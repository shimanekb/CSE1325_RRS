#ifndef RRS_PART_PART_VIEW_HPP_
#define RRS_PART_PART_VIEW_HPP_

#include <memory>
#include <vector>
#include "part.hpp"

class PartView {
    public:
        void AskPartType();
        void AskPartName();
        void AskPartNumber();
        void AskPartWeight();
        void AskPartCost();
        void AskPartDescription();
        void AskForKiloWattHours();
        void AskForPowerConsumedWatts();
        void AskForMaxMphSpeed();
        void AskForBatteryCompartmentSize();
        void DisplayPart(std::unique_ptr<Part> const &part);
        void DisplayParts(std::vector<std::unique_ptr<Part>> const &parts);
};

#endif
