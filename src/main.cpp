#include <iostream>
#include <string>

#include "rentalManager.h"
#include "car.h"
#include "bike.h"
#include "truck.h"

using namespace std;

int getInt(const string& msg) {
    cout << msg;
    int x;
    cin >> x;
    cin.ignore();
    return x;
}

string getStr(const string& msg) {
    cout << msg;
    string s;
    getline(cin, s);
    return s;
}

void showMenu() {
    cout << "\n====== Vehicle Rental System ======\n";
    cout << "1. Add Vehicle\n";
    cout << "2. Show All Vehicles\n";
    cout << "3. Show Available Vehicles\n";
    cout << "4. Show Rented Vehicles\n";
    cout << "5. Show Vehicles by Type\n";
    cout << "6. Rent Vehicle\n";
    cout << "7. Return Vehicle\n";
    cout << "8. Rental History\n";
    cout << "9. Exit\n";
}

int main() {
    RentalManager manager;

    while (true) {
        showMenu();
        int choice = getInt("Enter choice: ");

        if (choice == 1) {
            cout << "Select Type:\n1. Car\n2. Bike\n3. Truck\n";
            int t = getInt("Choice: ");

            string id = getStr("ID: ");
            string brand = getStr("Brand: ");
            string model = getStr("Model: ");
            double price = stod(getStr("Price per day: "));

            if (t == 1)
                manager.addVehicle(make_shared<Car>(id, brand, model, price));
            else if (t == 2)
                manager.addVehicle(make_shared<Bike>(id, brand, model, price));
            else if (t == 3)
                manager.addVehicle(make_shared<Truck>(id, brand, model, price));
            else
                cout << "Invalid type!\n";
        }

        else if (choice == 2) manager.showAll();
        else if (choice == 3) manager.showAvailable();
        else if (choice == 4) manager.showRented();

        else if (choice == 5) {
            cout << "1.Car  2.Bike  3.Truck\n";
            int t = getInt("Choice: ");

            if (t == 1) manager.showByType("Car");
            else if (t == 2) manager.showByType("Bike");
            else if (t == 3) manager.showByType("Truck");
            else cout << "Invalid choice\n";
        }

        else if (choice == 6) {
            string id = getStr("Enter ID to rent: ");
            int days = getInt("Days: ");
            manager.rentVehicle(id, days);
        }

        else if (choice == 7) {
            string id = getStr("Enter ID to return: ");
            manager.returnVehicle(id);
        }

        else if (choice == 8) manager.showHistory();

        else if (choice == 9) {
            cout << "Exiting...\n";
            break;
        }

        else cout << "Invalid option!\n";
    }

    return 0;
}
