#ifndef BOOKING_H
#define BOOKING_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <ctime>
#include <conio.h>
#include <cstdlib>

#include "TerminalControl.h"
using namespace std;

class Booking
{
    string bookingID;
    string bookedVehicleID;
    string bookedCustomerID;
    string rentDate;
    int rentDuration;
    double rentalCost;
    static int bookingsCount;
    static int bookingIDCounter;

public:
    /* Constructors */
    Booking();
    Booking(const string &vID, const string &cID, int days, double rentPerDay = 0.0);

    /* Utility Methods */
    void generateBookingID();
    void incrementOrDecrementIDCounter(bool isIncrement);
    void displayBookingDetails() const;

    /* Setters */
    void setBookingID(const string &id);
    void setBookedVehicleID(const string &vID);
    void setBookedCustomerID(const string &cID);
    void setRentDate(const string &date);
    void setRentDateToToday();
    void setRentDuration(int days);
    void setRentalCost(double cost);
    static void setIDCounter(int count);

    /* Getters */
    string getBookingID() const;
    string getBookedVehicleID() const;
    string getBookedCustomerID() const;
    string getRentDate() const;
    int getRentDuration() const;
    double getRentalCost() const;
    static int getBookingsCount();

    /* Destructor */
    ~Booking();
};

#endif