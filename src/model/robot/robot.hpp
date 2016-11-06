#ifndef RRS_MODEL_ROBOT_ROBOT_HPP_
#define RRS_MODEL_ROBOT_ROBOT_HPP_

#include <vector>
#include <memory>
#include <string>

#include "model/part/part.hpp"

class Robot {
    public:
        Robot(const std::string name, const int model_number, const double price);
        const std::vector<std::unique_ptr<Part>>& GetParts() const;
        std::string GetName() const;
        int GetModelNumber() const;
        double GetPrice() const; 
        bool AddPart(std::unique_ptr<Part> part);
        std::string ToString() const;
        std::unique_ptr<Robot> GetCopy() const;
        Robot* Clone() const;
    private:
        int ValidatePart(const Part &part);
        std::vector<std::unique_ptr<Part>> parts;
        const std::string kName;
        const int kModelNumber;
        const double kPrice;
};
#endif
