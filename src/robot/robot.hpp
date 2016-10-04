#ifndef RRS_ROBOT_ROBOT_HPP_
#define RRS_ROBOT_ROBOT_HPP_

#include <vector>
#include <memory>
#include <string>
#include "part.hpp"

class Robot {
    public:
        Robot(const std::string name, const int model_number, const double price);
        const std::vector<std::unique_ptr<const Part>> GetParts() const;
        std::string GetName() const;
        int GetModelNumber() const;
        double GetPrice() const; 
    private:
        std::vector<std::unique_ptr<const Part>> parts;
        const std::string kName;
        const int kModelNumber;
        const double kPrice;
};
#endif
