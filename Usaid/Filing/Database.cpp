#include "Database.h"
#include <fstream>
#include <sys/stat.h>
#include <iostream>

using namespace std;

// Initialize static members
vector<Vehicle> Database::vehicles;
vector<Customer> Database::customers;
vector<Rental> Database::rentals;

const string Database::VEHICLE_FILE = "data/vehicles.dat";
const string Database::CUSTOMER_FILE = "data/customers.dat";
const string Database::RENTAL_FILE = "data/rentals.dat";

void Database::createDataDirectory() {
    mkdir("data", 0777); // Create directory if it doesn't exist
}

void Database::initialize() {
    createDataDirectory();
    loadAllData();
}

void Database::cleanup() {
    saveAllData();
}

void Database::saveAllData() {
    try {
        Vehicle::saveToFile(vehicles, VEHICLE_FILE);
        Customer::saveToFile(customers, CUSTOMER_FILE);
        Rental::saveToFile(rentals, RENTAL_FILE);
    } catch (const exception& e) {
        cerr << "Error saving data: " << e.what() << endl;
    }
}

void Database::loadAllData() {
    try {
        vehicles = Vehicle::loadFromFile(VEHICLE_FILE);
        customers = Customer::loadFromFile(CUSTOMER_FILE);
        rentals = Rental::loadFromFile(RENTAL_FILE);
    } catch (const exception& e) {
        cout << "No existing data found. Starting with fresh database." << endl;
        vehicles.clear();
        customers.clear();
        rentals.clear();
    }
}
