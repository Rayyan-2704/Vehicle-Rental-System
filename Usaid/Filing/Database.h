#include <string>
#include "Vehicle.h"
#include "Customer.h"
#include "Rental.h"

class Database {
public:
    static void initialize();
    static void cleanup();
    
    static void saveAllData();
    static void loadAllData();
    
    static std::vector<Vehicle> vehicles;
    static std::vector<Customer> customers;
    static std::vector<Rental> rentals;
    
private:
    static const std::string VEHICLE_FILE;
    static const std::string CUSTOMER_FILE;
    static const std::string RENTAL_FILE;
};
