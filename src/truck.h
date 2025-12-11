#ifndef TRUCK_H
#define TRUCK_H

#include "vehicle.h"

class Truck : public Vehicle {
public:
    Truck() {}
    Truck(const std::string& id, const std::string& brand,
          const std::string& model, double pricePerDay, bool available = true);

    std::string getType() const override;
};

#endif
