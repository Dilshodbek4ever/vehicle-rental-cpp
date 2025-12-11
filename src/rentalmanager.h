#ifndef RENTAL_MANAGER_H
#define RENTAL_MANAGER_H

#include <vector>
#include <memory>
#include <string>

#include "vehicle.h"

class RentalManager {
private:
    std::vector< std::shared_ptr<Vehicle> > vehicles;
    std::vector<std::string> history;

    std::string currentTimestamp() const;

    void loadFromFile();
    void saveToFile();

    const std::string vehiclesFile = "data/vehicles.txt";
    const std::string historyFile  = "data/history.txt";

public:
    RentalManager();
    ~RentalManager();

    bool idExists(const std::string& id) const;
    void addVehicle(const std::shared_ptr<Vehicle>& v);

    void showAll() const;
    void showAvailable() const;
    void showRented() const;

    void showByType(const std::string& type) const;

    std::shared_ptr<Vehicle> findById(const std::string& id) const;

    void rentVehicle(const std::string& id, int days);
    void returnVehicle(const std::string& id);

    void showHistory() const;
};

#endif
