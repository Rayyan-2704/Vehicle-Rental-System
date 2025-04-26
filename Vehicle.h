#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <conio.h>
#include <cstdlib>

#include "TerminalControl.h"
using namespace std;

class Vehicle
{
protected:
    string vehicleID;
    string brand;
    string model;
    string licensePlate;
    double ratePerDay;
    bool isAvailable;
    string vehicleType;
    static int vehiclesCount;

public:
    Vehicle();
    Vehicle(const string &b, const string &m, const string &l, double rate, bool available, const string vT);

    /* Vehicle Utility Methods */
    virtual void generateVehicleID();
    virtual void incrementOrDecrementIDCounter(bool isIncrement) = 0;
    virtual void displayVehicleDetails(ostream &os) const = 0;
    virtual void addVehicle() = 0;

    /* Setters (Mutators) */
    void setBrand(const string &b);
    void setModel(const string &m);
    void setLicensePlate(const string &l);
    void setRatePerDay(double rate);
    void setAvailability(bool available);
    void setVehicleType(const string &type);

    /* Getters (Accessors) */
    string getVehicleID() const;
    string getBrand() const;
    string getModel() const;
    string getLicensePlate() const;
    double getRatePerDay() const;
    bool getAvailability() const;
    string getVehicleType() const;
    static int getVehiclesCount();

    /* Operator Overloaded Friend Function */
    friend ostream &operator<<(ostream &os, const Vehicle &v);

    /* Destructor */
    virtual ~Vehicle();
};

ostream &operator<<(ostream &os, const Vehicle &v);

#endif