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
#define BG_CYAN       "\033[46m"
#define BG_GREEN      "\033[42m"

#include "Customer.h"
using namespace std;

Customer::Customer()
{
    customersCount++;
    generateID();
}

Customer::Customer(const string &name, const string &email, const string &pass, const string &phoneNum, const string &address) : User(name, email, pass, phoneNum, address)
{
    customersCount++;
    generateID();
}

void Customer::generateID()
{
    stringstream ss;
    ss << COLOR_CYAN << "UC-" << setw(4) << setfill('0') << customersCount << COLOR_RESET;
    userID = ss.str();
}

void Customer::editDetails()
{
    system("cls");
    string newName, newEmail, newPass, newPhone, newAddress;
    
    cout << COLOR_MAGENTA << COLOR_BOLD << "╔════════════════════════════╗" << endl;
    cout << "║ Editing Customer " << userID << " Details ║" << endl;
    cout << "╚════════════════════════════╝" << COLOR_RESET << endl << endl;

    cout << COLOR_BLUE << "\tCurrent username: " << COLOR_RESET << userName << endl;
    cout << COLOR_GREEN << "\tEnter new username: " << COLOR_RESET;
    getline(cin, newName);

    cout << COLOR_BLUE << "\n\tCurrent email: " << COLOR_RESET << userEmail << endl;
    cout << COLOR_GREEN << "\tEnter new email: " << COLOR_RESET;
    getline(cin, newEmail);
    while (!isEmailValid(newEmail))
    {
        cout << COLOR_RED << "\t✖ Invalid email format!" << COLOR_RESET << endl;
        cout << COLOR_GREEN << "\tPlease enter valid email (e.g., user@domain.com): " << COLOR_RESET;
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
    cout << COLOR_YELLOW << COLOR_BOLD << "╔══════════════════════════╗" << endl;
    cout << "║   Confirm New Details   ║" << endl;
    cout << "╚══════════════════════════╝" << COLOR_RESET << endl;
    cout << COLOR_BLUE << "┌──────────────────────────┐" << COLOR_RESET << endl;
    cout << COLOR_BLUE << "│ Username: " << COLOR_RESET << newName << endl;
    cout << COLOR_BLUE << "│ Email: " << COLOR_RESET << newEmail << endl;
    cout << COLOR_BLUE << "│ Password: " << COLOR_RESET << string(newPass.length(), '*') << endl;
    cout << COLOR_BLUE << "│ Phone: " << COLOR_RESET << newPhone << endl;
    cout << COLOR_BLUE << "│ Address: " << COLOR_RESET << newAddress << endl;
    cout << COLOR_BLUE << "└──────────────────────────┘" << COLOR_RESET << endl << endl;

    cout << COLOR_CYAN << "Save these changes? (" << COLOR_GREEN << "Y" << COLOR_RESET << "/" << COLOR_RED << "N" << COLOR_CYAN << "): " << COLOR_RESET;
    cin >> choice;

    if (toupper(choice) == 'Y')
    {
        updateUserProfile(newName, newEmail, newPass, newPhone, newAddress);
        cout << COLOR_GREEN << "\n✔ Profile updated successfully!" << COLOR_RESET << endl;
    }
    else
    {
        cout << COLOR_YELLOW << "\n✖ Changes discarded." << COLOR_RESET << endl;
    }

    cout << COLOR_MAGENTA << "\nPress any key to continue..." << COLOR_RESET;
    _getch();
}

void Customer::rentVehicle()
{
    // Implementation to be done once Vehicle and its derived classes are made
}

void Customer::returnVehicle()
{
    // Implementation to be done once Vehicle and its derived classes are made
}

void Customer::viewAllBookings()
{
    // Implementation to be done once Vehicle and its derived classes are made
}

void Customer::userConsole()
{
    string options[5] = {
        "Edit My Details",
        "Rent a Vehicle",
        "Return a Vehicle",
        "View My Bookings",
        "Exit to Main Menu"
    };

    int choice = 1, maxChoices = 5;
    bool exitStatus = false;
    char pressedKey;

    do
    {
        system("cls");
        cout << COLOR_CYAN << COLOR_BOLD << "╔══════════════════════════╗" << endl;
        cout << "║     CUSTOMER PORTAL     ║" << endl;
        cout << "╚══════════════════════════╝" << COLOR_RESET << endl;
        cout << COLOR_YELLOW << "Welcome back, " << userName << "!" << COLOR_RESET << endl << endl;

        cout << COLOR_BLUE << "Please select an option:" << COLOR_RESET << endl;
        for (int i = 0; i < 5; i++)
        {
            if (i + 1 == choice) {
                cout << BG_CYAN << COLOR_WHITE << COLOR_BOLD << " ➔ " << (i + 1) << ". " << options[i] << COLOR_RESET << endl;
            } else {
                cout << "    " << (i + 1) << ". " << options[i] << endl;
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
                // rent vehicle function call
                break;

            case 3:
                // return vehicle function call
                break;

            case 4:
                // view all bookings function call
                break;

            case 5:
                exitStatus = true;
                break;
            }
        }
    } while (!exitStatus);
}

int Customer::customersCount = 0;
