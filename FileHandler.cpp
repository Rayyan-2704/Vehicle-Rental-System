#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <conio.h>
#include <cstdlib>
#include <fstream>

#include "FileHandler.h"
using namespace std;

FileHandler::FileHandler() {}

void FileHandler::loadAdminData(vector <Admin*> &admins, const string &fileName)
{
    inputFile.open(fileName);
    if (!inputFile.is_open())
    {
        cerr << "Error in opening the Admin file!" << endl;
        return;
    }
    string line;

    /* Reading objects and storing it */
    int initialIDCounter = 0;
    getline(inputFile, line); // Read Variables Header
    while (getline(inputFile, line))
    {
        stringstream inputString(line);
        string id, name, email, password, phoneNumber, address;

        getline(inputString, id, ',');
        getline(inputString, name, ',');
        getline(inputString, email, ',');
        getline(inputString, password, ',');
        getline(inputString, phoneNumber, ',');
        getline(inputString, address);

        Admin *a = new Admin(name, email, password, phoneNumber, address);
        a->setUserID(id);

        admins.push_back(a);

        int count = atoi(a->getUserID().substr(3).c_str());
        if (count > initialIDCounter)
        {
            initialIDCounter = count;
        }
    }

    /* Setting the Admin ID Counter to an initial value to start from in the program */
    Admin::setAdminIDCounter(initialIDCounter);

    inputFile.close();
}

void FileHandler::writeAdminData(vector <Admin*> &admins, const string &fileName)
{
    outputFile.open(fileName);
    if (!outputFile.is_open())
    {
        cerr << "Error in opening the Admin file!" << endl;
        return;
    }

    /* Writing Object Variables */
    outputFile << "Admin ID,Full Name,Email,Password,Phone Number,Address" << endl; // Object Variables Header
    for (Admin *a : admins)
    {
        outputFile << a->getUserID() << "," << a->getUserName() << "," << a->getUserEmail() << "," << a->getUserPassword() << "," << a->getUserPhoneNumber() << "," << a->getUserAddress() << endl;
    }

    outputFile.close();
}

void FileHandler::loadCustomerData(vector <Customer*> &customers, const string &fileName)
{
    inputFile.open(fileName);
    if (!inputFile.is_open())
    {
        cerr << "Error in opening the Customer file!" << endl;
        return;
    }
    string line;

    /* Reading objects and storing it */
    int initialIDCounter = 0;
    getline(inputFile, line); // Read Variables Header
    while (getline(inputFile, line))
    {
        stringstream inputString(line);
        string id, name, email, password, phoneNumber, address;

        getline(inputString, id, ',');
        getline(inputString, name, ',');
        getline(inputString, email, ',');
        getline(inputString, password, ',');
        getline(inputString, phoneNumber, ',');
        getline(inputString, address);

        Customer *c = new Customer(name, email, password, phoneNumber, address);
        c->setUserID(id);

        customers.push_back(c);

        int count = atoi(c->getUserID().substr(3).c_str());
        if (count > initialIDCounter)
        {
            initialIDCounter = count;
        }
    }

    /* Setting the Customer ID Counter to an initial value to start from in the program */
    Customer::setCustomerIDCounter(initialIDCounter);

    inputFile.close();
}

void FileHandler::writeCustomerData(vector <Customer*> &customers, const string &fileName)
{
    outputFile.open(fileName);
    if (!outputFile.is_open())
    {
        cerr << "Error in opening the Customer file!" << endl;
        return;
    }

    /* Writing Object Variables */
    outputFile << "Customer ID,Full Name,Email,Password,Phone Number,Address" << endl; // Object Variables Header
    for (Customer *c : customers)
    {
        outputFile << c->getUserID() << "," << c->getUserName() << "," << c->getUserEmail() << "," << c->getUserPassword() << "," << c->getUserPhoneNumber() << "," << c->getUserAddress() << endl;
    }

    outputFile.close();
}

void FileHandler::loadVehiclesData(vector <Vehicle*> &inventory, const string &fileName)
{
    inputFile.open(fileName);
    if (!inputFile.is_open())
    {
        cerr << "Error in opening the Vehicles file!" << endl;
        return;
    }
    string line;

    /* Reading objects and storing it */
    Vehicle *v;
    int initialCarIDCounter = 0, initialBikeIDCounter = 0, initialTruckIDCounter = 0;
    getline(inputFile, line); // Read Variables Header
    while (getline(inputFile, line))
    {
        stringstream inputString(line);
        string id, brand, model, license, type, tempString, additionalData;
        double rate;
        bool availability;

        getline(inputString, id, ',');
        getline(inputString, brand, ',');
        getline(inputString, model, ',');
        getline(inputString, license, ',');
        getline(inputString, type, ',');

        getline(inputString, tempString, ',');
        rate = atof(tempString.c_str());

        getline(inputString, tempString, ',');
        availability = (tempString == "Yes") ? true : false;

        getline(inputString, additionalData);

        if (type == "Car")
        {
            v = new Car(brand, model, license, rate, availability, additionalData);
            int count = atoi(v->getVehicleID().substr(3).c_str());
            if (count > initialCarIDCounter)
            {
                initialCarIDCounter = count;
            }
        }
        else if (type == "Bike")
        {
            int engineCC = atoi(additionalData.c_str());
            v = new Bike(brand, model, license, rate, availability, engineCC);
            int count = atoi(v->getVehicleID().substr(3).c_str());
            if (count > initialBikeIDCounter)
            {
                initialBikeIDCounter = count;
            }
        }
        else if (type == "Truck")
        {
            double loadCapacity = atof(additionalData.c_str());
            v = new Truck(brand, model, license, rate, availability, loadCapacity);
            int count = atoi(v->getVehicleID().substr(3).c_str());
            if (count > initialTruckIDCounter)
            {
                initialTruckIDCounter = count;
            }
        }

        v->setVehicleID(id);

        inventory.push_back(v);
    }

    /* Setting the Car/Bike/Truck ID Counter to an initial value to start from in the program  */
    Car::setCarIDCounter(initialCarIDCounter);
    Bike::setBikeIDCounter(initialBikeIDCounter);
    Truck::setTruckIDCounter(initialTruckIDCounter);

    inputFile.close();
}

void FileHandler::writeVehiclesData(vector <Vehicle*> &inventory, const string &fileName)
{
    outputFile.open(fileName);
    if (!outputFile.is_open())
    {
        cerr << "Error in opening the Customer file!" << endl;
        return;
    }

    /* Writing Object Variables*/
    outputFile << "Vehicle ID,Brand,Model,License,Vehicle Type,Rate Per Day,Available,Additional Data" << endl; // Object Variables Header
    for (Vehicle *v : inventory)
    {
        outputFile << v->getVehicleID() << "," << v->getBrand() << "," << v->getModel() << "," << v->getLicensePlate() << "," << v->getVehicleType() << "," << toTwoDecimalString(v->getRatePerDay()) << "," << ((v->getAvailability()) ? "Yes" : "No") << "," << v->getAdditionalData() << endl;
    }

    outputFile.close();
}

void FileHandler::loadBookingsData(vector <Customer*> &customers, const string &fileName)
{
    inputFile.open(fileName);
    if (!inputFile.is_open())
    {
        cerr << "Error in opening the Vehicles file!" << endl;
        return;
    }
    string line;

    /* Reading objects and storing it */
    int initialIDCounter = 0;
    getline(inputFile, line); // Read Variables Header
    while (getline(inputFile, line))
    {
        stringstream inputString(line);
        string bID, vehicleID, customerID, date, tempString;

        getline(inputString, bID, ',');
        getline(inputString, vehicleID, ',');
        getline(inputString, customerID, ',');
        getline(inputString, date, ',');

        getline(inputString, tempString, ',');
        int duration = atoi(tempString.c_str());

        getline(inputString, tempString);
        double cost = atof(tempString.c_str());

        Booking *b = new Booking(vehicleID, customerID, duration);
        b->setBookingID(bID);
        b->setRentDate(date);
        b->setRentalCost(cost);

        int count = atoi(bID.substr(3).c_str());
        if (count > initialIDCounter)
        {
            initialIDCounter = count;
        }

        for (Customer *c : customers)
        {
            if (c->getUserID() == b->getBookedCustomerID())
            {
                c->addBooking(*b);
            }
        }
    }

    /* Setting the Booking ID Counter to an initial value to start from in the program */
    Booking::setIDCounter(initialIDCounter);

    inputFile.close();
}

void FileHandler::writeBookingsData(vector <Customer*> &customers, const string &fileName)
{
    outputFile.open(fileName);
    if (!outputFile.is_open())
    {
        cerr << "Error in opening the Customer file!" << endl;
        return;
    }

    /* Writing Object Variables*/
    outputFile << "Booking ID,Vehicle ID,Customer ID,Rent Date,Rent Duration,Rental Cost" << endl; // Object Variables Header
    for (Customer *c : customers)
    {
        for (const Booking &b : c->getBookings())
        {
            outputFile << b.getBookingID() << "," << b.getBookedVehicleID() << "," << b.getBookedCustomerID() << "," << b.getRentDate() << "," << b.getRentDuration() << "," << toTwoDecimalString(b.getRentalCost()) << endl;
        }
    }

    outputFile.close();
}

FileHandler::~FileHandler() 
{
    if (inputFile.is_open() || outputFile.is_open())
    {
        inputFile.close();
        outputFile.close();
    }
}