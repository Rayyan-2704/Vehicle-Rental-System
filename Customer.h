#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <conio.h>
#include <cstdlib>

#include "Booking.h"
#include "User.h"
using namespace std;

class Customer : public User 
{
    vector <Booking> bookings;
    static int customersCount;
    static int customerIDCounter;

public:
    Customer();
    Customer(const string &name, const string &email, const string &pass, const string &phoneNum, const string &address);

    static int getCustomersCount();
    void generateUserID() override;
    void incrementOrDecrementIDCounter(bool isIncrement) override;
    void addBooking(Booking &b);
    const vector<Booking>& getBookingVector() const;
    void rentVehicle(vector <Vehicle*> &inventory);
    void returnVehicle(vector <Vehicle*> &inventory);
    void viewAllBookings() const ;
    void userConsole(vector <Vehicle*> &inventory) override;
    void editDetails() override;

    ~Customer();
};

#endif