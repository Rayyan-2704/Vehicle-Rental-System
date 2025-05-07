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
    generateUserID();
}

User::User(const string &name, const string &email, const string &pass, const string &phoneNum, const string &address, const string &type) : userName(name), userEmail(email), userPassword(pass), userPhoneNumber(phoneNum), userAddress(address), userType(type)
{
    usersCount++;
    generateUserID();
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

void User::generateUserID()
{
    stringstream ss;
    ss << "U-" << setw(4) << setfill('0') << usersCount; // building the string stream
    userID = ss.str(); // extracting full string from the stream and assigning it to userID
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
string User::getUserPhoneNumber() const { return userPhoneNumber; }
string User::getUserAddress() const { return userAddress; }
string User::getUserType() const { return userType; }
int User::getUsersCount() { return usersCount; }

User::~User() { usersCount--; }

int User::usersCount = 0;

bool isEmailValid(const string &email)
{
    // Ensure that the email does not contain any spaces
    if (email.find(' ') != string::npos)
    {
        return false;
    }

    size_t atPos = email.find('@');
    size_t dotPos = email.find('.', atPos);

    // Ensure that both '@' and '.' are present
    if (atPos == string::npos || dotPos == string::npos)
    {
        return false;
    }

    // Ensure that '@' is not at the start, there is atleast one character between '@' and the following '.' and atleast 2 characters are present after the last occuring '.'
    if (atPos == 0 || dotPos - atPos <= 1 || dotPos + 2 >= email.length())
    {
        return false;
    }

    // Ensure that '@' does not appear more than once
    if (email.find('@', atPos + 1) != string::npos)
    {
        return false;
    }

    return true;
}

string maskedPassword()
{
    string NewPassword = "";
    char ch;

    while ((ch = _getch()) != '\r')
    {
        if (ch == '\b')
        {
            if (!NewPassword.empty())
            {
                cout << "\b \b";
                NewPassword.pop_back();
            }
        }
        else
        {
            cout << '*';
            NewPassword += ch;
        }
    }
    return NewPassword;
}

string lowercaseString(const string& input) {
    string result;
    for (char ch : input) 
    {
        if (isalpha(ch)) 
        {
            result += tolower(ch);
        } 
        else 
        {
            result += ch;
        }
    }
    return result;
}