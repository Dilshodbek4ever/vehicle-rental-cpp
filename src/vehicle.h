#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <memory>

class Vehicle {
protected:
    std::string id;
    std::string brand;
    std::string model;
    double pricePerDay;
    bool available;

public:
    Vehicle() {}
    Vehicle(const std::string& id, const std::string& brand,
            const std::string& model, double pricePerDay, bool available = true);

    virtual ~Vehicle() {}

    std::string getId() const;
    std::string getBrand() const;
    std::string getModel() const;
    double getPricePerDay() const;
    bool isAvailable() const;

    void setAvailable(bool val);

    virtual std::string getType() const = 0;
    virtual void displayShort() const;

    virtual std::string serialize() const;
    static std::shared_ptr<Vehicle> deserialize(const std::string& line);
};

#endif
