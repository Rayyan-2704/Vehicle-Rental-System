#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <conio.h>
#include <cstdlib>

#include "User.h"
using namespace std;

class Admin : public User
{
    static int adminsCount;

public:
    Admin();
    Admin(const string &name, const string &email, const string &pass, const string &phoneNum, const string &address);

    static int getAdminsCount();
    void generateUserID() override;
    void addVehicleToInventory();      // vector of vehicles in parameter
    void removeVehicleFromInventory(); // vector of vehicles in parameter
    void viewAllVehicles();            // vector of vehicles in parameter
    void userConsole() override;       // vector of vehicles in parameter
    void editDetails() override;

    ~Admin();
};

#endif