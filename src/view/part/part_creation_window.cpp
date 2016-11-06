#include "view/part/part_creation_window.hpp"

#include <FL/fl_ask.H>
#include <memory>
#include <sstream>

#include "controller/part/part_controller.hpp"
#include "model/part/part.hpp"
#include "rrs_io.hpp"
#include "rrs_error.hpp"

PartCreationWindow::PartCreationWindow() 
    : RrsWindow(400,665,"Part"),  
    partTypeLabel(325,30,90,30, "Enter/choose the following options:"), 
    partName(100,60,150,30, "Part Name:"),
    partNumber(100, 95, 150, 30, "Part Number:"), partWeight(100, 130, 90, 30, "Part Weight:"),
    partCost(100, 165, 90, 30, "Part Cost:"),
    partDescription(100, 200, 250, 60, "Description:"),
    partType(100, 265, 150, 30, "Part Type:"),
    torsoTypeLabel(200, 300, 90, 30, "Enter if Torso chosen:"),
    torsoBatteryCount(100, 335, 90, 30, "Battery size:"),
    armTypeLabel(195, 370, 90, 30, "Enter if Arm chosen:"),
    powerConsumedWatts(100, 405, 90, 30, "Power used:"),
    locomotorTypeLabel(250, 440, 90, 30, "Enter if Locomotor chosen:"),
    locomotorMaxSpeed(100, 475, 90, 30, "Max speed:"),
    locomotorPowerUsedWatts(100, 510, 90, 30, "Power used:"),
    batteryTypeLabel(80, 565, 90, 30, "Enter if Battery chosen:"),
    batteryEnergy(100, 580, 90, 30, "Energy held:"),
    createButton(100, 630, 90, 30, "Create"),
    cancelButton(225, 630, 90, 30, "Cancel"){

        partTypeLabel.align(FL_ALIGN_LEFT);
        partTypeLabel.labelfont(FL_BOLD);

        partType.add("Torso");
        partType.add("Head");
        partType.add("Arm");
        partType.add("Locomotor");
        partType.add("Battery");

        torsoTypeLabel.align(FL_ALIGN_LEFT);
        torsoTypeLabel.labelfont(FL_BOLD);

        torsoBatteryCount.maximum(3);
        torsoBatteryCount.minimum(1);

        armTypeLabel.align(FL_ALIGN_LEFT);
        armTypeLabel.labelfont(FL_BOLD);

        locomotorTypeLabel.align(FL_ALIGN_LEFT);
        locomotorTypeLabel.labelfont(FL_BOLD);

        batteryTypeLabel.align(FL_BOLD);
        batteryTypeLabel.labelfont(FL_BOLD);

        createButton.callback(CreatePartCallback, this);
        cancelButton.callback(WindowExitCallback, this);
        end();
    };

inline void PartCreationWindow::CreatePart() {
    int error_code;
    PartController controller{};
    std::unique_ptr<Part> part;
    error_code = controller.CreatePart(part, this);

    if (!error_code) {
         std::stringstream ss;
         ss << "Part Created!" << std::endl <<std::endl << part->ToString();
         hide();
         fl_message(ss.str().c_str());
    } 
    else {
        std::stringstream ss;
        ss << "Cannot create Part! Invalid input!" << std::endl 
            << "Cannot have:" << std::endl << "\t1. Negative numbers"
            << std::endl << "\t2. Empty input for chosen part type.";
        fl_alert(ss.str().c_str());
    }
}

void PartCreationWindow::CreatePartCallback(Fl_Widget *w, void* v) {
    ((PartCreationWindow*) v)->CreatePart();
}

std::string PartCreationWindow::GetPartName() const {
    return partName.value();
}

std::string PartCreationWindow::GetPartNumber() const {
    return partNumber.value();
}

std::string PartCreationWindow::GetPartWeight() const {
    return partWeight.value();
}

std::string PartCreationWindow::GetPartCost() const {
    return partCost.value();
}

std::string PartCreationWindow::GetPartDescription() const {
   return partDescription.value(); 
}

int PartCreationWindow::GetPartTypeIndex() const {
    return partType.value();
}

int PartCreationWindow::GetTorsoBatteryCount() const {
    return torsoBatteryCount.value();
}

std::string PartCreationWindow::GetArmPowerConsumedWatts() const {
    return powerConsumedWatts.value();
}

std::string PartCreationWindow::GetLocomotorMaxSpeed() const {
    return locomotorMaxSpeed.value();
}

std::string PartCreationWindow::GetLocomotorPowerConsumedWatts() const {
    return locomotorPowerUsedWatts.value();
}

std::string PartCreationWindow::GetBatteryEnergy() const {
    return batteryEnergy.value();
}

