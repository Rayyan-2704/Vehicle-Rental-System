#ifndef BIKE_H
#define BIKE_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <conio.h>
#include <cstdlib>

#include "Vehicle.h"
using namespace std;

class Bike : public Vehicle
{
    int engineCC;
    static int bikesCount;

public:
    Bike();
    Bike(const string &b, const string &m, const string &l, double rate, bool available, int cc);

    void setEngineCC(int cc);
    int getEngineCC() const;
    static int getBikesCount();
    
    void generateVehicleID() override;
    void displayVehicleDetails(ostream &os) const override;
    void addVehicle() override;

    ~Bike();
};

#endif