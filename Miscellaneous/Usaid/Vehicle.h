#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include <string>
using namespace std;
class Vehicle
{
protected:
    int vehicleID;
    string brand;
    string model;
    int year;
    string licensePlate;
    float pricePerDay;
    bool isAvailable;
    string fuelType;
    float mileage;

public:
    // Constructor
    Vehicle(int id, const string &brand, const string &model, int year,
            const string &licensePlate, float price, bool available,
            const string &fuelType, float mileage);

    // Virtual destructor
    virtual ~Vehicle() = default;

    // Display vehicle information
    virtual void displayInfo() const;

    // Calculate rental price for given number of days
    virtual float calculatePrice(int days) const;

    // Update availability status
    virtual void updateAvailability(bool available);

    // Getters
    int getVehicleID() const;
    string getBrand() const;
    string getModel() const;
    int getYear() const;
    string getLicensePlate() const;
    float getPricePerDay() const;
    bool getIsAvailable() const;
    string getFuelType() const;
    float getMileage() const;
};

class Car : virtual public Vehicle
{
private:
    string carType;
    int numDoors;

public:
    Car(int id, const string &brand, const string &model, int year,
        const string &licensePlate, float price, bool available,
        const string &fuelType, float mileage,
        const string &carType, int numDoors);

    void displayInfo() const override;
};

class Bike : virtual public Vehicle
{
private:
    float engineCC;
    bool hasABS;

public:
    Bike(int id, const string &brand, const string &model, int year,
         const string &licensePlate, float price, bool available,
         const string &fuelType, float mileage,
         float engineCC, bool hasABS);

    void displayInfo() const override;
};

class Truck : virtual public Vehicle
{
private:
    float loadCapacity;
    bool isHeavyDuty;

public:
    Truck(int id, const string &brand, const string &model, int year,
          const string &licensePlate, float price, bool available,
          const string &fuelType, float mileage,
          float loadCapacity, bool isHeavyDuty);

    void displayInfo() const override;
};

#endif