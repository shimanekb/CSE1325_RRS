#ifndef PART_HPP_
#define PART_HPP_

#include <string>

class Part {
    public:
        enum class PartType {
            TORSO,
            HEAD,
            ARM,
            LOCOMOTOR,
            BATTERY
        };
        Part(const std::string name, const int part_number, const double weight,
                const double cost, std::string description,
                const Part::PartType part_type);
        std::string GetName() const;
        int GetPartNumber() const;
        double GetWeight() const;
        double GetCost() const;
        std::string GetDescription() const;
        std::string GetPartTypeString() const;
        Part::PartType GetPartType() const;
        virtual std::string ToString() const = 0;
    private:
        const std::string kName;
        const int kPartNumber;
        const double kWeight;
        const double kCost;
        const std::string kDescription;
        const Part::PartType kPartType;
};
#endif
