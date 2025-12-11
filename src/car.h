#ifndef CAR_H
#define CAR_H

#include "vehicle.h"

class Car : public Vehicle {
public:
    Car() {}
    Car(const std::string& id, const std::string& brand,
        const std::string& model, double pricePerDay, bool available = true);

    std::string getType() const override;
};

#endif
