#ifndef PART_
#define PART_

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
        std::string GetName();
        int GetPartNumber();
        double GetWeight();
        double GetCost();
        std::string GetDescription();
        Part::PartType GetPartType();
    private:
        const std::string kName;
        const int kPartNumber;
        const double kWeight;
        const double kCost;
        const std::string kDescription;
        const Part::PartType kPartType;
};
#endif
