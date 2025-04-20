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
    generateVehicleID();
}

Truck::Truck(const string &b, const string &m, const string &l, double rate, bool available, double lC) : Vehicle(b, m, l, rate, available, "Truck"), loadCapacity(lC)
{
    trucksCount++;
    generateVehicleID();
}

void Truck::setLoadCapacity(double lC) { loadCapacity = lC; }
double Truck::getLoadCapacity() const { return loadCapacity; }
int Truck::getTrucksCount() { return trucksCount; }

void Truck::generateVehicleID()
{
    stringstream ss;
    ss << "VT-" << setw(4) << setfill('0') << trucksCount;
    vehicleID = ss.str();
}

void Truck::displayVehicleDetails(ostream &os) const
{
    // os << "Vehicle ID: " << vehicleID << " | Brand: " << brand << " | Model: " << model << " | Vehicle Type: " << vehicleType << endl;
    // os << "Rate Per Day: $" << ratePerDay << " | License Plate: " << licensePlate << " | Available: " << ((isAvailable) ? "Yes" : "No") << " | Load Capacity: " << loadCapacity << " kg" << endl;
    os << "Vehicle ID: " << vehicleID << endl;
    os << "Brand: " << brand << " | Model: " << model << " | Type: " << vehicleType << endl;
    os << "Rate: $" << ratePerDay << " | License Plate: " << licensePlate << " | Available: " << ((isAvailable) ? "Yes" : "No") << endl;
    os << "Load Capacity: " << loadCapacity << " kg" << endl;
}

void Truck::addVehicle()
{
    cout << endl << "Enter the details of the new TRUCK below" << endl;
    cout << "Enter the brand of the new truck: ";
    getline(cin, brand);

    cout << "Enter the model of the new truck: ";
    getline(cin, model);

    cout << "Enter the license plate of the new truck: ";
    getline(cin, licensePlate);

    do
    {
        cout << "Enter the rate per day of the new truck: ";
        cin >> ratePerDay;
        if (ratePerDay <= 0)
        {
            cout << "Invalid rate! Please enter a positive value." << endl;
        }
    } while (ratePerDay <= 0);

    do {
        cout << "Enter the load capacity (in kg) of the new truck: ";
        cin >> loadCapacity;
        if (loadCapacity <= 0) 
        {
            cout << "Invalid capacity! Please enter a positive value." << endl;
        }
    } while (loadCapacity <= 0);
    cin.ignore();
    

    isAvailable = true;
    vehicleType = "Truck";   
}

Truck::~Truck() { trucksCount--; }

int Truck::trucksCount = 0;