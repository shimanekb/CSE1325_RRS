#include "part/view/part_creation_window.hpp"

PartCreationWindow::PartCreationWindow() 
    : Fl_Window(400,665,"Part"),  
    partTypeLabel(325,30,90,30, "Enter/choose the following options:"), 
    partName(100,60,150,30, "Part Name:"),
    partNumber(100, 95, 150, 30, "Part Number:"),
    partWeight(100, 130, 90, 30, "Part Weight:"),
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

        armTypeLabel.align(FL_ALIGN_LEFT);
        armTypeLabel.labelfont(FL_BOLD);

        locomotorTypeLabel.align(FL_ALIGN_LEFT);
        locomotorTypeLabel.labelfont(FL_BOLD);

        batteryTypeLabel.align(FL_BOLD);
        batteryTypeLabel.labelfont(FL_BOLD);

        end();
    };
