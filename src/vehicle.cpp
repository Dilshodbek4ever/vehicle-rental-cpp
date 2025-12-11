#include "vehicle.h"
#include "car.h"
#include "bike.h"
#include "truck.h"
#include <sstream>
#include <iostream>
#include <vector>

Vehicle::Vehicle(const std::string& id, const std::string& brand,
                 const std::string& model, double pricePerDay, bool available)
    : id(id), brand(brand), model(model), pricePerDay(pricePerDay), available(available) {}

std::string Vehicle::getId() const { return id; }
std::string Vehicle::getBrand() const { return brand; }
std::string Vehicle::getModel() const { return model; }
double Vehicle::getPricePerDay() const { return pricePerDay; }
bool Vehicle::isAvailable() const { return available; }

void Vehicle::setAvailable(bool val) { available = val; }

void Vehicle::displayShort() const {
    std::cout << "ID:" << id
              << " | Type:" << getType()
              << " | Brand:" << brand
              << " | Model:" << model
              << " | Price/day:" << pricePerDay
              << " | " << (available ? "Available" : "Rented") << "\n";
}

std::string Vehicle::serialize() const {
    std::stringstream ss;
    ss << getType() << "|" << id << "|" << brand << "|" << model
       << "|" << pricePerDay << "|" << (available ? "1" : "0");
    return ss.str();
}

std::shared_ptr<Vehicle> Vehicle::deserialize(const std::string& line) {
    std::stringstream ss(line);
    std::string token;
    std::vector<std::string> parts;

    while (std::getline(ss, token, '|')) parts.push_back(token);

    if (parts.size() < 6) return nullptr;

    std::string type = parts[0];
    std::string id = parts[1];
    std::string brand = parts[2];
    std::string model = parts[3];
    double price = std::stod(parts[4]);
    bool avail = (parts[5] == "1");

    if (type == "Car") return std::make_shared<Car>(id, brand, model, price, avail);
    if (type == "Bike") return std::make_shared<Bike>(id, brand, model, price, avail);
    if (type == "Truck") return std::make_shared<Truck>(id, brand, model, price, avail);

    return nullptr;
}
