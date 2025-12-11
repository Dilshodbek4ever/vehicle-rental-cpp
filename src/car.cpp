#include "car.h"

Car::Car(const std::string& id, const std::string& brand,
         const std::string& model, double pricePerDay, bool available)
    : Vehicle(id, brand, model, pricePerDay, available) {}

std::string Car::getType() const { return "Car"; }
