#ifndef CAR_H
#define CAR_H

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

class Car : public Vehicle
{
    string fuelType;
    static int carsCount;

public:
    Car();
    Car(const string &b, const string &m, const string &l, double rate, bool available, const string &f);

    void setFuelType(const string &f);
    string getFuelType() const;
    static int getCarsCount();
    
    void generateVehicleID() override;
    void displayVehicleDetails(ostream &os) const override;
    void addVehicle() override;

    ~Car();
};

#endif