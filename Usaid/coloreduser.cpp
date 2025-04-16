#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <conio.h>

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

#include "User.h"
using namespace std;

User::User()
{
    usersCount++;
    generateID();
}

User::User(const string &name, const string &email, const string &pass, const string &phoneNum, const string &address) : userName(name), userEmail(email), userPassword(pass), userPhoneNumber(phoneNum), userAddress(address)
{
    usersCount++;
    generateID();
}

void User::registerUser()
{
    cout << COLOR_CYAN << COLOR_BOLD << "Enter Full Name: " << COLOR_RESET;
    getline(cin, userName);
    
    string email;
    do {
        cout << COLOR_CYAN << COLOR_BOLD << "Enter Email: " << COLOR_RESET;
        getline(cin, email);
        if (!isEmailValid(email)) {
            cout << COLOR_RED << "Invalid email format! Please try again." << COLOR_RESET << endl;
        }
    } while (!isEmailValid(email));
    userEmail = email;
    
    cout << COLOR_CYAN << COLOR_BOLD << "Enter Password: " << COLOR_RESET;
    userPassword = maskedPassword();
    
    cout << COLOR_CYAN << COLOR_BOLD << "\nEnter Phone Number: " << COLOR_RESET;
    getline(cin, userPhoneNumber);
    
    cout << COLOR_CYAN << COLOR_BOLD << "Enter Address: " << COLOR_RESET;
    getline(cin, userAddress);
    
    cout << COLOR_GREEN << "\nRegistration successful!" << COLOR_RESET << endl;
}

void User::updateUserProfile(const string &name, const string &email, const string &pass, const string &phoneNum, const string &address)
{
    this->userName = name;
    this->userEmail = email;
    this->userPassword = pass;
    this->userPhoneNumber = phoneNum;
    this->userAddress = address;
    cout << COLOR_GREEN << "Profile updated successfully!" << COLOR_RESET << endl;
}

bool User::verifyLogin(const string &e, const string &p)
{
    bool success = (userEmail == e && userPassword == p);
    if (!success) {
        cout << COLOR_RED << "Login failed! Invalid email or password." << COLOR_RESET << endl;
    }
    return success;
}

void User::generateID()
{
    stringstream ss;
    ss << "U-" << setw(4) << setfill('0') << usersCount;
    userID = ss.str();
}

void User::displayUserInfo() const
{
    cout << COLOR_YELLOW << COLOR_BOLD << "\n=== USER INFORMATION ===" << COLOR_RESET << endl;
    cout << COLOR_BLUE << "User ID: " << COLOR_RESET << userID << endl;
    cout << COLOR_BLUE << "Name: " << COLOR_RESET << userName << endl;
    cout << COLOR_BLUE << "Email: " << COLOR_RESET << userEmail << endl;
    cout << COLOR_BLUE << "Phone Number: " << COLOR_RESET << userPhoneNumber << endl;
    cout << COLOR_BLUE << "Address: " << COLOR_RESET << userAddress << endl;
    cout << COLOR_YELLOW << "=========================" << COLOR_RESET << endl;
}

/* Setters */
void User::setUserName(const string &name) { userName = name; }
void User::setUserEmail(const string &email) { userEmail = email; }
void User::setUserPassword(const string &password) { userPassword = password; }
void User::setUserPhoneNumber(const string &phoneNumber) { userPhoneNumber = phoneNumber; }
void User::setUserAddress(const string &address) { userAddress = address; }

/* Getters */
string User::getUserName() const { return userName; }
string User::getUserEmail() const { return userEmail; }
string User::getUserPhoneNumber() const { return userPhoneNumber; }
string User::getUserAddress() const { return userAddress; }
int User::getUsersCount() { return usersCount; }

User::~User() {}

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

    // Ensure proper positioning of '@' and '.'
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
            cout << COLOR_MAGENTA << '*' << COLOR_RESET;
            NewPassword += ch;
        }
    }
    return NewPassword;
}
