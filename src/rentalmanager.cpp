#include "rentalManager.h"
#include "car.h"
#include "bike.h"
#include "truck.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

RentalManager::RentalManager() {
    loadFromFile();
}

RentalManager::~RentalManager() {
    saveToFile();
}

bool RentalManager::idExists(const std::string& id) const {
    for (auto& v : vehicles)
        if (v->getId() == id) return true;
    return false;
}

void RentalManager::addVehicle(const shared_ptr<Vehicle>& v) {
    vehicles.push_back(v);
    cout << v->getType() << " added successfully!\n";

    history.push_back(currentTimestamp() + " | Added vehicle: " + v->getId());
}

void RentalManager::showAll() const {
    if (vehicles.empty()) {
        cout << "No vehicles.\n";
        return;
    }
    for (auto& v : vehicles) {
        v->displayShort();
        cout << "--------------------------------------------\n";
    }
}

void RentalManager::showAvailable() const {
    bool any = false;
    for (auto& v : vehicles) {
        if (v->isAvailable()) {
            v->displayShort();
            any = true;
        }
    }
    if (!any) cout << "No available vehicles.\n";
}

void RentalManager::showRented() const {
    bool any = false;
    for (auto& v : vehicles) {
        if (!v->isAvailable()) {
            v->displayShort();
            any = true;
        }
    }
    if (!any) cout << "No rented vehicles.\n";
}

void RentalManager::showByType(const string& type) const {
    bool any = false;
    for (auto& v : vehicles) {
        if (v->getType() == type) {
            v->displayShort();
            any = true;
        }
    }
    if (!any) cout << "No vehicles of type " << type << "\n";
}

shared_ptr<Vehicle> RentalManager::findById(const string& id) const {
    for (auto& v : vehicles)
        if (v->getId() == id) return v;
    return nullptr;
}

void RentalManager::rentVehicle(const string& id, int days) {
    auto v = findById(id);
    if (!v) {
        cout << "Vehicle not found.\n";
        return;
    }
    if (!v->isAvailable()) {
        cout << "Vehicle already rented.\n";
        return;
    }

    double total = days * v->getPricePerDay();
    v->setAvailable(false);

    cout << "Vehicle rented! Total cost: $" << fixed << setprecision(2) << total << "\n";

    stringstream ss;
    ss << currentTimestamp() << " | Rented " << id << " for " << days << " days.";
    history.push_back(ss.str());
}

void RentalManager::returnVehicle(const string& id) {
    auto v = findById(id);
    if (!v) {
        cout << "Vehicle not found.\n";
        return;
    }
    if (v->isAvailable()) {
        cout << "Vehicle was not rented.\n";
        return;
    }

    v->setAvailable(true);
    cout << "Vehicle returned.\n";

    history.push_back(currentTimestamp() + " | Returned " + id);
}

void RentalManager::showHistory() const {
    if (history.empty()) {
        cout << "No rental history.\n";
        return;
    }
    for (auto& h : history) cout << h << "\n";
}

string RentalManager::currentTimestamp() const {
    auto t = time(nullptr);
    tm tmTime{};
#if defined(_WIN32) || defined(_WIN64)
    localtime_s(&tmTime, &t);
#else
    localtime_r(&t, &tmTime);
#endif
    stringstream ss;
    ss << put_time(&tmTime, "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

void RentalManager::saveToFile() {
    ofstream vf(vehiclesFile);
    for (auto& v : vehicles) vf << v->serialize() << "\n";
    vf.close();

    ofstream hf(historyFile);
    for (auto& h : history) hf << h << "\n";
    hf.close();
}

void RentalManager::loadFromFile() {
    vehicles.clear();
    history.clear();

    ifstream vf(vehiclesFile);
    string line;
    while (getline(vf, line)) {
        if (!line.empty()) {
            auto v = Vehicle::deserialize(line);
            if (v) vehicles.push_back(v);
        }
    }
    vf.close();

    ifstream hf(historyFile);
    while (getline(hf, line)) {
        if (!line.empty()) history.push_back(line);
    }
    hf.close();
}
