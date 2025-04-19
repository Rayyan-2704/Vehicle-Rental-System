#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <conio.h>
#include <cstdlib>

#include "Car.h"
#include "Bike.h"
#include "Truck.h"
using namespace std;

class User
{
protected:
    string userID;
    string userName;
    string userEmail;
    string userPassword;
    string userPhoneNumber;
    string userAddress;
    static int usersCount;

public:
    /* Constructors */
    User();
    User(const string &name, const string &email, const string &pass, const string &phoneNum, const string &address);

    /* User Registration, Profile Management and Utility Methods */
    virtual void registerUser();
    virtual void updateUserProfile(const string &name, const string &email, const string &pass, const string &phoneNum, const string &address);
    bool verifyLogin(const string &e, const string &p);
    virtual void generateUserID();
    virtual void displayUserInfo() const;
    virtual void editDetails() = 0;
    virtual void userConsole(vector <Vehicle*> &inventory) = 0;

    /* Setters (Mutators) */
    void setUserName(const string &name);
    void setUserEmail(const string &email);
    void setUserPassword(const string &password);
    void setUserPhoneNumber(const string &phoneNumber);
    void setUserAddress(const string &address);

    /* Getters (Accessors) */
    string getUserID() const;
    string getUserName() const;
    string getUserEmail() const;
    string getUserPhoneNumber() const;
    string getUserAddress() const;
    static int getUsersCount();

    /* Destructor */
    virtual ~User();
};

/* Verification of Email: Global function */
bool isEmailValid(const string &email);

/* Ensuring that when password is entered onto the console, it is masked by asterisks '*' */
string maskedPassword();

/* Converting the string to lowercase and removing punctuation if any */
string cleanString(const string& input);

#endif