#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cctype>
#include <conio.h>
#include <cstdlib>

#include "Car.h"
using namespace std;

Car::Car() : fuelType("") 
{
    carsCount++;
    generateVehicleID();
}

Car::Car(const string &b, const string &m, const string &l, double rate, bool available, const string &f) : Vehicle(b, m, l, rate, available, "Car"), fuelType(f) 
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

void Car::displayVehicleDetails(ostream &os) const
{
    os << "Vehicle ID: " << vehicleID << " | Brand: " << brand << " | Model: " << model << " | Vehicle Type: " << endl;
    os << "Rate Per Day: $" << ratePerDay << " | License Plate: " << licensePlate << " | Available: " << ((isAvailable) ? "Yes" : "No") << " | Fuel Type: " << fuelType << endl;
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

    do
    {
        cout << "Enter the rate per day of the new car: ";
        cin >> ratePerDay;
        if (ratePerDay <= 0)
        {
            cout << "Invalid rate! Please enter a positive value." << endl;
        }
    } while (ratePerDay <= 0);
    cin.ignore();

    cout << "Enter the fuel type of the new car: ";
    getline(cin, fuelType);

    isAvailable = true;
    vehicleType = "Car";
}

Car::~Car() { carsCount--; }

int Car::carsCount = 0;