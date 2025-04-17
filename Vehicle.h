#ifndef VEHICLE_H
#define VEHICLE_h

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <conio.h>
#include <cstdlib>
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
    virtual void displayVehicleDetails(ostream &os) const = 0;
    virtual void addVehicle() = 0;
    void removeVehicle(vector <Vehicle*> &inventory, const string &id); 

    /* Setters (Mutators) */
    void setBrand(const string &b);
    void setModel(const string &m);
    void setLicensePlate(const string &l);
    void setRatePerDay(double rate);
    void setAvailability(bool available);

    /* Getters (Accessors) */
    string getVehicleID() const;
    string getBrand() const;
    string getModel() const;
    string getLicensePlate() const;
    double getRatePerDay() const;
    bool getAvailability() const;
    static int getVehiclesCount();

    /* Operator Overloaded Friend Function */
    friend ostream &operator<<(ostream &os, const Vehicle &v);

    /* Destructor */
    virtual ~Vehicle();
};

ostream &operator<<(ostream &os, const Vehicle &v);

#endif