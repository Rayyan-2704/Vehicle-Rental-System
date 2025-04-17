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

Car::Car(const string &b, const string &m, const string &l, double rate, bool available, const string &f) : Vehicle(b, m, l, rate, available, "car"), fuelType(f) 
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

void Car::addVehicle() 
{
    cout << endl << "Enter the details of the new CAR below" << endl;
    cout << "Enter the brand of the new car: ";
    getline(cin, brand);
    cout << "Enter the model of the new car: ";
    getline(cin, model);
    cout << "Enter the license plate of the new car: ";
    getline(cin, licensePlate);
    cout << "Enter the rate per day of the new car: ";
    cin >> ratePerDay;
    cin.ignore();
    cout << "Enter the fuel type of the new car: ";
    getline(cin, fuelType);
    isAvailable = true;
    vehicleType = "car";
}

void Car::removeVehicle(vector <Vehicle*> &inventory, const string &id)
{
    
}

Car::~Car() { carsCount--; }

int Car::carsCount = 0;