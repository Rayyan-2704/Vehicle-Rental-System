#include "FileHandler.h"
#include <string>

// Admin file operations
void FileHandler::saveAdmins(const vector<Admin>& admins) {
    ofstream outFile("admins.dat", ios::binary);
    if (!outFile) {
        cerr << "Error opening file for writing admins!" << endl;
        return;
    }
    
    for (const Admin& admin : admins) {
        outFile.write(reinterpret_cast<const char*>(&admin), sizeof(Admin));
    }
    outFile.close();
}

vector<Admin> FileHandler::loadAdmins() {
    vector<Admin> admins;
    ifstream inFile("admins.dat", ios::binary);
    
    if (!inFile) {
        cerr << "No existing admin file found. Creating new one." << endl;
        return admins;
    }
    
    Admin admin;
    while (inFile.read(reinterpret_cast<char*>(&admin), sizeof(Admin))) {
        admins.push_back(admin);
    }
    inFile.close();
    return admins;
}

// Customer file operations
void FileHandler::saveCustomers(const vector<Customer>& customers) {
    ofstream outFile("customers.dat", ios::binary);
    if (!outFile) {
        cerr << "Error opening file for writing customers!" << endl;
        return;
    }
    
    for (const Customer& customer : customers) {
        outFile.write(reinterpret_cast<const char*>(&customer), sizeof(Customer));
    }
    outFile.close();
}

vector<Customer> FileHandler::loadCustomers() {
    vector<Customer> customers;
    ifstream inFile("customers.dat", ios::binary);
    
    if (!inFile) {
        cerr << "No existing customer file found. Creating new one." << endl;
        return customers;
    }
    
    Customer customer;
    while (inFile.read(reinterpret_cast<char*>(&customer), sizeof(Customer))) {
        customers.push_back(customer);
    }
    inFile.close();
    return customers;
}

// Vehicle file operations
void FileHandler::saveVehicles(const vector<Vehicle>& vehicles) {
    ofstream outFile("vehicles.dat", ios::binary);
    if (!outFile) {
        cerr << "Error opening file for writing vehicles!" << endl;
        return;
    }
    
    for (const Vehicle& vehicle : vehicles) {
        outFile.write(reinterpret_cast<const char*>(&vehicle), sizeof(Vehicle));
    }
    outFile.close();
}

vector<Vehicle> FileHandler::loadVehicles() {
    vector<Vehicle> vehicles;
    ifstream inFile("vehicles.dat", ios::binary);
    
    if (!inFile) {
        cerr << "No existing vehicle file found. Creating new one." << endl;
        return vehicles;
    }
    
    Vehicle vehicle;
    while (inFile.read(reinterpret_cast<char*>(&vehicle), sizeof(Vehicle))) {
        vehicles.push_back(vehicle);
    }
    inFile.close();
    return vehicles;
}

// Rental records file operations
void FileHandler::saveRentalRecords(const vector<RentalRecord>& records) {
    ofstream outFile("rental_records.dat", ios::binary);
    if (!outFile) {
        cerr << "Error opening file for writing rental records!" << endl;
        return;
    }
    
    for (const RentalRecord& record : records) {
        outFile.write(reinterpret_cast<const char*>(&record), sizeof(RentalRecord));
    }
    outFile.close();
}

vector<RentalRecord> FileHandler::loadRentalRecords() {
    vector<RentalRecord> records;
    ifstream inFile("rental_records.dat", ios::binary);
    
    if (!inFile) {
        cerr << "No existing rental records file found. Creating new one." << endl;
        return records;
    }
    
    RentalRecord record;
    while (inFile.read(reinterpret_cast<char*>(&record), sizeof(RentalRecord))) {
        records.push_back(record);
    }
    inFile.close();
    return records;
}
