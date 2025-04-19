#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cctype>
#include <conio.h>
#include <cstdlib>

#include "Vehicle.h"
using namespace std;

Vehicle::Vehicle() : brand(""), model(""), licensePlate(""), ratePerDay(0.0), isAvailable(false)
{
    vehiclesCount++;
    generateVehicleID();
}

Vehicle::Vehicle(const string &b, const string &m, const string &l, double rate, bool available, const string vT) : brand(b), model(m), licensePlate(l), ratePerDay(rate), isAvailable(available), vehicleType(vT)
{
    vehiclesCount++;
    generateVehicleID();
}

void Vehicle::generateVehicleID() 
{
    stringstream ss;
    ss << "V-" << setw(4) << setfill('0') << vehiclesCount;
    vehicleID = ss.str();
}

/* Setters */
void Vehicle::setBrand(const string &b) { brand = b; }
void Vehicle::setModel(const string &m) { model = m; }
void Vehicle::setLicensePlate(const string &l) { licensePlate = l; }
void Vehicle::setRatePerDay(double rate) { ratePerDay = rate; }
void Vehicle::setAvailability(bool available) { isAvailable = available; }
void Vehicle::setVehicleType(const string &type) { vehicleType = type; } 

/* Getters */
string Vehicle::getVehicleID() const { return vehicleID; }
string Vehicle::getBrand() const { return brand; }
string Vehicle::getModel() const { return model; }
string Vehicle::getLicensePlate() const { return licensePlate; }
double Vehicle::getRatePerDay() const { return ratePerDay; }
bool Vehicle::getAvailability() const { return isAvailable; }
string Vehicle::getVehicleType() const { return vehicleType; }
int Vehicle::getVehiclesCount() { return vehiclesCount; }

Vehicle::~Vehicle() { vehiclesCount--; }

int Vehicle::vehiclesCount = 0;

ostream &operator<<(ostream &os, const Vehicle &v)
{
    v.displayVehicleDetails(os);
    return os;
}