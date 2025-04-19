#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <conio.h>
#include <cstdlib>

#include "Bike.h"
using namespace std;

Bike::Bike() : engineCC(0)
{
    bikesCount++;
    generateVehicleID();
}

Bike::Bike(const string &b, const string &m, const string &l, double rate, bool available, int cc) : Vehicle(b, m, l, rate, available, "bike"), engineCC(cc)
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
    os << "Brand: " << brand << " | Model: " << model << " | Rate Per Day: $" << ratePerDay << endl;
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
    cout << "Enter the rate per day of the new bike: ";
    cin >> ratePerDay;
    cout << "Enter the engine CC of the new bike: ";
    cin >> engineCC;
    cin.ignore();
    isAvailable = true;
    vehicleType = "bike";   
}

Bike::~Bike() { bikesCount--; }

int Bike::bikesCount = 0;