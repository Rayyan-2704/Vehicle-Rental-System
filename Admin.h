#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cctype>
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
    void addVehicleToInventory(vector <Vehicle*> &inventory);
    void removeVehicleFromInventory(vector <Vehicle*> &inventory);
    void viewAllVehicles(const vector <Vehicle*> &inventory);
    void userConsole(vector <Vehicle*> &inventory) override;
    void editDetails() override;

    ~Admin();
};

#endif