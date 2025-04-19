#ifndef TRUCK_H
#define TRUCK_H

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

class Truck : public Vehicle 
{
    double loadCapacity;
    static int trucksCount;

public:
    Truck();
    Truck(const string &b, const string &m, const string &l, double rate, bool available, double lC);

    void setLoadCapacity(double lC);
    double getLoadCapacity() const;
    static int getTrucksCount();

    void generateVehicleID() override;
    void displayVehicleDetails(ostream &os) const override;
    void addVehicle() override;

    ~Truck();
};

#endif