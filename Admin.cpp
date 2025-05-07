#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <conio.h>
#include <cstdlib>

#include "Admin.h"
using namespace std;

Admin::Admin()
{
    adminsCount++;
    adminIDCounter++;
    generateUserID();
}

Admin::Admin(const string &name, const string &email, const string &pass, const string &phoneNum, const string &address) : User(name, email, pass, phoneNum, address, "Admin")
{
    adminsCount++;
    adminIDCounter++;
    generateUserID();
}

int Admin::getAdminsCount() { return adminsCount; }

void Admin::generateUserID()
{
    stringstream ss;
    ss << "UA-" << setw(4) << setfill('0') << adminIDCounter;
    userID = ss.str();
}

void Admin::incrementOrDecrementIDCounter(bool isIncrement)
{
    (isIncrement) ? adminIDCounter++ : adminIDCounter--;
}

void Admin::editDetails()
{
    string newName, newEmail, newPass, newPhone, newAddress;
    system("cls");
    printLineWithDashes();
    printFormattedText("Editing Admin Details", COLOR_BLUE, true);
    printLineWithDashes();
    // cout << "Editing Admin " << userID << " details" << endl;

    printLineWithDashes();
    // cout << "Current username: " << userName << endl;
    printFormattedText("Current Username: " + userName, COLOR_WHITE, false);
    // cout << "Enter new username: ";
    printFormattedText("Enter new username:", COLOR_WHITE, false);
    printInputPrompt();
    getline(cin, newName);

    printLineWithSpaces();
    // cout << "Current email: " << userEmail << endl;
    printFormattedText("Current Email: " + userEmail, COLOR_WHITE, false);
    // cout << "Enter new email: ";
    printFormattedText("Enter new email: ", COLOR_WHITE, false);
    printInputPrompt();
    getline(cin, newEmail);
    while (!isEmailValid(newEmail))
    {
        // cout << "Invalid email entered! Please enter an email with the correct format:";
        printFormattedText("Invalid email entered! Please enter an email with the correct format: ", COLOR_WHITE, false);
        printInputPrompt();
        getline(cin, newEmail);
    }

    printLineWithSpaces();
    // cout << "Current password: " << userPassword << endl;
    printFormattedText("Current Password: " + userPassword, COLOR_WHITE, false);
    // cout << "Enter new password: ";
    printFormattedText("Enter new password: ", COLOR_WHITE, false);
    printInputPrompt();
    newPass = maskedPassword();
    cout << endl;

    printLineWithSpaces();
    // cout << "Current phone number: " << userPhoneNumber << endl;
    printFormattedText("Current Phone Number: " + userPhoneNumber, COLOR_WHITE, false);
    // cout << "Enter new phone number: ";
    printFormattedText("Enter new phone number: ", COLOR_WHITE, false);
    printInputPrompt();
    getline(cin, newPhone);

    printLineWithSpaces();
    // cout << "Current Address: " << userAddress << endl;
    printFormattedText("Current Address: " + userAddress, COLOR_WHITE, false);
    // cout << "\tEnter new address: ";
    printFormattedText("Enter new address: ", COLOR_WHITE, false);
    printInputPrompt();
    getline(cin, newAddress);

    // system("cls");
    printLineWithDashes();
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
    printInputPrompt();
    cin >> confirmation;
    cin.ignore();

    printLineWithSpaces();
    if (confirmation == 'y' || confirmation == 'Y')
    {
        updateUserProfile(newName, newEmail, newPass, newPhone, newAddress);
        // cout << "User profile updated successfully!" << endl;
        printLineWithDashes();
        printFormattedText("Admin profile details updated successfully!", COLOR_GREEN, true);    
    }
    else
    {
        // cout << "Discarding the changes made." << endl;
        printLineWithDashes();
        printFormattedText("Discarding the changes made.", COLOR_RED, true);
    }

    // cout << "Press any key to return to the main menu..." << endl;
    // printFormattedText("Press any key to return to the main menu...", COLOR_WHITE, false);
    printLineWithDashes();
    system("pause");
}

void Admin::addVehicleToInventory(vector <Vehicle*> &inventory)
{
    Vehicle *newVehicle;
    string options[3] = {"Car", "Bike", "Truck"};

    int choice = 0, maxChoices = 2;
    bool optionChosen = false;
    char pressedKey, confirmation;

    do
    {
        system("cls");
        printLineWithDashes();
        // cout << "Adding new vehicle to the inventory" << endl;
        printFormattedText("Adding New Vehicle To The Inventory", COLOR_BLUE, true);
        printLineWithDashes();

        printLineWithDashes();
        // cout << "Choose the vehicle type to add:" << endl;
        printFormattedText("Choose the vehicle type to add:", COLOR_WHITE, false);
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
        printLineWithDashes();

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
                newVehicle = new Car();
                optionChosen = true;
                break;

            case 1:
                newVehicle = new Bike();
                optionChosen = true;
                break;

            case 2:
                newVehicle = new Truck();
                optionChosen = true;
                break;
            }
        }
    } while (!optionChosen);

    newVehicle->addVehicle();

    printLineWithSpaces();
    // cout << endl << "Please confirm to add the new vehicle to the inventory. (Y/N): ";
    printFormattedText("Please confirm to add the new vehicle to the inventory. (Y/N): ", COLOR_WHITE, false);
    printInputPrompt();
    cin >> confirmation;
    cin.ignore();
    
    if (confirmation == 'y' || confirmation == 'Y')
    {
        inventory.push_back(newVehicle);
        // cout << "New vehicle (" << newVehicle->getVehicleID() << ") has been added to the inventory successfully!" << endl;
        printLineWithDashes();
        printFormattedText("New vehicle (" + newVehicle->getVehicleID() + ") has been added to the inventory successfully!", COLOR_GREEN, true);
    }
    else
    {
        newVehicle->incrementOrDecrementIDCounter(false);
        delete newVehicle;
        // cout << "Discarding the changes made." << endl;
        printLineWithDashes();
        printFormattedText("Discarding the changes made.", COLOR_RED, true);
    }

    // cout << "Press any key to return to the main menu..." << endl;
    // printFormattedText("Press any key to return to the main menu...", COLOR_WHITE, false);
    printLineWithDashes();
    system("pause");
}

void Admin::removeVehicleFromInventory(vector <Vehicle*> &inventory)
{
    string id;
    bool flag = false;
    char confirmation;
    int i;

    system("cls");
    printLineWithDashes();
    // cout << "Removing vehicle from the inventory" << endl;
    printFormattedText("Removing Vehicle From The Inventory" , COLOR_BLUE, true);
    printLineWithDashes();

    printLineWithDashes();
    for (i = 0; i < inventory.size(); i++)
    {
        // cout << "Vehicle " << (i + 1) << ": " << inventory[i]->getVehicleID() << " | Vehicle Type: " << inventory[i]->getVehicleType() << endl;
        printFormattedText("Vehicle " + to_string(i + 1) + ": " + inventory[i]->getVehicleID() + " | Vehicle Type: " + inventory[i]->getVehicleType() , COLOR_WHITE, false);
    }

    printLineWithSpaces();
    // cout << endl << "Enter the vehicle ID of the vehicle to be removed from the inventory: ";
    printFormattedText("Enter the vehicle ID of the vehicle to be removed from the inventory:", COLOR_WHITE, false);
    printInputPrompt();
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
        // cout << endl << "Invalid vehicle ID!" << endl << "Enter the valid vehicle ID of the vehicle to be removed from the inventory: ";
        printFormattedText("Invalid vehicle ID! Enter the valid vehicle ID of the vehicle to be removed from the inventory: ", COLOR_WHITE, false);
        printInputPrompt();
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

    printLineWithSpaces();
    // cout << endl << "Please confirm to remove vehicle (" << id << ") from the inventory. (Y/N): ";
    printFormattedText("Please confirm to remove vehicle (" + id + ") from the inventory. (Y/N): ", COLOR_WHITE, false);
    printInputPrompt();
    cin >> confirmation;
    cin.ignore();
    
    if (confirmation == 'y' || confirmation == 'Y')
    {
        delete inventory[i];
        inventory.erase(inventory.begin() + i);
        // cout << "Vehicle (" << id << ") has been removed from the inventory successfully!" << endl;
        printLineWithDashes();
        printFormattedText("Vehicle (" + id + ") has been removed from the inventory successfully!", COLOR_GREEN, true);
    }
    else
    {
        // cout << "Discarding the changes made." << endl;
        printLineWithDashes();
        printFormattedText("Discarding the changes made.", COLOR_RED, true);   
    }

    // cout << "Press any key to return to the main menu..." << endl;
    // printFormattedText("Press any key to return to the main menu...", COLOR_WHITE, false);
    printLineWithDashes();
    system("pause");
}

void Admin::viewAllVehicles(const vector <Vehicle*> &inventory)
{
    system("cls");
    printLineWithDashes();
    // cout << "Viewing All Vehicles From The Inventory" << endl;
    printFormattedText("Viewing All Vehicles From The Inventory" , COLOR_BLUE, true);
    printLineWithDashes();
    
    printLineWithDashes();
    for (int i = 0; i < inventory.size(); i++)
    {
        cout << *inventory[i];
    }

    printLineWithSpaces();
    // cout << endl << "Total number of vehicles in the inventory: " << Vehicle::getVehiclesCount() << endl;
    // cout << "Total number of cars in the inventory: " << Car::getCarsCount() << endl;
    // cout << "Total number of bikes in the inventory: " << Bike::getBikesCount() << endl;
    // cout << "Total number of trucks in the inventory: " << Truck::getTrucksCount() << endl;
    printFormattedText("Total number of vehicles in the inventory: " + to_string(Vehicle::getVehiclesCount()), COLOR_WHITE, false);
    printFormattedText("Total number of cars in the inventory: " + to_string(Car::getCarsCount()), COLOR_WHITE, false);
    printFormattedText("Total number of bikes in the inventory: " + to_string(Bike::getBikesCount()), COLOR_WHITE, false);
    printFormattedText("Total number of trucks in the inventory: " + to_string(Truck::getTrucksCount()), COLOR_WHITE, false);

    printLineWithSpaces();
    // cout << "Press any key to return to the main menu..." << endl;
    // printFormattedText("Press any key to return to the main menu...", COLOR_WHITE, false);
    printLineWithDashes();
    system("pause");
}

void Admin::userConsole(vector <Vehicle*> &inventory)
{ 
    string options[5] = {
        "Edit Admin Details and Information",
        "Add a New Vehicle to the Inventory",
        "Remove a Vehicle from the Inventory",
        "View All Vehicles",
        "Sign Out"
    };

    int choice = 0, maxChoices = 4;
    bool exitStatus = false;
    char pressedKey;

    do
    {
        system("cls");
        printLineWithDashes();
        // cout << "Admin Console" << endl;
        printFormattedText("Admin Console", COLOR_BLUE, true);
        printLineWithDashes();

        // cout << "Welcome, Admin " << userName << "!" << endl << endl;
        printFormattedText("Welcome, Admin " + userName + "!", COLOR_WHITE, true);
        printLineWithDashes();

        printLineWithDashes();
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
        else if (pressedKey == '\r' || pressedKey == ' ')
        {
            switch (choice)
            {
            case 0:
                editDetails();
                break;

            case 1:
                addVehicleToInventory(inventory);
                break;

            case 2:
                removeVehicleFromInventory(inventory);
                break;

            case 3:
                viewAllVehicles(inventory);
                break;

            case 4:
                exitStatus = true;
                break;
            }
        }
    } while (!exitStatus);
}

Admin::~Admin() { adminsCount--; }

int Admin::adminsCount = 0;
int Admin::adminIDCounter = 0;