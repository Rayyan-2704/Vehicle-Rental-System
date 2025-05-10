#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Admin.h"
#include "Customer.h"
#include "Vehicle.h"

using namespace std;

class FileHandler {
public:
    // Admin related file operations
    static void saveAdmins(const vector<Admin>& admins);
    static vector<Admin> loadAdmins();
    
    // Customer related file operations
    static void saveCustomers(const vector<Customer>& customers);
    static vector<Customer> loadCustomers();
    
    // Vehicle related file operations
    static void saveVehicles(const vector<Vehicle>& vehicles);
    static vector<Vehicle> loadVehicles();
    
    // Rental records
    static void saveRentalRecords(const vector<RentalRecord>& records);
    static vector<RentalRecord> loadRentalRecords();
};

#endif
