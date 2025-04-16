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

// Terminal width for centering 
#define TERMINAL_WIDTH 80

#include "User.h"
using namespace std;

// Helper function to center text
string centerText(const string& text, char fillchar = ' ') {
    int padding = (TERMINAL_WIDTH - text.length()) / 2;
    if (padding <= 0) return text;
    return string(padding, fillchar) + text + string(padding, fillchar);
}

User::User()
{
    usersCount++;
    generateID();
}

User::User(const string &name, const string &email, const string &pass, 
          const string &phoneNum, const string &address) 
    : userName(name), userEmail(email), userPassword(pass), 
      userPhoneNumber(phoneNum), userAddress(address)
{
    usersCount++;
    generateID();
}

void User::registerUser()
{
    cout << COLOR_CYAN << COLOR_BOLD << centerText("Enter Full Name: ") << COLOR_RESET;
    getline(cin, userName);
    
    string email;
    do {
        cout << COLOR_CYAN << COLOR_BOLD << centerText("Enter Email: ") << COLOR_RESET;
        getline(cin, email);
        if (!isEmailValid(email)) {
            cout << COLOR_RED << centerText("Invalid email format! Please try again.") << COLOR_RESET << endl;
        }
    } while (!isEmailValid(email));
    userEmail = email;
    
    cout << COLOR_CYAN << COLOR_BOLD << centerText("Enter Password: ") << COLOR_RESET;
    userPassword = maskedPassword();
    
    cout << COLOR_CYAN << COLOR_BOLD << centerText("\nEnter Phone Number: ") << COLOR_RESET;
    getline(cin, userPhoneNumber);
    
    cout << COLOR_CYAN << COLOR_BOLD << centerText("Enter Address: ") << COLOR_RESET;
    getline(cin, userAddress);
    
    cout << COLOR_GREEN << centerText("\nRegistration successful!") << COLOR_RESET << endl;
}

void User::updateUserProfile(const string &name, const string &email, 
                           const string &pass, const string &phoneNum, 
                           const string &address)
{
    this->userName = name;
    this->userEmail = email;
    this->userPassword = pass;
    this->userPhoneNumber = phoneNum;
    this->userAddress = address;
    cout << COLOR_GREEN << centerText("Profile updated successfully!") << COLOR_RESET << endl;
}

bool User::verifyLogin(const string &e, const string &p)
{
    bool success = (userEmail == e && userPassword == p);
    if (!success) {
        cout << COLOR_RED << centerText("Login failed! Invalid email or password.") << COLOR_RESET << endl;
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
    cout << COLOR_YELLOW << COLOR_BOLD << centerText("\n=== USER INFORMATION ===") << COLOR_RESET << endl;
    cout << COLOR_BLUE << centerText("User ID: " + userID) << COLOR_RESET << endl;
    cout << COLOR_BLUE << centerText("Name: " + userName) << COLOR_RESET << endl;
    cout << COLOR_BLUE << centerText("Email: " + userEmail) << COLOR_RESET << endl;
    cout << COLOR_BLUE << centerText("Phone Number: " + userPhoneNumber) << COLOR_RESET << endl;
    cout << COLOR_BLUE << centerText("Address: " + userAddress) << COLOR_RESET << endl;
    cout << COLOR_YELLOW << centerText("=========================") << COLOR_RESET << endl;
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
    if (email.find(' ') != string::npos) return false;

    size_t atPos = email.find('@');
    size_t dotPos = email.find('.', atPos);

    if (atPos == string::npos || dotPos == string::npos) return false;
    if (atPos == 0 || dotPos - atPos <= 1 || dotPos + 2 >= email.length()) return false;
    if (email.find('@', atPos + 1) != string::npos) return false;

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
