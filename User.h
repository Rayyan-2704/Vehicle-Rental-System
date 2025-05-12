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
#include "TerminalControl.h"
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
    string userType;
    static int usersCount;

public:
    /* Constructors */
    User();
    User(const string &name, const string &email, const string &pass, const string &phoneNum, const string &address, const string &type);

    /* User Registration, Profile Management and Utility Methods */
    virtual void registerUser(vector <User*> &users);
    virtual void updateUserProfile(const string &name, const string &email, const string &pass, const string &phoneNum, const string &address);
    bool verifyLogin(const string &e, const string &p);
    virtual void generateUserID() = 0;
    virtual void displayUserInfo() const;
    virtual void incrementOrDecrementIDCounter(bool isIncrement) = 0;
    virtual void editDetails() = 0;
    virtual void userConsole(vector <Vehicle*> &inventory) = 0;

    /* Setters (Mutators) */
    void setUserID(const string &id);
    void setUserName(const string &name);
    void setUserEmail(const string &email);
    void setUserPassword(const string &password);
    void setUserPhoneNumber(const string &phoneNumber);
    void setUserAddress(const string &address);
    void setUserType(const string &type);

    /* Getters (Accessors) */
    string getUserID() const;
    string getUserName() const;
    string getUserEmail() const;
    string getUserPassword() const;
    string getUserPhoneNumber() const;
    string getUserAddress() const;
    string getUserType() const;
    static int getUsersCount();

    /* Destructor */
    virtual ~User();
};

#endif