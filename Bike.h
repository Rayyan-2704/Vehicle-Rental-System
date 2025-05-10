#ifndef BIKE_H
#define BIKE_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <conio.h>
#include <cstdlib>

#include "Vehicle.h"
using namespace std;

class Bike : public Vehicle
{
    int engineCC;
    static int bikesCount;
    static int bikeIDCounter;

public:
    Bike();
    Bike(const string &b, const string &m, const string &l, double rate, bool available, int cc);

    static void setBikeIDCounter(int count);
    void setEngineCC(int cc);
    int getEngineCC() const;
    static int getBikesCount();
    string getAdditionalData() const override;
    
    void generateVehicleID() override;
    void incrementOrDecrementIDCounter(bool isIncrement) override;
    void displayVehicleDetails(ostream &os) const override;
    void addVehicle() override;

    ~Bike();
};

#endif