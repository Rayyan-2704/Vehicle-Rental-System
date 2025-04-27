#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <string>
#include "Vehicle.h"
#include "Customer.h"
#include "Rental.h"

using namespace std;

class Database {
public:
    static vector<Vehicle> vehicles;
    static vector<Customer> customers;
    static vector<Rental> rentals;

    static void initialize();
    static void cleanup();
    static void saveAllData();
    static void loadAllData();

private:
    static const string VEHICLE_FILE;
    static const string CUSTOMER_FILE;
    static const string RENTAL_FILE;
    
    static void createDataDirectory();
};

#endif
