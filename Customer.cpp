#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <conio.h>
#include <cstdlib>

#include "Customer.h"
using namespace std;

Customer::Customer()
{
    customersCount++;
    generateUserID();
}

Customer::Customer(const string &name, const string &email, const string &pass, const string &phoneNum, const string &address) : User(name, email, pass, phoneNum, address)
{
    customersCount++;
    generateUserID();
}

int Customer::getCustomersCount() { return customersCount; }

void Customer::generateUserID()
{
    stringstream ss;
    ss << "UC-" << setw(4) << setfill('0') << customersCount;
    userID = ss.str();
}

void Customer::editDetails()
{
    system("cls");
    string newName, newEmail, newPass, newPhone, newAddress;
    cout << "Editing Customer " << userID << " details" << endl;

    cout << "\tCurrent username: " << userName << endl;
    cout << "\tEnter new username: ";
    getline(cin, newName);

    cout << "\n\tCurrent email: " << userEmail << endl;
    cout << "\tEnter new email: ";
    getline(cin, newEmail);
    while (!isEmailValid(newEmail))
    {
        cout << "\tInvalid email entered! Please enter an email with the correct format:";
        getline(cin, newEmail);
    }

    cout << "\n\tCurrent password: " << userPassword << endl;
    cout << "\tEnter new password: ";
    newPass = maskedPassword();

    cout << "\n\tCurrent phone number: " << userPhoneNumber << endl;
    cout << "\tEnter new phone number: ";
    getline(cin, newPhone);

    cout << "\n\tCurrent Address: " << userAddress << endl;
    cout << "\tEnter new address: ";
    getline(cin, newAddress);

    system("cls");

    char confirmation;
    cout << "Username: " << newName << endl;
    cout << "Email: " << newEmail << endl;
    cout << "Password: " << newPass << endl;
    cout << "Phone Number: " << newPhone << endl;
    cout << "Address: " << newAddress << endl;
    cout << "Please confirm your updated details. Would you like to save your changes? (Y/N): ";
    cin >> confirmation;

    if (confirmation == 'y' || confirmation == 'Y')
    {
        updateUserProfile(newName, newEmail, newPass, newPhone, newAddress);
        cout << "User profile updated successfully!" << endl;
    }
    else
    {
        cout << "Discarding the changes made." << endl;
    }

    cout << "Press any key to return to the main menu..." << endl;
    _getch();
}

void Customer::rentVehicle(vector <Vehicle*> &inventory)
{
    Booking *newBooking;
    string options[3] = {"Car", "Bike", "Truck"};
    int i, numDays;
    int choice = 1, maxChoices = 3;
    bool optionChosen = false, flag = false;
    char pressedKey, confirmation;
    string vehicleTypeChosen, id;

    do
    {
        system("cls");
        cout << "Renting A Vehicle" << endl;

        cout << "Choose the vehicle type to rent:" << endl;
        for (int i = 0; i < 3; i++)
        {
            // further addition required here
            cout << ">> " << (i + 1) << ". " << options[i] << endl;
        }

        pressedKey = _getch();
        if ((pressedKey == 'w' || pressedKey == 'W'|| pressedKey == 72) && (choice > 1))
        {
            choice--;
        }
        else if ((pressedKey == 's' || pressedKey == 'S' || pressedKey == 80) && (choice < maxChoices))
        {
            choice++;
        }
        else if (pressedKey == '\r' || pressedKey == ' ')
        {
            switch (choice)
            {
            case 1:
                vehicleTypeChosen = "Car";
                optionChosen = true;
                break;

            case 2:
                vehicleTypeChosen = "Bike";
                optionChosen = true;
                break;

            case 3:
                vehicleTypeChosen = "Truck";
                optionChosen = true;
                break;
            }
        }
    } while (!optionChosen);

    cout << "Displaying all available " << vehicleTypeChosen << "s to rent from" << endl;
    for (i = 0; i < inventory.size(); i++)
    {
        if(inventory[i]->getVehicleType() == vehicleTypeChosen && inventory[i]->getAvailability()){
            cout << *inventory[i];
        }
    }

    cout << endl << "Enter the vehicle ID of the " << vehicleTypeChosen << " you want to rent: ";
    getline(cin, id);

    for (i = 0; i < inventory.size(); i++)
    {
        if(inventory[i]->getVehicleType() == vehicleTypeChosen && inventory[i]->getAvailability() && lowercaseString(id) == lowercaseString(inventory[i]->getVehicleID())){
            flag = true;
            break;
        }
    }

    while (!flag)
    {
        cout << endl << "Invalid vehicle ID!" << endl << "Enter the valid vehicle ID of the " << vehicleTypeChosen << " you want to rent: ";
        getline(cin, id);

        for (i = 0; i < inventory.size(); i++)
        {
            if (inventory[i]->getVehicleType() == vehicleTypeChosen && inventory[i]->getAvailability() && lowercaseString(id) == lowercaseString(inventory[i]->getVehicleID())) 
            {
                flag = true;
                break;
            }
        }
    }

    do {
        cout << "Enter the number of days you would like to rent the vehicle for: ";
        cin >> numDays;
        if (numDays <= 0) 
        {
            cout << "Invalid number of days! Please enter a positive value." << endl;
        }
    } while (numDays <= 0);

    newBooking = new Booking(inventory[i]->getVehicleID(), userID, numDays, inventory[i]->getRatePerDay());

    cout << endl << "Please confirm to rent vehicle (" << id << "). (Y/N): ";
    cin >> confirmation;
    cin.ignore();

    if (confirmation == 'y' || confirmation == 'Y')
    {
        bookings.push_back(*newBooking);
        inventory[i]->setAvailability(false);
        cout << "Vehicle (" << id << ") has been rented successfully!" << endl;
    }
    else
    {
        delete newBooking;
        cout << "Discarding the changes made." << endl;
    }

    cout << "Press any key to return to the main menu..." << endl;
    _getch();
}

void Customer::returnVehicle(vector <Vehicle*> &inventory)
{
    int i;
    string id;
    char confirmation;
    double payment;
    bool flag = false;
    
    system("cls");
    cout << "Returning Rented Vehicle" << endl;
    cout << "Enter the vehicle ID of the rented vehicle you want to return: " << endl;
    getline(cin, id);

    for (i = 0; i < inventory.size(); i++)
    {
        if (lowercaseString(id) == lowercaseString(inventory[i]->getVehicleID())) 
        {
            flag = true;
            break;
        }
    }

    while (!flag)
    {
        cout << endl << "Invalid vehicle ID!" << endl << "Enter the valid vehicle ID of the rented vehicle you want to return: ";
        getline(cin, id);

        for (i = 0; i < inventory.size(); i++)
        {
            if (lowercaseString(id) == lowercaseString(inventory[i]->getVehicleID())) 
            {
                flag = true;
                break;
            }
        }
    }

    cout << endl << "Please confirm to return vehicle (" << id << "). (Y/N): ";
    cin >> confirmation;
    cin.ignore();

    if (confirmation == 'y' || confirmation == 'Y')
    {
        for (int j = 0; j < bookings.size(); j++)
        {
            if(lowercaseString(bookings[j].getBookedVehicleID()) == lowercaseString(id) && bookings[j].getBookedCustomerID() == userID)
            {
                inventory[i]->setAvailability(true);
                payment = bookings[j].getRentalCost();
                bookings.erase(bookings.begin() + j);
                break;
            }
        }
        cout << "Vehicle (" << id << ") has been returned successfully!" << endl;
        cout << "Your total rental cost amounts to $" << payment << endl;
    }
    else
    {
        cout << "Discarding the changes made." << endl;
    }

    cout << "Press any key to return to the main menu..." << endl;
    _getch();
}

void Customer::viewAllBookings() const
{
    system("cls");
    cout << "Viewing All Bookings Of Customer" << endl;

    cout << "Current Bookings of " << userName << " (" <<  userID << "):" << endl;
    for (int i = 0; i < bookings.size(); i++)
    {
        bookings[i].displayBookingDetails();
    }

    cout << "Press any key to return to the main menu..." << endl;
    _getch();
}

void Customer::userConsole(vector <Vehicle*> &inventory)
{
    string options[5] = {
        "Edit Customer Details and Information",
        "Rent a Vehicle",
        "Return a Vehicle",
        "View All Bookings",
        "Sign Out"
    };

    int choice = 1, maxChoices = 5;
    bool exitStatus = false;
    char pressedKey;

    do
    {
        system("cls");
        cout << "Customer Console" << endl;
        cout << "Welcome, Customer " << userName << "!" << endl << endl;

        cout << "Menu Actions:" << endl;
        for (int i = 0; i < 5; i++)
        {
            // further addition required here
            cout << ">> " << (i + 1) << ". " << options[i] << endl;
        }

        pressedKey = _getch();
        if ((pressedKey == 'w' || pressedKey == 'W' || pressedKey == 72) && (choice > 1))
        {
            choice--;
        }
        else if ((pressedKey == 's' || pressedKey == 'S' || pressedKey == 80) && (choice < maxChoices))
        {
            choice++;
        }
        else if (pressedKey == '\r' || pressedKey == ' ') 
        {
            switch (choice)
            {
            case 1:
                editDetails();
                break;

            case 2:
                rentVehicle(inventory);
                break;

            case 3:
                returnVehicle(inventory);
                break;

            case 4:
                viewAllBookings();
                break;

            case 5:
                exitStatus = true;
                break;
            }
        }
    } while(!exitStatus);
}

Customer::~Customer() { customersCount--; }

int Customer::customersCount = 0;