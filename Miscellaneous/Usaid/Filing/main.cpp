#include <iostream>
#include <vector>
#include <cstdlib> // for exit()
#include "Admin.h"
#include "Customer.h"
#include "Vehicle.h"
#include "FileHandler.h"

using namespace std;

// ... (all your existing functions remain exactly the same)

void saveAllData(const vector<Admin>& admins, 
                const vector<Customer>& customers,
                const vector<Vehicle>& vehicles,
                const vector<RentalRecord>& records) {
    FileHandler::saveAdmins(admins);
    FileHandler::saveCustomers(customers);
    FileHandler::saveVehicles(vehicles);
    FileHandler::saveRentalRecords(records);
}

int main() {
    // Load data at startup
    vector<Admin> admins = FileHandler::loadAdmins();
    vector<Customer> customers = FileHandler::loadCustomers();
    vector<Vehicle> vehicles = FileHandler::loadVehicles();
    vector<RentalRecord> rentalRecords = FileHandler::loadRentalRecords();

    // ... (your existing main menu code)

    // Example of adding save points in menu options:
    while (true) {
        int choice = displayMainMenu();
        switch (choice) {
            case 1: // Admin login
                if (adminLogin(admins)) {
                    int adminChoice;
                    do {
                        adminChoice = displayAdminMenu();
                        switch (adminChoice) {
                            case 1: // Add Vehicle
                                // ... existing code
                                FileHandler::saveVehicles(vehicles); // Save after modification
                                break;
                            case 2: // Remove Vehicle
                                // ... existing code
                                FileHandler::saveVehicles(vehicles);
                                break;
                            // ... other cases
                            case 8: // Exit
                                saveAllData(admins, customers, vehicles, rentalRecords);
                                exit(0); // Or return 0;
                        }
                    } while (adminChoice != 8);
                }
                break;
                
            case 2: // Customer login
                if (customerLogin(customers)) {
                    int customerChoice;
                    do {
                        customerChoice = displayCustomerMenu();
                        switch (customerChoice) {
                            case 1: // Rent vehicle
                                // ... existing code
                                FileHandler::saveVehicles(vehicles);
                                FileHandler::saveRentalRecords(rentalRecords);
                                break;
                            case 2: // Return vehicle
                                // ... existing code
                                FileHandler::saveVehicles(vehicles);
                                FileHandler::saveRentalRecords(rentalRecords);
                                break;
                            // ... other cases
                            case 5: // Exit
                                saveAllData(admins, customers, vehicles, rentalRecords);
                                exit(0);
                        }
                    } while (customerChoice != 5);
                }
                break;
                
            case 3: // Exit program
                saveAllData(admins, customers, vehicles, rentalRecords);
                exit(0);
                
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
