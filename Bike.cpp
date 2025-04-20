#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cctype>
#include <conio.h>
#include <cstdlib>

#include "Bike.h"
using namespace std;

Bike::Bike() : engineCC(0)
{
    bikesCount++;
    generateVehicleID();
}

Bike::Bike(const string &b, const string &m, const string &l, double rate, bool available, int cc) : Vehicle(b, m, l, rate, available, "Bike"), engineCC(cc)
{
    bikesCount++;
    generateVehicleID();
}

void Bike::setEngineCC(int cc) { engineCC = cc; }
int Bike::getEngineCC() const { return engineCC; }
int Bike::getBikesCount() { return bikesCount; }

void Bike::generateVehicleID()
{
    stringstream ss;
    ss << "VB-" << setw(4) << setfill('0') << bikesCount;
    vehicleID = ss.str();
}

void Bike::displayVehicleDetails(ostream &os) const
{
    os << "Vehicle ID: " << vehicleID << " | Brand: " << brand << " | Model: " << model << " | Vehicle Type: " << endl;
    os << "Rate Per Day: $" << ratePerDay << " | License Plate: " << licensePlate << " | Available: " << ((isAvailable) ? "Yes" : "No") << " | Engine CC: " << engineCC << " CC" <<endl;
}

void Bike::addVehicle()
{
    cout << endl << "Enter the details of the new BIKE below" << endl;
    cout << "Enter the brand of the new bike: ";
    getline(cin, brand);

    cout << "Enter the model of the new bike: ";
    getline(cin, model);

    cout << "Enter the license plate of the new bike: ";
    getline(cin, licensePlate);

    do
    {
        cout << "Enter the rate per day of the new bike: ";
        cin >> ratePerDay;
        if (ratePerDay <= 0)
        {
            cout << "Invalid rate! Please enter a positive value." << endl;
        }
    } while (ratePerDay <= 0);

    cout << "Enter the engine CC of the new bike: ";
    cin >> engineCC;
    cin.ignore();

    isAvailable = true;
    vehicleType = "Bike";   
}

Bike::~Bike() { bikesCount--; }

int Bike::bikesCount = 0;