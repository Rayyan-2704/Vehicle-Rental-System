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
    bikeIDCounter++;
    generateVehicleID();
}

Bike::Bike(const string &b, const string &m, const string &l, double rate, bool available, int cc) : Vehicle(b, m, l, rate, available, "Bike"), engineCC(cc)
{
    bikesCount++;
    bikeIDCounter++;    
    generateVehicleID();
}

void Bike::setBikeIDCounter(int count) { bikeIDCounter = count; }
void Bike::setEngineCC(int cc) { engineCC = cc; }
int Bike::getEngineCC() const { return engineCC; }
int Bike::getBikesCount() { return bikesCount; }
string Bike::getAdditionalData() const
{
    string s = to_string(engineCC);
    return s;
}

void Bike::generateVehicleID()
{
    stringstream ss;
    ss << "VB-" << setw(4) << setfill('0') << bikeIDCounter;
    vehicleID = ss.str();
}

void Bike::incrementOrDecrementIDCounter(bool isIncrement)
{
    (isIncrement) ? bikeIDCounter++ : bikeIDCounter --;
}

void Bike::displayVehicleDetails(ostream &os) const
{
    // os << "Vehicle ID: " << vehicleID << endl;
    // os << "Brand: " << brand << " | Model: " << model << " | Type: " << vehicleType << endl;
    // os << "Rate: $" << ratePerDay << " | License Plate: " << licensePlate << " | Available: " << ((isAvailable) ? "Yes" : "No") << endl;
    // os << "Engine CC: " << engineCC <<  " CC" << endl;
    printFormattedText("Vehicle ID: " + vehicleID, COLOR_WHITE, false);
    printFormattedText("Brand: " + brand + " | Model: " + model + " | Type: " + vehicleType, COLOR_WHITE, false);
    printFormattedText("Rate: $" + toTwoDecimalString(ratePerDay) + " | License Plate: " + licensePlate + " | Available: " + ((isAvailable) ? "Yes" : "No"), COLOR_WHITE, false);
    printFormattedText("Engine CC: " + to_string(engineCC) + " CC", COLOR_WHITE, false);
    printLineWithSpaces();
}

void Bike::addVehicle()
{
    // cout << endl << "Enter the details of the new BIKE below" << endl;
    printFormattedText("Enter the details of the new BIKE below", COLOR_WHITE, false);
    // cout << "Enter the brand of the new bike: ";
    printFormattedText("Enter the brand of the new bike:", COLOR_WHITE, false);
    printInputPrompt();
    getline(cin, brand);

    // cout << "Enter the model of the new bike: ";
    printFormattedText("Enter the model of the new bike:", COLOR_WHITE, false);
    printInputPrompt();
    getline(cin, model);

    // cout << "Enter the license plate of the new bike: ";
    printFormattedText("Enter the license plate of the new bike:", COLOR_WHITE, false);
    printInputPrompt();
    getline(cin, licensePlate);

    do
    {
        // cout << "Enter the rate per day of the new bike: ";
        printFormattedText("Enter the rate per day of the new bike:", COLOR_WHITE, false);
        printInputPrompt();
        cin >> ratePerDay;
        if (ratePerDay <= 0)
        {
            // cout << "Invalid rate! Please enter a positive value." << endl;
            printFormattedText("Invalid rate! Please enter a positive value.", COLOR_WHITE, false);
        }
    } while (ratePerDay <= 0);

    do 
    {
        // cout << "Enter the engine CC of the new bike: ";
        printFormattedText("Enter the engine CC of the new bike:", COLOR_WHITE, false);
        printInputPrompt();
        cin >> engineCC;
        if (engineCC <= 0) 
        {
            // cout << "Invalid engine CC! Please enter a positive value." << endl;
            printFormattedText("Invalid engine CC! Please enter a positive value.", COLOR_WHITE, false);
        }
    } while (engineCC <= 0);
    cin.ignore();

    isAvailable = true;
    vehicleType = "Bike";   
}

Bike::~Bike() { bikesCount--; }

int Bike::bikesCount = 0;
int Bike::bikeIDCounter = 0;