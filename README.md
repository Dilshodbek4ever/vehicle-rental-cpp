# Vehicle Rental System (C++ Project)

A simple console-based **Vehicle Rental System** built using C++ and Object-Oriented Programming (OOP).  
This project demonstrates the use of **classes, inheritance, polymorphism, abstraction, encapsulation, file handling, and modular programming**.

---

## Project Structure

project/
│
├── src/
│ ├── main.cpp
│ ├── vehicle.cpp
│ ├── car.cpp
│ ├── bike.cpp
│ ├── truck.cpp
│ ├── rentalmanager.cpp
│ ├── vehicle.h
│ ├── car.h
│ ├── bike.h
│ ├── truck.h
│ └── rentalmanager.h
│
├── data/
│ ├── vehicles.txt
│ └── history.txt
│
└── rental.exe


---

## Features

### ✔ Vehicle Management
- Add new vehicles (Car, Bike, Truck)
- View all vehicles
- View available vehicles
- View rented vehicles
- Filter vehicles by type

### ✔ Rental Operations
- Rent a vehicle
- Return a vehicle
- Display total cost
- Prevent renting unavailable vehicles

### ✔ Rental History
- Show all past rental events
- History is stored during runtime

### ✔ OOP Concepts
- **Inheritance:** Car, Bike, Truck → Vehicle  
- **Polymorphism:** virtual `display()` method  
- **Encapsulation:** private members with getters/setters  
- **Abstraction:** RentalManager controls all operations  
- **Modular Programming:** separate headers and source files

---

## Compilation (Using g++)

If your files are inside **src/**, use this command:

```bash
g++ -o rental.exe src/main.cpp src/vehicle.cpp src/car.cpp src/bike.cpp src/truck.cpp src/rentalmanager.cpp

This will generate the executable:

rental.exe


Make sure you run it from the project root folder:

rental.exe


This is required so the program can find the files in data/.

Data Files

Your program reads and writes data from:

data/vehicles.txt
data/history.txt


Ensure these files exist before running the program.

How to Use

Run the executable:

rental.exe


Choose from the menu:

====== Vehicle Rental System ======
1. Add Vehicle
2. Show All Vehicles
3. Show Available Vehicles
4. Show Rented Vehicles
5. Show Vehicles by Type
6. Rent Vehicle
7. Return Vehicle
8. Rental History
9. Exit


Follow the on-screen instructions.

License
This project is created for educational purposes and can be freely used or modified.
