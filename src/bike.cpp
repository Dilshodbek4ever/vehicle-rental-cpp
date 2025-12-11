#include "bike.h"

Bike::Bike(const std::string& id, const std::string& brand,
           const std::string& model, double pricePerDay, bool available)
    : Vehicle(id, brand, model, pricePerDay, available) {}

std::string Bike::getType() const { return "Bike"; }
