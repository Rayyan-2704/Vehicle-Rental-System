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
    generateUserID();
}

Admin::Admin(const string &name, const string &email, const string &pass, const string &phoneNum, const string &address) : User(name, email, pass, phoneNum, address)
{
    adminsCount++;
    generateUserID();
}

int Admin::getAdminsCount() { return adminsCount; }

void Admin::generateUserID()
{
    stringstream ss;
    ss << "UA-" << setw(4) << setfill('0') << adminsCount;
    userID = ss.str();
}

void Admin::editDetails()
{
    system("cls");
    string newName, newEmail, newPass, newPhone, newAddress;
    cout << "Editing Admin " << userID << " details" << endl;

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
    cout << "Password: " << userPassword << endl;
    cout << "Phone Number: " << userPhoneNumber << endl;
    cout << "Address: " << userAddress << endl;
    cout << "Please confirm your updated details. Would you like to save your changes? (Y/N): ";
    cin >> confirmation;
    cin.ignore();

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

void Admin::addVehicleToInventory(vector <Vehicle*> &inventory)
{
    Vehicle *newVehicle;
    string options[3] = {"Car", "Bike", "Truck"};

    int choice = 1, maxChoices = 3;
    bool optionChosen = false;
    char pressedKey, confirmation;

    do
    {
        system("cls");
        cout << "Adding new vehicle to the inventory" << endl;

        cout << "Choose the vehicle type:" << endl;
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
                newVehicle = new Car();
                optionChosen = true;
                break;

            case 2:
                newVehicle = new Bike();
                optionChosen = true;
                break;

            case 3:
                newVehicle = new Truck();
                optionChosen = true;
                break;
            }
        }
    } while (!optionChosen);

    newVehicle->addVehicle();

    cout << endl << "Please confirm to add the new vehicle to the inventory. (Y/N): ";
    cin >> confirmation;
    cin.ignore();
    
    if (confirmation == 'y' || confirmation == 'Y')
    {
        inventory.push_back(newVehicle);
        cout << "New vehicle (" << newVehicle->getVehicleID() << ") has been added to the inventory successfully!" << endl;
    }
    else
    {
        delete newVehicle;
        cout << "Discarding the changes made." << endl;
    }

    cout << "Press any key to return to the main menu..." << endl;
    _getch();
}

void Admin::removeVehicleFromInventory(vector <Vehicle*> &inventory)
{
    string id;
    bool flag = false;
    char confirmation;
    int i;

    system("cls");
    cout << "Removing vehicle from the inventory" << endl;

    for (i = 0; i < inventory.size(); i++)
    {
        cout << "Vehicle " << (i + 1) << ": " << inventory[i]->getVehicleID() << " | Vehicle Type: " << inventory[i]->getVehicleType() << endl;
    }

    cout << endl << "Enter the vehicle ID of the vehicle to be removed from the inventory: ";
    getline(cin, id);

    for (i = 0; i < inventory.size(); i++)
    {
        if (cleanString(id) == inventory[i]->getVehicleID()) 
        {
            flag = true;
            break;
        }
    }

    while (!flag)
    {
        cout << endl << "Invalid vehicle ID!" << endl << "Enter the valid vehicle ID of the vehicle to be removed from the inventory: ";
        getline(cin, id);

        for (i = 0; i < inventory.size(); i++)
        {
            if (cleanString(id) == inventory[i]->getVehicleID()) 
            {
                flag = true;
                break;
            }
        }
    }

    cout << endl << "Please confirm to remove vehicle (" << id << ") from the inventory. (Y/N): ";
    cin >> confirmation;
    cin.ignore();
    
    if (confirmation == 'y' || confirmation == 'Y')
    {
        delete inventory[i];
        inventory.erase(inventory.begin() + i);
        cout << "Vehicle (" << id << ") has been removed from the inventory successfully!" << endl;
    }
    else
    {
        cout << "Discarding the changes made." << endl;
    }

    cout << "Press any key to return to the main menu..." << endl;
    _getch();
}

void Admin::viewAllVehicles(vector <Vehicle*> &inventory)
{
    cout << "Viewing All Vehicles From The Inventory" << endl;
    for (int i = 0; i < inventory.size(); i++)
    {
        cout << *inventory[i];
    }

    cout << endl << "Total number of vehicles in the inventory: " << Vehicle::getVehiclesCount() << endl;
    cout << "Total number of cars in the inventory: " << Car::getCarsCount() << endl;
    cout << "Total number of bikes in the inventory: " << Bike::getBikesCount() << endl;
    cout << "Total number of trucks in the inventory: " << Truck::getTrucksCount() << endl;

    cout << "Press any key to return to the main menu..." << endl;
    _getch();
}

void Admin::userConsole(vector <Vehicle*> &inventory)
{ 
    string options[5] = {
        "Edit Admin Details and Information",
        "Add a New Vehicle to the Inventory",
        "Remove a Vehicle from the Inventory",
        "View All Vehicles",
        "< Navigate Back >"
    };

    int choice = 1, maxChoices = 5;
    bool exitStatus = false;
    char pressedKey;

    do
    {
        system("cls");
        cout << "Admin Console" << endl;
        cout << "Welcome, Admin " << userName << "!" << endl << endl;

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
        else if ((pressedKey == 's' || pressedKey == 'S'|| pressedKey == 80) && (choice < maxChoices))
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
                addVehicleToInventory(inventory);
                break;

            case 3:
                removeVehicleFromInventory(inventory);
                break;

            case 4:
                viewAllVehicles(inventory);
                break;

            case 5:
                exitStatus = true;
                break;
            }
        }
    } while (!exitStatus);
}

Admin::~Admin() { adminsCount--; }

int Admin::adminsCount = 0;