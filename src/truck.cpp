#include "truck.h"

Truck::Truck(const std::string& id, const std::string& brand,
             const std::string& model, double pricePerDay, bool available)
    : Vehicle(id, brand, model, pricePerDay, available) {}

std::string Truck::getType() const { return "Truck"; }
