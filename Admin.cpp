#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
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

    char choice;
    cout << "Username: " << newName << endl;
    cout << "Email: " << newEmail << endl;
    cout << "Password: " << userPassword << endl;
    cout << "Phone Number: " << userPhoneNumber << endl;
    cout << "Address: " << userAddress << endl;
    cout << "Please confirm your updated details. Would you like to save your changes? (Y/N): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y')
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

void Admin::addVehicleToInventory()
{
    // Implementation to be done once Vehicle and its derived classes are made
    system("cls");
}

void Admin::removeVehicleFromInventory()
{
    // Implementation to be done once Vehicle and its derived classes are made
}

void Admin::viewAllVehicles()
{
    // Implementation to be done once Vehicle and its derived classes are made
}

void Admin::userConsole()
{ // Parameter needed
    string options[5] = {
        "Edit Admin Details and Information.",
        "Add a New Vehicle to the Inventory.",
        "Remove a Vehicle from the Inventory.",
        "View All Vehicles.",
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
        if ((pressedKey == 'w' || pressedKey == 'W') && (choice > 1))
        {
            choice--;
        }
        else if ((pressedKey == 's' || pressedKey == 'S') && (choice < maxChoices))
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
                // add vehicle function call
                break;

            case 3:
                // remove vehicle function call
                break;

            case 4:
                // view all vehicles function call
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