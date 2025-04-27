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
    customerIDCounter++;
    generateUserID();
}

Customer::Customer(const string &name, const string &email, const string &pass, const string &phoneNum, const string &address) : User(name, email, pass, phoneNum, address, "Customer")
{
    customersCount++;
    customerIDCounter++;
    generateUserID();
}

int Customer::getCustomersCount() { return customersCount; }

void Customer::generateUserID()
{
    stringstream ss;
    ss << "UC-" << setw(4) << setfill('0') << customerIDCounter;
    userID = ss.str();
}

void Customer::incrementOrDecrementIDCounter(bool isIncrement)
{
    (isIncrement) ? customerIDCounter++ : customerIDCounter--;
}

void Customer::addBooking(Booking &b)
{
    bookings.push_back(b);
}

const vector<Booking>& Customer::getBookingVector() const {
    return bookings;
}

void Customer::editDetails()
{
    string newName, newEmail, newPass, newPhone, newAddress;
    system("cls");
    printLineWithDashes(COLOR_CYAN);
    printFormattedText("Editing Customer Details", COLOR_BLUE, true);
    printLineWithDashes(COLOR_CYAN);
    // cout << "Editing Admin " << userID << " details" << endl;

    printLineWithDashes(COLOR_CYAN);
    // cout << "Current username: " << userName << endl;
    printFormattedText("Current Username: " + userName, COLOR_WHITE, false);
    // cout << "Enter new username: ";
    printFormattedText("Enter new username:", COLOR_WHITE, false);
    cout << COLOR_CYAN "| >> " << COLOR_RESET;
    getline(cin, newName);

    printLineWithSpaces(COLOR_CYAN);
    // cout << "Current email: " << userEmail << endl;
    printFormattedText("Current Email: " + userEmail, COLOR_WHITE, false);
    // cout << "Enter new email: ";
    printFormattedText("Enter new email: ", COLOR_WHITE, false);
    cout << COLOR_CYAN << "| >> " COLOR_RESET;
    getline(cin, newEmail);
    while (!isEmailValid(newEmail))
    {
        // cout << "Invalid email entered! Please enter an email with the correct format:";
        printFormattedText("Invalid email entered! Please enter an email with the correct format: ", COLOR_WHITE, false);
        cout << COLOR_CYAN << "| >> " << COLOR_RESET;
        getline(cin, newEmail);
    }

    printLineWithSpaces(COLOR_CYAN);
    // cout << "Current password: " << userPassword << endl;
    printFormattedText("Current Password: " + userPassword, COLOR_WHITE, false);
    // cout << "Enter new password: ";
    printFormattedText("Enter new password: ", COLOR_WHITE, false);
    cout << COLOR_CYAN << "| >> " << COLOR_RESET;
    newPass = maskedPassword();
    cout << endl;

    printLineWithSpaces(COLOR_CYAN);
    // cout << "Current phone number: " << userPhoneNumber << endl;
    printFormattedText("Current Phone Number: " + userPhoneNumber, COLOR_WHITE, false);
    // cout << "Enter new phone number: ";
    printFormattedText("Enter new phone number: ", COLOR_WHITE, false);
    cout << COLOR_CYAN << "| >> " << COLOR_RESET;
    getline(cin, newPhone);

    printLineWithSpaces(COLOR_CYAN);
    // cout << "Current Address: " << userAddress << endl;
    printFormattedText("Current Address: " + userAddress, COLOR_WHITE, false);
    // cout << "\tEnter new address: ";
    printFormattedText("Enter new address: ", COLOR_WHITE, false);
    cout << COLOR_CYAN << "| >> " << COLOR_RESET;
    getline(cin, newAddress);

    // system("cls");
    printLineWithDashes(COLOR_CYAN);
    char confirmation;
    // cout << "Username: " << newName << endl;
    // cout << "Email: " << newEmail << endl;
    // cout << "Password: " << newPass << endl;
    // cout << "Phone Number: " << newPhone << endl;
    // cout << "Address: " << newAddress << endl;
    printFormattedText("Username: " + newName, COLOR_WHITE, false);
    printFormattedText("Email: " + newEmail, COLOR_WHITE, false);
    printFormattedText("Password: " + string(newPass.length(), '*'), COLOR_WHITE, false);
    printFormattedText("Phone Number: " + newPhone, COLOR_WHITE, false);
    printFormattedText("Address: " + newAddress, COLOR_WHITE, false);
    // cout << "Please confirm your updated details. Would you like to save your changes? (Y/N): ";
    printFormattedText("Please confirm your updated details. Would you like to save your changes? (Y/N): ", COLOR_WHITE, false);
    cout << COLOR_CYAN << "| >> " << COLOR_RESET;
    cin >> confirmation;
    cin.ignore();

    printLineWithSpaces(COLOR_CYAN);
    if (confirmation == 'y' || confirmation == 'Y')
    {
        updateUserProfile(newName, newEmail, newPass, newPhone, newAddress);
        // cout << "User profile updated successfully!" << endl;
        printLineWithDashes(COLOR_CYAN);
        printFormattedText("Customer profile details updated successfully!", COLOR_GREEN, true);    
    }
    else
    {
        // cout << "Discarding the changes made." << endl;
        printLineWithDashes(COLOR_CYAN);
        printFormattedText("Discarding the changes made.", COLOR_RED, true);
    }

    // cout << "Press any key to return to the main menu..." << endl;
    // printFormattedText("Press any key to return to the main menu...", COLOR_WHITE, false);
    printLineWithDashes(COLOR_CYAN);
    system("pause");
}

void Customer::rentVehicle(vector <Vehicle*> &inventory)
{
    Booking *newBooking;
    string options[3] = {"Car", "Bike", "Truck"};
    int i, numDays;
    int choice = 0, maxChoices = 2;
    bool optionChosen = false, flag = false;
    char pressedKey, confirmation;
    string vehicleTypeChosen, id;

    do
    {
        system("cls");
        printLineWithDashes(COLOR_CYAN);
        // cout << "Renting A Vehicle" << endl;
        printFormattedText("Renting A Vehicle", COLOR_BLUE, true);
        printLineWithDashes(COLOR_CYAN);

        printLineWithDashes(COLOR_CYAN);
        // cout << "Choose the vehicle type to rent:" << endl;
        printFormattedText("Choose the vehicle type to rent:", COLOR_WHITE, false);
        for (int i = 0; i < 3; i++)
        {
            if(i == choice)
            {
                // cout << "==> " << (i + 1) << ". " << options[i] << endl;
                printFormattedText(string("==> ") + to_string(i + 1) + ". " + options[i], COLOR_YELLOW, false);
            }
            else
            {
                printFormattedText(to_string(i + 1) + ". " + options[i], COLOR_WHITE, false);
            }
        }
        printLineWithDashes(COLOR_CYAN);

        pressedKey = _getch();
        if ((pressedKey == 'w' || pressedKey == 'W'|| pressedKey == 72) && (choice > 0))
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
            case 0:
                vehicleTypeChosen = "Car";
                optionChosen = true;
                break;

            case 1:
                vehicleTypeChosen = "Bike";
                optionChosen = true;
                break;

            case 2:
                vehicleTypeChosen = "Truck";
                optionChosen = true;
                break;
            }
        }
    } while (!optionChosen);

    printLineWithSpaces(COLOR_CYAN);
    // cout << "Displaying all available " << vehicleTypeChosen << "s to rent from" << endl;
    printFormattedText("Displaying all available " + vehicleTypeChosen + "s to rent from", COLOR_WHITE, false);
    for (i = 0; i < inventory.size(); i++)
    {
        if(inventory[i]->getVehicleType() == vehicleTypeChosen && inventory[i]->getAvailability()){
            cout << *inventory[i];
        }
    }

    printLineWithSpaces(COLOR_CYAN);
    // cout << endl << "Enter the vehicle ID of the " << vehicleTypeChosen << " you want to rent: ";
    printFormattedText("Enter the vehicle ID of the " + vehicleTypeChosen + " you want to rent:", COLOR_WHITE, false);
    cout << COLOR_CYAN "| >> " << COLOR_RESET;
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
        // cout << endl << "Invalid vehicle ID!" << endl << "Enter the valid vehicle ID of the " << vehicleTypeChosen << " you want to rent: ";
        printFormattedText("Invalid vehicle ID! Enter the valid vehicle ID of the " + vehicleTypeChosen + " you want to rent: ", COLOR_WHITE, false);
        cout << COLOR_CYAN "| >> " << COLOR_RESET;
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
        // cout << "Enter the number of days you would like to rent the vehicle for: ";
        printFormattedText("Enter the number of days you would like to rent the vehicle for:", COLOR_WHITE, false);
        cout << COLOR_CYAN << "| >> " << COLOR_RESET;
        cin >> numDays;
        if (numDays <= 0) 
        {
            // cout << "Invalid number of days! Please enter a positive value." << endl;
            printFormattedText("Invalid number of days! Please enter a positive value.", COLOR_WHITE, false);
        }
    } while (numDays <= 0);

    newBooking = new Booking(inventory[i]->getVehicleID(), userID, numDays, inventory[i]->getRatePerDay());

    // cout << endl << "Please confirm to rent vehicle (" << id << "). (Y/N): ";
    printFormattedText("Please confirm to rent vehicle (" + id + "). (Y/N):", COLOR_WHITE, false);
    cout << COLOR_CYAN << "| >> " COLOR_RESET;
    cin >> confirmation;
    cin.ignore();

    if (confirmation == 'y' || confirmation == 'Y')
    {
        bookings.push_back(*newBooking);
        inventory[i]->setAvailability(false);
        // cout << "Vehicle (" << id << ") has been rented successfully!" << endl;
        printLineWithDashes(COLOR_CYAN);
        printFormattedText("Vehicle (" + id + ") has been rented successfully!", COLOR_GREEN, true);
    }
    else
    {
        newBooking->incrementOrDecrementIDCounter(false);
        delete newBooking;
        // cout << "Discarding the changes made." << endl;
        printLineWithDashes(COLOR_CYAN);
        printFormattedText("Discarding the changes made.", COLOR_RED, true);
    }

    // cout << "Press any key to return to the main menu..." << endl;
    // printFormattedText("Press any key to return to the main menu...", COLOR_WHITE, false);
    printLineWithDashes(COLOR_CYAN);
    system("pause");
}

void Customer::returnVehicle(vector <Vehicle*> &inventory)
{
    int i;
    string id;
    char confirmation;
    double payment;
    bool flag = false;
    
    system("cls");
    printLineWithDashes(COLOR_CYAN);
    // cout << "Returning Rented Vehicle" << endl;
    printFormattedText("Returning Rented Vehicle", COLOR_BLUE, true);
    printLineWithDashes(COLOR_CYAN);

    printLineWithDashes(COLOR_CYAN);
    // cout << "Enter the vehicle ID of the rented vehicle you want to return: " << endl;
    printFormattedText("Enter the vehicle ID of your rented vehicle to be returned:", COLOR_WHITE, false);
    cout << COLOR_CYAN << "| >> " << COLOR_RESET;
    getline(cin, id);

    for (i = 0; i < bookings.size(); i++)
    {
        if (lowercaseString(id) == lowercaseString(bookings[i].getBookedVehicleID())) 
        {
            flag = true;
            break;
        }
    }

    while (!flag)
    {
        // cout << endl << "Invalid vehicle ID!" << endl << "Enter the valid vehicle ID of the rented vehicle to return: ";
        printFormattedText("Invalid vehicle ID! Enter the valid vehicle ID of your rented vehicle to be returned:", COLOR_WHITE, false);
        cout << COLOR_CYAN << "| >> " << COLOR_RESET;
        getline(cin, id);

        for (i = 0; i < bookings.size(); i++)
        {
            if (lowercaseString(id) == lowercaseString(bookings[i].getBookedVehicleID())) 
            {
                flag = true;
                break;
            }
        }
    }

    printLineWithSpaces(COLOR_CYAN);
    // cout << endl << "Please confirm to return vehicle (" << id << "). (Y/N): ";
    printFormattedText("Please confirm to return vehicle (" + id + "). (Y/N):", COLOR_WHITE, false);
    cout << COLOR_CYAN << "| >> " COLOR_RESET;
    cin >> confirmation;
    cin.ignore();

    if (confirmation == 'y' || confirmation == 'Y')
    {
        for (int j = 0; j < bookings.size(); j++)
        {
            if(lowercaseString(bookings[j].getBookedVehicleID()) == lowercaseString(id) && bookings[j].getBookedCustomerID() == userID)
            {
                for (auto &veh : inventory)
                {
                    if (lowercaseString(veh->getVehicleID()) == lowercaseString(id))
                    {
                        veh->setAvailability(true);
                        break;
                    }
                }
                payment = bookings[j].getRentalCost();
                bookings.erase(bookings.begin() + j);
                break;
            }
        }
        // cout << "Vehicle (" << id << ") has been returned successfully!" << endl;
        // cout << "Your total rental cost amounts to $" << payment << endl;
        printLineWithDashes(COLOR_CYAN);
        printFormattedText("Vehicle (" + id + ") has been returned successfully!", COLOR_GREEN, true);
        printFormattedText("Your total rental cost amounts to $" + to_string(payment), COLOR_WHITE, true);
    }
    else
    {
        // cout << "Discarding the changes made." << endl;
        printLineWithDashes(COLOR_CYAN);
        printFormattedText("Discarding the changes made.", COLOR_RED, true);
    }

    // cout << "Press any key to return to the main menu..." << endl;
    // printFormattedText("Press any key to return to the main menu...", COLOR_WHITE, false);
    printLineWithDashes(COLOR_CYAN);
    system("pause");
}

void Customer::viewAllBookings() const
{
    system("cls");
    printLineWithDashes(COLOR_CYAN);
    // cout << "Viewing All Bookings Of Customer" << endl;
    printFormattedText("Viewing All Bookings Of Customer", COLOR_BLUE, true);
    printLineWithDashes(COLOR_CYAN);

    printLineWithDashes(COLOR_CYAN);
    // cout << "Current Bookings of " << userName << " (" <<  userID << "):" << endl;
    printFormattedText("Current Bookings of " + userName + " (" +  userID + "):", COLOR_MAGENTA, true);
    printLineWithSpaces(COLOR_CYAN);
    for (int i = 0; i < bookings.size(); i++)
    {
        bookings[i].displayBookingDetails();
    }

    printLineWithSpaces(COLOR_CYAN);
    // cout << "Press any key to return to the main menu..." << endl;
    // printFormattedText("Press any key to return to the main menu...", COLOR_WHITE, false);
    printLineWithDashes(COLOR_CYAN);
    system("pause");
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

    int choice = 0, maxChoices = 4;
    bool exitStatus = false;
    char pressedKey;

    do
    {
        system("cls");
        printLineWithDashes(COLOR_CYAN);
        // cout << "Customer Console" << endl;
        printFormattedText("Customer Console", COLOR_BLUE, true);
        printLineWithDashes(COLOR_CYAN);

        // cout << "Welcome, Customer " << userName << "!" << endl << endl;
        printFormattedText("Welcome, Customer " + userName + "!", COLOR_WHITE, true);
        printLineWithDashes(COLOR_CYAN);

        printLineWithDashes(COLOR_CYAN);
        // cout << "Menu Actions:" << endl;
        printFormattedText("Menu Actions:", COLOR_MAGENTA, true);
        for (int i = 0; i < 5; i++)
        {
            if(i == choice)
            {
                // cout << "==> " << (i + 1) << ". " << options[i] << endl;
                printFormattedText(string("==> ") + to_string(i + 1) + ". " + options[i], COLOR_YELLOW, true);
            }
            else
            {
                printFormattedText(to_string(i + 1) + ". " + options[i], COLOR_WHITE, true);
            }
        }
        printLineWithDashes(COLOR_CYAN);

        pressedKey = _getch();
        if ((pressedKey == 'w' || pressedKey == 'W' || pressedKey == 72) && (choice > 0))
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
            case 0:
                editDetails();
                break;

            case 1:
                rentVehicle(inventory);
                break;

            case 2:
                returnVehicle(inventory);
                break;

            case 3:
                viewAllBookings();
                break;

            case 4:
                exitStatus = true;
                break;
            }
        }
    } while(!exitStatus);
}

Customer::~Customer() { customersCount--; }

int Customer::customersCount = 0;
int Customer::customerIDCounter = 0;

void Customer::serialize(std::ostream& os) const {
    os << id << '\n'
       << name << '\n'
       << contactNumber << '\n'
       << licenseNumber << '\n';
       
    // Save rental history
    os << rentalHistory.size() << ' ';
    for (int rentalId : rentalHistory) {
        os << rentalId << ' ';
    }
    os << '\n';
}

void Customer::deserialize(std::istream& is) {
    std::getline(is >> std::ws, name);
    std::getline(is >> std::ws, contactNumber);
    std::getline(is >> std::ws, licenseNumber);
    
    // Load rental history
    size_t historySize;
    is >> historySize;
    rentalHistory.resize(historySize);
    for (size_t i = 0; i < historySize; ++i) {
        is >> rentalHistory[i];
    }
}
