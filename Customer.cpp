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
    cout << "Password: " << userPassword << endl;
    cout << "Phone Number: " << userPhoneNumber << endl;
    cout << "Address: " << userAddress << endl;
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
    // Implementation to be done once Vehicle and its derived classes
}

void Customer::userConsole(vector <Vehicle*> &inventory)
{ // Parameter needed
    string options[5] = {
        "Edit Customer Details and Information.",
        "Rent a Vehicle.",
        "Return a Vehicle.",
        "View All Bookings.",
        "< Navigate Back >"
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
    } while(!exitStatus);
}

Customer::~Customer() { customersCount--; }

int Customer::customersCount = 0;