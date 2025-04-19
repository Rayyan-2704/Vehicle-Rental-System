#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <ctime>
#include <conio.h>
#include <cstdlib>

#include "Booking.h"
using namespace std;

Booking::Booking() : bookedVehicleID(""), bookedCustomerID(""), rentDuration(0), rentalCost(0.0)
{
    bookingsCount++;
    generateBookingID();
    setRentDateToToday();
}

Booking::Booking(const string &vID, const string &cID, const string &dateOfRent, int days, double rentPerDay) : bookedVehicleID(vID), bookedCustomerID(cID), rentDate(dateOfRent), rentDuration(days)
{
    bookingsCount++;
    generateBookingID();
    rentalCost = rentDuration * rentPerDay;
}

void Booking::generateBookingID()
{
    stringstream ss;
    ss << "B-" << setw(4) << setfill('0') << bookingsCount;
    bookingID = ss.str();
}

void Booking::displayBookingDetails() const
{
    cout << "Booking ID: " << bookingID << " | Booked Vehicle ID: " << bookedVehicleID << " | Booked Customer ID: " << bookedCustomerID << endl;
    cout << "Rent Date: " << rentDate << " | Rent Duration: " << rentDuration <<  " days" << endl;
}

void Booking::setBookedVehicleID(const string &vID) { bookedVehicleID = vID; }
void Booking::setBookedCustomerID(const string &cID) { bookedCustomerID = cID; }

void Booking::setRentDateToToday()
{
    time_t now = time(0);
    tm* currentDate = localtime(&now);

    stringstream ss;
    ss << setfill('0') << setw(2) << currentDate->tm_mday << "-" << setfill('0') << setw(2) << (currentDate->tm_mon + 1) << "-" << (1900 + currentDate->tm_year);
    
    rentDate = ss.str();
}

void Booking::setRentDuration(int days){ rentDuration = days; }
void Booking::setRentalCost(double cost) { rentalCost = cost; }

string Booking::getBookingID() const { return bookingID; }
string Booking::getBookedVehicleID() const { return bookedVehicleID; }
string Booking::getBookedCustomerID() const { return bookedCustomerID; }
string Booking::getRentDate() const { return rentDate; }
int Booking::getRentDuration() const { return rentDuration; }
double Booking::getRentalCost() const { return rentalCost; }
int Booking::getBookingsCount() { return bookingsCount; }

Booking::~Booking() { bookingsCount--; }

int Booking::bookingsCount = 0;