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
    carIDCounter++;
    generateVehicleID();
}

Car::Car(const string &b, const string &m, const string &l, double rate, bool available, const string &f) : Vehicle(b, m, l, rate, available, "Car"), fuelType(f) 
{
    carsCount++;
    carIDCounter++;
    generateVehicleID();
}

void Car::setFuelType(const string &f) { fuelType = f; }
string Car::getFuelType() const { return fuelType; }
int Car::getCarsCount() { return carsCount; }

void Car::generateVehicleID()
{
    stringstream ss;
    ss << "VC-" << setw(4) << setfill('0') << carIDCounter;
    vehicleID = ss.str();
}

void Car::incrementOrDecrementIDCounter(bool isIncrement)
{
    (isIncrement) ? carIDCounter++ : carIDCounter--;
}

void Car::displayVehicleDetails(ostream &os) const
{
    // os << "Vehicle ID: " << vehicleID << endl;
    // os << "Brand: " << brand << " | Model: " << model << " | Type: " << vehicleType << endl;
    // os << "Rate: $" << ratePerDay << " | License Plate: " << licensePlate << " | Available: " << ((isAvailable) ? "Yes" : "No") << endl;
    // os << "Fuel Type: " << fuelType << endl;
    printFormattedText("Vehicle ID: " + vehicleID, COLOR_WHITE, false);
    printFormattedText("Brand: " + brand + " | Model: " + model + " | Type: " + vehicleType, COLOR_WHITE, false);
    printFormattedText("Rate: $" + to_string(ratePerDay) + " | License Plate: " + licensePlate + " | Available: " + ((isAvailable) ? "Yes" : "No"), COLOR_WHITE, false);
    printFormattedText("Fuel Type: " + fuelType, COLOR_WHITE, false);
    printLineWithSpaces(COLOR_CYAN);
}

void Car::addVehicle()
{
    // cout << endl << "Enter the details of the new CAR below" << endl;
    printFormattedText("Enter the details of the new CAR below", COLOR_WHITE, false);
    // cout << "Enter the brand of the new car: ";
    printFormattedText("Enter the brand of the new car:", COLOR_WHITE, false);
    cout << COLOR_CYAN << "| >> " << COLOR_RESET;
    getline(cin, brand);

    // cout << "Enter the model of the new car: ";
    printFormattedText("Enter the model of the new car:", COLOR_WHITE, false);
    cout << COLOR_CYAN << "| >> " << COLOR_RESET;
    getline(cin, model);

    // cout << "Enter the license plate of the new car: ";
    printFormattedText("Enter the license plate of the new car:", COLOR_WHITE, false);
    cout << COLOR_CYAN << "| >> " << COLOR_RESET;
    getline(cin, licensePlate);

    do
    {
        // cout << "Enter the rate per day of the new car: ";
        printFormattedText("Enter the rate per day of the new car:", COLOR_WHITE, false);
        cout << COLOR_CYAN << "| >> " << COLOR_RESET;
        cin >> ratePerDay;
        if (ratePerDay <= 0)
        {
            // cout << "Invalid rate! Please enter a positive value." << endl;
            printFormattedText("Invalid rate! Please enter a positive value.", COLOR_WHITE, false);
        }
    } while (ratePerDay <= 0);
    cin.ignore();

    // cout << "Enter the fuel type of the new car: ";
    printFormattedText("Enter the fuel type of the new car:", COLOR_WHITE, false);
    cout << COLOR_CYAN << "| >> " << COLOR_RESET;
    getline(cin, fuelType);

    isAvailable = true;
    vehicleType = "Car";
}

Car::~Car() { carsCount--; }

int Car::carsCount = 0;
int Car::carIDCounter = 0;