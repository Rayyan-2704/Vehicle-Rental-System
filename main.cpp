#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <cstdlib>

#include "Admin.h"
#include "Customer.h"
#include "Car.h"
#include "Bike.h"
#include "Truck.h"
#include "Booking.h"
#include "TerminalControl.h"
#include "FileHandler.h"
using namespace std;

void registerOrLogin(vector <Admin*> &admins, vector <Customer*> &customers, vector <Vehicle*> &inventory, const string &userType);
void loginUser(vector <Admin*> &admins, vector <Customer*> &customers, vector <Vehicle*> &inventory, const string &userType);
void registerUser(vector <Admin*> &admins, vector <Customer*> &customers, const string &userType);

int main()
{
    // vector <Admin*> admins = {
    //     new Admin("Rayyan Aamir", "k240687@nu.edu.pk", "pass123", "1234567", "Block-J North Nazimabad"),
    //     new Admin("Usaid Khan", "k240732@nu.edu.pk", "qwer789", "0987653", "Naya Nazimabad"),
    //     new Admin("Hammad Haider", "k240634@nu.edu.pk", "wasd456", "3287459", "5-Star North Nazimabad")
    // };

    // vector <Customer*> customers = {
    //     new Customer("Jules Kounde", "juleskounde@gmail.com", "barca687", "5840339", "Clifton"),
    //     new Customer("Ammar Baig", "ammarbaig@gmail.com", "ketw484", "9698348", "DHA Phase 7"),
    //     new Customer("Sahal Arif", "sahalarif@gmail.com", "vmds458", "3948851", "Shahrah-e-Faisal")
    // };

    // vector <Vehicle*> vehicles = {
    //     new Car("Toyota", "Corolla", "ABC-123", 50.0, true, "Petrol"),
    //     new Car("Honda", "Civic", "DEF-456", 55.0, true, "Petrol"),
    //     new Car("Tesla", "Model 3", "GHI-789", 75.0, true, "Electric"),
    //     new Car("Ford", "Mustang", "BCD-777", 85.0, false, "Petrol"),  // assuming it is already booked

    //     new Bike("Yamaha", "R15", "JKL-111", 20.0, true, 150),
    //     new Bike("Honda", "CBR500R", "MNO-222", 25.0, true, 500),
    //     new Bike("Suzuki", "GSX-R600", "PQR-333", 30.0, false, 600),  // assuming it is already booked
    //     new Bike("Kawasaki", "Ninja 300", "EFG-888", 28.0, false, 300),  // assuming it is already booked

    //     new Truck("Volvo", "FH16", "STU-444", 120.0, true, 20000.0),
    //     new Truck("Scania", "R500", "VWX-555", 110.0, true, 18000.0),
    //     new Truck("MAN", "TGX", "YZA-666", 130.0, true, 22000.0),
    //     new Truck("Mercedes", "Actros", "HIJ-999", 125.0, false, 25000.0)  // assuming it is already booked
    // };

    // vector <Booking*> totalBookings = {
    //     new Booking(vehicles[3]->getVehicleID(), customers[0]->getUserID(), 10, vehicles[3]->getRatePerDay()),
    //     new Booking(vehicles[6]->getVehicleID(), customers[0]->getUserID(), 5, vehicles[6]->getRatePerDay()),
    //     new Booking(vehicles[7]->getVehicleID(), customers[1]->getUserID(), 7, vehicles[7]->getRatePerDay()),
    //     new Booking(vehicles[11]->getVehicleID(), customers[2]->getUserID(), 25, vehicles[11]->getRatePerDay())
    // };

    // customers[0]->addBooking(*totalBookings[0]);
    // customers[0]->addBooking(*totalBookings[1]);
    // customers[1]->addBooking(*totalBookings[2]);
    // customers[2]->addBooking(*totalBookings[3]);

    vector <Admin*> admins;
    vector <Customer*> customers;
    vector <Vehicle*> vehicles;

    FileHandler filing;
    filing.loadAdminData(admins, "admins.csv");
    filing.loadCustomerData(customers, "customers.csv");
    filing.loadVehiclesData(vehicles, "vehicles.csv");
    filing.loadBookingsData(customers, "bookings.csv");

    string options[3] = {"Admin", "Customer", "Exit Program"};

    int choice = 0, maxChoices = 2;
    bool exitStatus = false;
    char pressedKey;
    do
    {
        system("cls");
        printProjectTitle();

        printLineWithDashes();
        printFormattedText("User Access Portal", COLOR_BLUE, true);
        printLineWithDashes();

        printLineWithDashes();

        for (int i = 0; i < 3; i++)
        {
            printLineWithSpaces();
        }

        for (int i = 0; i < 3; i++)
        {
            if(i == choice)
            {
                printFormattedText(string("==> ") + to_string(i + 1) + ". " + options[i], COLOR_YELLOW, true);
            }
            else
            {
                printFormattedText(to_string(i + 1) + ". " + options[i], COLOR_WHITE, true);
            }
        }

        for (int i = 0; i < 3; i++)
        {
            printLineWithSpaces();
        }

        printFormattedText("Navigate with W/S or Arrow Keys", COLOR_WHITE, false);
        printLineWithDashes();

        printLineWithDashes();
        printFormattedText("Developed By:", COLOR_MAGENTA, true);
        printFormattedText("Rayyan Aamir (24K-0687)", COLOR_WHITE, true);
        printFormattedText("Usaid Khan (24K-0832)", COLOR_WHITE, true);
        printFormattedText("Hammad Haider (24K-0634)", COLOR_WHITE, true);
        printLineWithDashes();

        maskCursor();
        pressedKey = _getch();
        if ((pressedKey == 'w' || pressedKey == 'W' || pressedKey == 72) && (choice > 0))
        {
            choice--;
        }
        else if ((pressedKey == 's' || pressedKey == 'S'|| pressedKey == 80) && (choice < maxChoices))
        {
            choice++;
        }
        else if (pressedKey == '\r')
        {
            switch (choice)
            {
            case 0:
                registerOrLogin(admins, customers, vehicles, "Admin");
                break;

            case 1:
                registerOrLogin(admins, customers, vehicles, "Customer");
                break;

            case 2:
                exitStatus = true;
                break;
            }
        }     
    } while (!exitStatus);
    
    std :: cout << COLOR_GREEN << "Exiting the program..." << COLOR_RESET;

    filing.writeAdminData(admins, "admins.csv");
    filing.writeCustomerData(customers, "customers.csv");
    filing.writeVehiclesData(vehicles, "vehicles.csv");
    filing.writeBookingsData(customers, "bookings.csv");

    for (Vehicle* v : vehicles)
        delete v;

    for (Customer* c : customers)
        delete c;

    for (Admin* a : admins)
        delete a;

    // for (Booking* b : totalBookings)
    //     delete b;
    
    return 0;
}

void registerOrLogin(vector <Admin*> &admins, vector <Customer*> &customers, vector <Vehicle*> &inventory, const string &userType)
{
    string options[3] = {"Create New Account", "Sign In", "Navigate Back"};

    int choice = 0, maxChoices = 2;
    bool exitStatus = false;
    char pressedKey;

    do
    {
        system("cls");
        printProjectTitle();
        printLineWithDashes();
        printFormattedText("Select And Proceed", COLOR_BLUE, true);
        printLineWithDashes();

        printLineWithDashes();

        for (int i = 0; i < 3; i++)
        {
            printLineWithSpaces();
        }

        for (int i = 0; i < 3; i++)
        {
            if(i == choice)
            {
                printFormattedText(string("==> ") + to_string(i + 1) + ". " + options[i], COLOR_YELLOW, true);
            }
            else
            {
                printFormattedText(to_string(i + 1) + ". " + options[i], COLOR_WHITE, true);
            }
        }

        for (int i = 0; i < 3; i++)
        {
            printLineWithSpaces();
        }
        printLineWithDashes();

        printLineWithDashes();
        printFormattedText("Developed By:", COLOR_MAGENTA, true);
        printFormattedText("Rayyan Aamir (24K-0687)", COLOR_WHITE, true);
        printFormattedText("Usaid Khan (24K-0832)", COLOR_WHITE, true);
        printFormattedText("Hammad Haider (24K-0634)", COLOR_WHITE, true);
        printLineWithDashes();

        pressedKey = _getch();
        if ((pressedKey == 'w' || pressedKey == 'W' || pressedKey == 72) && (choice > 0))
        {
            choice--;
        }
        else if ((pressedKey == 's' || pressedKey == 'S'|| pressedKey == 80) && (choice < maxChoices))
        {
            choice++;
        }
        else if (pressedKey == '\r')
        {
            switch (choice)
            {
            case 0:
                registerUser(admins, customers, userType);
                break;

            case 1:
                loginUser(admins, customers, inventory, userType);
                break;

            case 2:
                exitStatus = true;
                break;
            }
        }     
    } while (!exitStatus);
}

void loginUser(vector <Admin*> &admins, vector <Customer*> &customers, vector <Vehicle*> &inventory, const string &userType)
{
    bool flag = false;
    string enteredEmail, enteredPass;
    vector <User*> users;

    if (userType == "Admin")
    {
        for (int i = 0; i < admins.size(); i++)
        {
            users.push_back(admins[i]);
        }
    }
    else
    {
        for (int i = 0; i < customers.size(); i++)
        {
            users.push_back(customers[i]);
        }
    }

    system("cls");
    printLineWithDashes();
    printFormattedText((string)((userType == "Admin") ? "Admin" : "Customer") + " Login", COLOR_BLUE, true);
    printLineWithDashes();

    do
    {
        printLineWithDashes();
        printFormattedText("Enter Email Address:", COLOR_WHITE, false);
        printInputPrompt();
        getline(cin, enteredEmail);
        
        printLineWithSpaces();
        printFormattedText("Enter Password:", COLOR_WHITE, false);
        printInputPrompt();
        enteredPass = maskedPassword();
        cout << endl;

        for (int i = 0; i < users.size(); i++)
        {
            if (users[i]->verifyLogin(enteredEmail, enteredPass))
            {
                flag = true;
                printLineWithDashes();
                printFormattedText("Login Successful!", COLOR_GREEN, true);
                printLineWithDashes();
                system("pause");
                users[i]->userConsole(inventory);
                return;
            }
        }

        if (!flag)
        {
            printLineWithDashes();
            printFormattedText("Wrong Email or Password! Try again", COLOR_RED, true);
            printLineWithDashes();
            system("pause");
        }
    } while (!flag);
}

void registerUser(vector <Admin*> &admins, vector <Customer*> &customers, const string &userType)
{
    User *newUser;
    vector <User*> users;

    if (userType == "Admin")
    {
        for (int i = 0; i < admins.size(); i++)
        {
            users.push_back(admins[i]);
        }
    }
    else
    {
        for (int i = 0; i < customers.size(); i++)
        {
            users.push_back(customers[i]);
        }
    }
    
    system("cls");
    printLineWithDashes();
    printFormattedText((string)((userType == "Admin") ? "Admin" : "Customer") + " Registration Form", COLOR_BLUE, true);
    printLineWithDashes();

    printLineWithDashes();
    if (userType == "Admin")
    {
        newUser = new Admin();
    }
    else
    {
        newUser = new Customer();
    }

    newUser->registerUser(users);
    if (userType == "Admin")
    {
        admins.push_back(static_cast <Admin*> (newUser));
    }
    else
    {
        customers.push_back(static_cast <Customer*> (newUser));
    }

    printLineWithDashes();
    printFormattedText("Registration Successful!", COLOR_GREEN, true);
    printLineWithDashes();
    system("pause");
}