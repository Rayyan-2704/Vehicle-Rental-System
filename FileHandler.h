#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <conio.h>
#include <cstdlib>
#include <fstream>

#include "Admin.h"
#include "Customer.h"
#include "Car.h"
#include "Bike.h"
#include "Truck.h"
#include "Booking.h"
#include "TerminalControl.h"
using namespace std;

class FileHandler
{
    ifstream inputFile;
    ofstream outputFile;

public:
    FileHandler();

    void loadAdminData(vector <Admin*> &admins, const string &fileName);
    void writeAdminData(vector <Admin*> &admins, const string &fileName);
    void loadCustomerData(vector <Customer*> &customers, const string &fileName);
    void writeCustomerData(vector <Customer*> &customers, const string &fileName);
    void loadVehiclesData(vector <Vehicle*> &inventory, const string &fileName);
    void writeVehiclesData(vector <Vehicle*> &inventory, const string &fileName);
    void loadBookingsData(vector <Customer*> &customers, const string &fileName);
    void writeBookingsData(vector <Customer*> &customers, const string &fileName);

    ~FileHandler();
};

#endif