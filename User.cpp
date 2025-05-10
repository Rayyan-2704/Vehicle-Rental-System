#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cctype>
#include <conio.h>
#include <cstdlib>

#include "User.h"
using namespace std;

User::User() : userName(""), userEmail(""), userPassword(""), userPhoneNumber(""), userAddress("")
{
    usersCount++;
}

User::User(const string &name, const string &email, const string &pass, const string &phoneNum, const string &address, const string &type) : userName(name), userEmail(email), userPassword(pass), userPhoneNumber(phoneNum), userAddress(address), userType(type)
{
    usersCount++;
}

void User::registerUser()
{
    // cout << "Enter Full Name: ";
    // getline(cin, userName);
    // cout << "Enter Email: ";
    // getline(cin, userEmail);
    // cout << "Enter Password: ";
    // userPassword = maskedPassword();
    // cout << "Enter Phone Number: ";
    // getline(cin, userPhoneNumber);
    // cout << "Enter Address: ";
    // getline(cin, userAddress);

    printFormattedText("Enter the full name of the user:", COLOR_WHITE, false);
    printInputPrompt();
    getline(cin, userName);

    printLineWithSpaces();
    do
    {
        printFormattedText("Enter the email of the user:", COLOR_WHITE, false);
        printInputPrompt();
        getline(cin, userEmail);
        if(!isEmailValid(userEmail))
        {
            printFormattedText("Invalid email! Try again.", COLOR_WHITE, false);
        }
    } while (!isEmailValid(userEmail));
    
    string repeatedPassword;
    printLineWithSpaces();
    do
    {
        printFormattedText("Enter the password of the user:", COLOR_WHITE, false);
        printInputPrompt();
        userPassword = maskedPassword();
        cout << endl;

        printFormattedText("Enter password again for confirmation:", COLOR_WHITE, false);
        printInputPrompt();
        repeatedPassword = maskedPassword();
        cout << endl;

        if(repeatedPassword != userPassword)
        {
            printFormattedText("Passwords do not match. Try again!", COLOR_WHITE, false);
        }
    } while (repeatedPassword != userPassword);

    printLineWithSpaces();
    printFormattedText("Enter the phone number of the user:", COLOR_WHITE, false);
    printInputPrompt();
    getline(cin, userPhoneNumber);

    printLineWithSpaces();
    printFormattedText("Enter the address of the user:", COLOR_WHITE, false);
    printInputPrompt();
    getline(cin, userAddress);
}

void User::updateUserProfile(const string &name, const string &email, const string &pass, const string &phoneNum, const string &address)
{
    this->userName = name;
    this->userEmail = email;
    this->userPassword = pass;
    this->userPhoneNumber = phoneNum;
    this->userAddress = address;
}

bool User::verifyLogin(const string &e, const string &p)
{
    return (userEmail == e && userPassword == p);
}

void User::displayUserInfo() const
{
    cout << "User ID: " << userID << endl;
    cout << "Name: " << userName << endl;
    cout << "Email: " << userEmail << endl;
    cout << "Phone Number: " << userPhoneNumber << endl;
    cout << "Address: " << userAddress << endl;
}

/* Setters */
void User::setUserID(const string &id) { userID = id; }
void User::setUserName(const string &name) { userName = name; }
void User::setUserEmail(const string &email) { userEmail = email; }
void User::setUserPassword(const string &password) { userPassword = password; }
void User::setUserPhoneNumber(const string &phoneNumber) { userPhoneNumber = phoneNumber; }
void User::setUserAddress(const string &address) { userAddress = address; }
void User::setUserType(const string &type) { userType = type; }

/* Getters */
string User::getUserID() const { return userID; }
string User::getUserName() const { return userName; }
string User::getUserEmail() const { return userEmail; }
string User::getUserPassword() const { return userPassword; }
string User::getUserPhoneNumber() const { return userPhoneNumber; }
string User::getUserAddress() const { return userAddress; }
string User::getUserType() const { return userType; }
int User::getUsersCount() { return usersCount; }

User::~User() { usersCount--; }

int User::usersCount = 0;