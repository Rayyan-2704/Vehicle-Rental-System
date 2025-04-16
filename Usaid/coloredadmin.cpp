#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <conio.h>
#include <iomanip>
#include <cstdlib>

// ANSI color codes
#define COLOR_RESET   "\033[0m"
#define COLOR_RED     "\033[31m"
#define COLOR_GREEN   "\033[32m"
#define COLOR_YELLOW  "\033[33m"
#define COLOR_BLUE    "\033[34m"
#define COLOR_MAGENTA "\033[35m"
#define COLOR_CYAN    "\033[36m"
#define COLOR_WHITE   "\033[37m"
#define COLOR_BOLD    "\033[1m"
#define BG_BLUE       "\033[44m"
#define BG_GREEN      "\033[42m"

#include "Admin.h"
using namespace std;

Admin::Admin()
{
    adminsCount++;
    generateID();
}

Admin::Admin(const string &name, const string &email, const string &pass, const string &phoneNum, const string &address) : User(name, email, pass, phoneNum, address)
{
    adminsCount++;
    generateID();
}

void Admin::generateID()
{
    stringstream ss;
    ss << "UA-" << setw(4) << setfill('0') << adminsCount;
    userID = COLOR_YELLOW << ss.str() << COLOR_RESET;
}

void Admin::editDetails()
{
    system("cls");
    string newName, newEmail, newPass, newPhone, newAddress;
    
    cout << COLOR_CYAN << COLOR_BOLD << "Editing Admin " << userID << " details" << COLOR_RESET << endl << endl;

    cout << COLOR_BLUE << "\tCurrent username: " << COLOR_RESET << userName << endl;
    cout << COLOR_GREEN << "\tEnter new username: " << COLOR_RESET;
    getline(cin, newName);

    cout << COLOR_BLUE << "\n\tCurrent email: " << COLOR_RESET << userEmail << endl;
    cout << COLOR_GREEN << "\tEnter new email: " << COLOR_RESET;
    getline(cin, newEmail);
    while (!isEmailValid(newEmail))
    {
        cout << COLOR_RED << "\tInvalid email entered!" << COLOR_RESET << endl;
        cout << COLOR_GREEN << "\tPlease enter an email with the correct format: " << COLOR_RESET;
        getline(cin, newEmail);
    }

    cout << COLOR_BLUE << "\n\tCurrent password: " << COLOR_RESET << string(userPassword.length(), '*') << endl;
    cout << COLOR_GREEN << "\tEnter new password: " << COLOR_RESET;
    newPass = maskedPassword();

    cout << COLOR_BLUE << "\n\tCurrent phone number: " << COLOR_RESET << userPhoneNumber << endl;
    cout << COLOR_GREEN << "\tEnter new phone number: " << COLOR_RESET;
    getline(cin, newPhone);

    cout << COLOR_BLUE << "\n\tCurrent Address: " << COLOR_RESET << userAddress << endl;
    cout << COLOR_GREEN << "\tEnter new address: " << COLOR_RESET;
    getline(cin, newAddress);

    system("cls");

    char choice;
    cout << COLOR_YELLOW << COLOR_BOLD << "=== Confirm Updated Details ===" << COLOR_RESET << endl;
    cout << COLOR_BLUE << "Username: " << COLOR_RESET << newName << endl;
    cout << COLOR_BLUE << "Email: " << COLOR_RESET << newEmail << endl;
    cout << COLOR_BLUE << "Password: " << COLOR_RESET << string(newPass.length(), '*') << endl;
    cout << COLOR_BLUE << "Phone Number: " << COLOR_RESET << newPhone << endl;
    cout << COLOR_BLUE << "Address: " << COLOR_RESET << newAddress << endl;
    
    cout << COLOR_CYAN << "\nWould you like to save your changes? (Y/N): " << COLOR_RESET;
    cin >> choice;

    if (choice == 'y' || choice == 'Y')
    {
        updateUserProfile(newName, newEmail, newPass, newPhone, newAddress);
        cout << COLOR_GREEN << "\nUser profile updated successfully!" << COLOR_RESET << endl;
    }
    else
    {
        cout << COLOR_YELLOW << "\nDiscarding the changes made." << COLOR_RESET << endl;
    }

    cout << COLOR_MAGENTA << "\nPress any key to return to the main menu..." << COLOR_RESET;
    _getch();
}

void Admin::addVehicleToInventory()
{
    // Implementation to be done once Vehicle and its derived classes are made
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
{
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
        cout << COLOR_YELLOW << COLOR_BOLD << "=== Admin Console ===" << COLOR_RESET << endl;
        cout << COLOR_CYAN << "Welcome, Admin " << userName << "!" << COLOR_RESET << endl << endl;

        cout << COLOR_BLUE << "Menu Actions:" << COLOR_RESET << endl;
        for (int i = 0; i < 5; i++)
        {
            if (i + 1 == choice) {
                cout << BG_BLUE << COLOR_WHITE << COLOR_BOLD << ">> " << (i + 1) << ". " << options[i] << COLOR_RESET << endl;
            } else {
                cout << "   " << (i + 1) << ". " << options[i] << endl;
            }
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

int Admin::adminsCount = 0;
