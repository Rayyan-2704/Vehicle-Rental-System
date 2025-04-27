#include "Database.h"
#include <stdexcept>

// Initialize static members
std::vector<Vehicle> Database::vehicles;
std::vector<Customer> Database::customers;
std::vector<Rental> Database::rentals;

const std::string Database::VEHICLE_FILE = "data/vehicles.dat";
const std::string Database::CUSTOMER_FILE = "data/customers.dat";
const std::string Database::RENTAL_FILE = "data/rentals.dat";

void Database::initialize() {
    loadAllData();
}

void Database::cleanup() {
    saveAllData();
}

void Database::saveAllData() {
    try {
        // Create data directory if it doesn't exist
        system("mkdir -p data");
        
        Vehicle::saveToFile(vehicles, VEHICLE_FILE);
        Customer::saveToFile(customers, CUSTOMER_FILE);
        Rental::saveToFile(rentals, RENTAL_FILE);
    } catch (const std::exception& e) {
        std::cerr << "Error saving data: " << e.what() << std::endl;
    }
}

void Database::loadAllData() {
    try {
        vehicles = Vehicle::loadFromFile(VEHICLE_FILE);
        customers = Customer::loadFromFile(CUSTOMER_FILE);
        rentals = Rental::loadFromFile(RENTAL_FILE);
    } catch (const std::exception& e) {
        std::cerr << "Error loading data: " << e.what() << std::endl;
        // Initialize empty vectors if files don't exist
        vehicles.clear();
        customers.clear();
        rentals.clear();
    }
}
