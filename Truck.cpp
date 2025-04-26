#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cctype>
#include <conio.h>
#include <cstdlib>

#include "Truck.h"
using namespace std;

Truck::Truck() : loadCapacity(0.0)
{
    trucksCount++;
    truckIDCounter++;
    generateVehicleID();
}

Truck::Truck(const string &b, const string &m, const string &l, double rate, bool available, double lC) : Vehicle(b, m, l, rate, available, "Truck"), loadCapacity(lC)
{
    trucksCount++;
    truckIDCounter++;
    generateVehicleID();
}

void Truck::setLoadCapacity(double lC) { loadCapacity = lC; }
double Truck::getLoadCapacity() const { return loadCapacity; }
int Truck::getTrucksCount() { return trucksCount; }

void Truck::generateVehicleID()
{
    stringstream ss;
    ss << "VT-" << setw(4) << setfill('0') << truckIDCounter;
    vehicleID = ss.str();
}

void Truck::incrementOrDecrementIDCounter(bool isIncrement)
{
    (isIncrement) ? truckIDCounter++ : truckIDCounter--;
}

void Truck::displayVehicleDetails(ostream &os) const
{
    // os << "Vehicle ID: " << vehicleID << endl;
    // os << "Brand: " << brand << " | Model: " << model << " | Type: " << vehicleType << endl;
    // os << "Rate: $" << ratePerDay << " | License Plate: " << licensePlate << " | Available: " << ((isAvailable) ? "Yes" : "No") << endl;
    // os << "Load Capacity: " << loadCapacity << " kg" << endl;
    printFormattedText("Vehicle ID: " + vehicleID, COLOR_WHITE, false);
    printFormattedText("Brand: " + brand + " | Model: " + model + " | Type: " + vehicleType, COLOR_WHITE, false);
    printFormattedText("Rate: $" + to_string(ratePerDay) + " | License Plate: " + licensePlate + " | Available: " + ((isAvailable) ? "Yes" : "No"), COLOR_WHITE, false);
    printFormattedText("Load Capacity: " + to_string(loadCapacity) + " kg" , COLOR_WHITE, false);
    printLineWithSpaces(COLOR_CYAN);
}

void Truck::addVehicle()
{
    // cout << endl << "Enter the details of the new TRUCK below" << endl;
    printFormattedText("Enter the details of the new TRUCK below", COLOR_WHITE, false);
    // cout << "Enter the brand of the new truck: ";
    printFormattedText("Enter the brand of the new truck:", COLOR_WHITE, false);
    cout << COLOR_CYAN << "| >> " COLOR_RESET;
    getline(cin, brand);

    // cout << "Enter the model of the new truck: ";
    printFormattedText("Enter the model of the new truck:", COLOR_WHITE, false);
    cout << COLOR_CYAN << "| >> " COLOR_RESET;
    getline(cin, model);

    // cout << "Enter the license plate of the new truck: ";
    printFormattedText("Enter the license plate of the new truck:", COLOR_WHITE, false);
    cout << COLOR_CYAN << "| >> " COLOR_RESET;
    getline(cin, licensePlate);

    do
    {
        // cout << "Enter the rate per day of the new truck: ";
        printFormattedText("Enter the rate per day of the new truck:", COLOR_WHITE, false);
        cout << COLOR_CYAN << "| >> " COLOR_RESET;
        cin >> ratePerDay;
        if (ratePerDay <= 0)
        {
            // cout << "Invalid rate! Please enter a positive value." << endl;
            printFormattedText("Invalid rate! Please enter a positive value.", COLOR_WHITE, false);
        }
    } while (ratePerDay <= 0);

    do {
        // cout << "Enter the load capacity (in kg) of the new truck: ";
        printFormattedText("Enter the load capacity (in kg) of the new truck:", COLOR_WHITE, false);
        cout << COLOR_CYAN << "| >> " COLOR_RESET;
        cin >> loadCapacity;
        if (loadCapacity <= 0) 
        {
            // cout << "Invalid capacity! Please enter a positive value." << endl;
            printFormattedText("Invalid capacity! Please enter a positive value.", COLOR_WHITE, false);
        }
    } while (loadCapacity <= 0);
    cin.ignore();
    

    isAvailable = true;
    vehicleType = "Truck";   
}

Truck::~Truck() { trucksCount--; }

int Truck::trucksCount = 0;
int Truck::truckIDCounter = 0;