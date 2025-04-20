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

public:
    /* Constructors */
    Booking();
    Booking(const string &vID, const string &cID, int days, double rentPerDay);

    /* Utility Methods */
    void generateBookingID();
    void displayBookingDetails() const;

    /* Setters */
    void setBookedVehicleID(const string &vID);
    void setBookedCustomerID(const string &cID);
    void setRentDateToToday();
    void setRentDuration(int days);
    void setRentalCost(double cost);

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