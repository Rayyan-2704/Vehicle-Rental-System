#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <conio.h>
#include <cstdlib>

#include "Car.h"
using namespace std;

Car::Car() : fuelType("") 
{
    carsCount++;
    generateVehicleID();
}

Car::Car(const string &b, const string &m, const string &l, double rate, bool available, const string &f) : Vehicle(b, m, l, rate, available), fuelType(f) 
{
    carsCount++;
    generateVehicleID();
}

void Car::setFuelType(const string &f) { fuelType = f; }
string Car::getFuelType() const { return fuelType; }
int Car::getCarsCount() { return carsCount; }

void Car::generateVehicleID()
{
    stringstream ss;
    ss << "VC-" << setw(4) << setfill('0') << carsCount;
    vehicleID = ss.str();
}

void Car::displayCarDetails(ostream &os) const
{

}

Vehicle* Car::addVehicle() 
{

}

void Car::removeVehicle()
{
    
}

int Car::carsCount = 0;