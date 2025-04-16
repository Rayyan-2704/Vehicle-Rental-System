#include "Vehicle.h"
#include <iostream>
#include <string>
using namespace std;
// Vehicle class implementation
Vehicle::Vehicle(int id, const string &brand, const string &model, int year,
                 const string &licensePlate, float price, bool available,
                 const string &fuelType, float mileage)
    : vehicleID(id), brand(brand), model(model), year(year),
      licensePlate(licensePlate), pricePerDay(price), isAvailable(available),
      fuelType(fuelType), mileage(mileage) {}

void Vehicle::displayInfo() const
{
    std::cout << "Vehicle ID: " << vehicleID << endl
              << "Brand: " << brand << endl
              << "Model: " << model << endl
              << "Year: " << year << endl
              << "License Plate: " << licensePlate << endl
              << "Price per day: $" << pricePerDay << endl
              << "Available: " << (isAvailable ? "Yes" : "No") << endl
              << "Fuel Type: " << fuelType << endl
              << "Mileage: " << mileage << " km\n";
}

float Vehicle::calculatePrice(int days) const
{
    return days * pricePerDay;
}

void Vehicle::updateAvailability(bool available)
{
    isAvailable = available;
}

// Getters implementation
int Vehicle::getVehicleID() const { return vehicleID; }
string Vehicle::getBrand() const { return brand; }
string Vehicle::getModel() const { return model; }
int Vehicle::getYear() const { return year; }
string Vehicle::getLicensePlate() const { return licensePlate; }
float Vehicle::getPricePerDay() const { return pricePerDay; }
bool Vehicle::getIsAvailable() const { return isAvailable; }
string Vehicle::getFuelType() const { return fuelType; }
float Vehicle::getMileage() const { return mileage; }

// Car class implementation
Car::Car(int id, const string &brand, const string &model, int year,
         const string &licensePlate, float price, bool available,
         const string &fuelType, float mileage,
         const string &carType, int numDoors)
    : Vehicle(id, brand, model, year, licensePlate, price, available, fuelType, mileage),
      carType(carType), numDoors(numDoors) {}

void Car::displayInfo() const
{
    Vehicle::displayInfo();
    cout << "Type: " << carType << "\n"
         << "Number of doors: " << numDoors << "\n";
}

// Bike class implementation
Bike::Bike(int id, const string &brand, const string &model, int year,
           const string &licensePlate, float price, bool available,
           const string &fuelType, float mileage,
           float engineCC, bool hasABS)
    : Vehicle(id, brand, model, year, licensePlate, price, available, fuelType, mileage),
      engineCC(engineCC), hasABS(hasABS) {}

void Bike::displayInfo() const
{
    Vehicle::displayInfo();
    cout << "Engine CC: " << engineCC << "\n"
         << "Has ABS: " << (hasABS ? "Yes" : "No") << "\n";
}

// Truck class implementation
Truck::Truck(int id, const string &brand, const string &model, int year,
             const string &licensePlate, float price, bool available,
             const string &fuelType, float mileage,
             float loadCapacity, bool isHeavyDuty)
    : Vehicle(id, brand, model, year, licensePlate, price, available, fuelType, mileage),
      loadCapacity(loadCapacity), isHeavyDuty(isHeavyDuty) {}

void Truck::displayInfo() const
{
    Vehicle::displayInfo();
    cout << "Load Capacity: " << loadCapacity << " kg\n"
         << "Heavy Duty: " << (isHeavyDuty ? "Yes" : "No") << "\n";
}