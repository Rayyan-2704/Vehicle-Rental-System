# 🚗 Vehicle Rental System

A C++ Object-Oriented Programming (OOP) project that simulates a **vehicle rental management system**.

This console-based system allows **admins** to manage a fleet of vehicles, while **customers** can rent vehicles like **cars, bikes, and trucks**.

---

## 📌 Key Features

* 🚘 **View available vehicles** by category (Car, Bike, Truck)
* 📆 **Customers can rent vehicles** for a specific number of days
* 🛠️ **Admins can add and remove vehicles** from the inventory
* 🧾 **Generate and view bookings** with unique IDs and cost
* 📂 **CSV File Handling** for persistent storage
* 🔐 **Separate Admin and Customer roles**
* 🎨 **Terminal formatting** for better UI experience

---

## 🧩 Object-Oriented Design Principles Used

* ✅ **Abstraction** (Simplified interaction through high-level interfaces)
* ✅ **Encapsulation** (Private data with getters/setters)
* ✅ **Inheritance** (`Car`, `Bike`, `Truck` inherit from `Vehicle` & `Admin`, `Customer` inherit from `User`)
* ✅ **Polymorphism** (Virtual methods for runtime behavior)
* ✅ **Association (Composition)** (Each `Customer` object has a `bookings` vector representing a strong ownership relationship)
* ✅ **Operator Overloading** (`<<` overloaded to display vehicles information)
* ✅ **Friend Function** (Access control for operator overloading)
* ✅ **File Handling** (Persistent data via CSV files)
* ✅ **Static Members** (Unique ID counters)
* ✅ **STL - Standard Template Library** (Vectors are used for efficient dynamic memory management)

---

## 🏗️ System Structure

```bash
📁 Vehicle-Rental-System/
├── main.cpp # Entry point of the application
├── FileHandler.cpp/.h # Handles all CSV file operations
├── TerminalControl.cpp/.h # Console UI styling and formatting
├── Vehicle.cpp/.h # Base Vehicle class
├── Car.cpp/.h # Derived class for Car
├── Bike.cpp/.h # Derived class for Bike
├── Truck.cpp/.h # Derived class for Truck
├── Booking.cpp/.h # Booking class for vehicle rentals
├── User.cpp/.h # Base User class
├── Admin.cpp/.h # Derived class for admin functionalities
├── Customer.cpp/.h # Derived class for customer functionalities
├── bookings.csv # Stores all bookings
├── vehicles.csv # Stores vehicle inventory
├── admins.csv # Stores admin data
├── customers.csv # Stores customers data
```

---

## ⚙️ How to Run

1. Clone the repository:
 ```bash
git clone https://github.com/Rayyan-2704/Vehicle-Rental-System.git
cd Vehicle-Rental-System
```

2. Compile all source files:
``` bash
g++ main.cpp TerminalControl.cpp FileHandler.cpp Vehicle.cpp Car.cpp Bike.cpp Truck.cpp Booking.cpp User.cpp Admin.cpp Customer.cpp -o VehicleRentalSystem.exe
```

3. Run the program:
```bash
.\VehicleRentalSystem.exe
```

---

## 💻 Requirements

- C++11 or above
- `g++` compiler (or any standard C++ compiler)
- Terminal / Command-line environment
- Text editor or IDE (e.g., VS Code, CLion)

---

## 👥 Group Members

- [Rayyan Aamir [24K-0687]](https://github.com/Rayyan-2704)
- [Usaid Khan [24K-0832]](https://github.com/MuhammadUsaidKhan)
- [Hammad Haider [24K-0634]](https://github.com/Syed-Hammad-Haider)
