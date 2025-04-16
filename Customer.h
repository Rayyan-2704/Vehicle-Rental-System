#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <conio.h>
#include <cstdlib>

#include "User.h"
using namespace std;

class Customer : public User 
{
    static int customersCount;
    // vector for bookings

public:
    Customer();
    Customer(const string &name, const string &email, const string &pass, const string &phoneNum, const string &address);

    static int getCustomersCount();
    void generateUserID() override;
    void rentVehicle(); // vector of bookings and vehicles
    void returnVehicle(); // vector of bookings
    void viewAllBookings(); // vector of bookings
    void userConsole() override; // vector of bookings & vehicles in parameter
    void editDetails() override;
};

#endif