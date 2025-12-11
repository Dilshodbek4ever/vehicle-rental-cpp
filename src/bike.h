#ifndef BIKE_H
#define BIKE_H

#include "vehicle.h"

class Bike : public Vehicle {
public:
    Bike() {}
    Bike(const std::string& id, const std::string& brand,
         const std::string& model, double pricePerDay, bool available = true);

    std::string getType() const override;
};

#endif
