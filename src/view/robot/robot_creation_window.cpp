#include "view/robot/robot_creation_window.hpp"

#include <FL/fl_ask.H>
#include <FL/Fl.H>
#include <FL/Fl_File_Chooser.H>
#include <sstream>

#include "controller/robot/robot_controller.hpp"
#include "rrs_io.hpp"
#include "rrs_error.hpp"

RobotCreationWindow::RobotCreationWindow() 
    : RrsWindow(415,665,"Robot"),  
    robotTypeLabel(350,30,90,30, "Enter/choose the following options:"), 
    robotName(125,60,150,30, "Robot Name:"),
    robotNumber(125, 95, 150, 30, "Robot Number:"),
    robotCost(125, 130, 90, 30, "Robot Cost:"),
    robotPicturePath(125, 165, 150, 30, "Picture:"),
    choosePictureButton(290, 165, 115, 30, "Choose Picture"),
    componentsTypeLabel(125, 200, 90, 30, "Choose at least one component:"),
    torsoChoice(125, 235, 90, 30, "Torso: "),
    headChoice(125, 270, 90, 30, "Head: "),
    armChoice1(125, 305, 90, 30, "Arm 1: "),
    armChoice2(125, 340, 90, 30, "Arm 2: "),
    locomotorChoice(125, 375, 90, 30, "Locomotor: "),
    batteryTypeLabel(325, 410, 90, 30, "Battery quantity is determined \nby Torso choice:"),
    batteryChoice1(125, 445, 90, 30, "Battery 1: "),
    batteryChoice2(125, 480, 90, 30, "Battery 2: "),
    batteryChoice3(125, 515, 90, 30, "Battery 3: "),
    createButton(100, 630, 90, 30, "Create"),
    cancelButton(225, 630, 90, 30, "Cancel") {

        robotTypeLabel.align(FL_ALIGN_LEFT);
        robotTypeLabel.labelfont(FL_BOLD);

        componentsTypeLabel.align(FL_ALIGN_LEFT);
        componentsTypeLabel.labelfont(FL_BOLD);

        torsoChoice.add("None");
        torsoChoice.value(0);

        headChoice.add("None");
        headChoice.value(0);

        armChoice1.add("None");
        armChoice1.value(0);
        armChoice2.add("None");
        armChoice2.value(0);

        locomotorChoice.add("None");
        locomotorChoice.value(0);

        batteryTypeLabel.align(FL_ALIGN_LEFT);
        batteryTypeLabel.labelfont(FL_BOLD);

        batteryChoice1.add("None");
        batteryChoice1.value(0);
        batteryChoice2.add("None");
        batteryChoice2.value(0);
        batteryChoice3.add("None");
        batteryChoice3.value(0);

        choosePictureButton.callback(ChoosePictureCallback, this); 
        createButton.callback(CreateRobotCallback, this);
        cancelButton.callback(WindowExitCallback, this);
        end();
    };

void RobotCreationWindow::ResetInputs() {
    robotName.value(NULL);
    robotNumber.value(NULL);
    robotCost.value(NULL);
}

inline void RobotCreationWindow::CreateRobot() {
    int error_code;
    RobotController controller{};
    std::unique_ptr<Robot> robot;
    error_code = controller.CreateRobot(robot, this);

    if (!error_code) {
         std::stringstream ss;
         ss << "Robot Created!" << std::endl <<std::endl << robot->ToString();
         hide();
         fl_message(ss.str().c_str());
    } 
    else {
        std::stringstream ss;
        ss << "Cannot create Robot! Invalid input!" << std::endl 
            << "Cannot have:" << std::endl << "\t1. Negative numbers"
            << std::endl << "\t2. More batteries than torso compartments.";
        fl_alert(ss.str().c_str());
    }
}

void RobotCreationWindow::CreateRobotCallback(Fl_Widget *w, void* v) {
    ((RobotCreationWindow*) v)->CreateRobot();
}

inline void RobotCreationWindow::ChoosePicture() {
    std::stringstream ss;
    Fl_File_Chooser chooser{".","*.png", Fl_File_Chooser::SINGLE, "Choose Robot Picture"};

    chooser.show();
    while(chooser.shown())
        Fl::wait();


    if ( chooser.value() == NULL ) { 
        fprintf(stderr, "(User hit 'Cancel')\n"); 
        return; 
    }


    ss << chooser.value();
    robotPicturePath.value(ss.str().c_str());
}

void RobotCreationWindow::ChoosePictureCallback(Fl_Widget *w, void* v) {
    ((RobotCreationWindow*) v)->ChoosePicture();
}

std::string RobotCreationWindow::GetPicturePath() const {
    return robotPicturePath.value();
}

void RobotCreationWindow::SetTorsoChoice(
        const std::vector<std::unique_ptr<Part>> &torsos) {
    torsoChoice.clear();
    torsoChoice.add("None");
    torsoChoice.value(0);

    for (const std::unique_ptr<Part> & part : torsos) {
        std::string tmp = std::to_string(part->GetPartNumber());
        torsoChoice.add(tmp.c_str());
    }
}

void RobotCreationWindow::SetHeadChoice(
        const std::vector<std::unique_ptr<Part>> &parts) {
    headChoice.clear();
    headChoice.add("None");
    headChoice.value(0);

    for (const std::unique_ptr<Part> & part : parts) {
        std::string tmp = std::to_string(part->GetPartNumber());
        headChoice.add(tmp.c_str());
    }
}

void RobotCreationWindow::SetArmChoice(
        const std::vector<std::unique_ptr<Part>> &parts) {
    armChoice1.clear();
    armChoice1.add("None");
    armChoice1.value(0);

    armChoice2.clear();
    armChoice2.add("None");
    armChoice2.value(0);

    for (const std::unique_ptr<Part> & part : parts) {
        std::string tmp = std::to_string(part->GetPartNumber());
        armChoice1.add(tmp.c_str());
        armChoice2.add(tmp.c_str());
    }
}

void RobotCreationWindow::SetLocomotorChoice(
        const std::vector<std::unique_ptr<Part>> &parts) {
    locomotorChoice.clear();
    locomotorChoice.add("None");
    locomotorChoice.value(0);

    for (const std::unique_ptr<Part> & part : parts) {
        std::string tmp = std::to_string(part->GetPartNumber());
        locomotorChoice.add(tmp.c_str());
    }
}

void RobotCreationWindow::SetBatteryChoice(
        const std::vector<std::unique_ptr<Part>> &parts) {
    batteryChoice1.clear();
    batteryChoice1.add("None");
    batteryChoice1.value(0);

    batteryChoice2.clear();
    batteryChoice2.add("None");
    batteryChoice2.value(0);

    batteryChoice3.clear();
    batteryChoice3.add("None");
    batteryChoice3.value(0);

    for (const std::unique_ptr<Part> & part : parts) {
        std::string tmp = std::to_string(part->GetPartNumber());
        batteryChoice1.add(tmp.c_str());
        batteryChoice2.add(tmp.c_str());
        batteryChoice3.add(tmp.c_str());
    }
}

std::string RobotCreationWindow::GetRobotName() const {
    return robotName.value();
}

std::string RobotCreationWindow::GetRobotNumber() const {
    return robotNumber.value();
}

std::string RobotCreationWindow::GetRobotCost() const {
    return robotCost.value();
}

std::string RobotCreationWindow::GetTorsoChoice() const {
    return torsoChoice.text();
}

std::string RobotCreationWindow::GetHeadChoice() const {
    return headChoice.text();
}

std::string RobotCreationWindow::GetArmChoiceOne() const {
    return armChoice1.text();
}

std::string RobotCreationWindow::GetArmChoiceTwo() const {
    return armChoice2.text();
}

std::string RobotCreationWindow::GetLocomotorChoice() const {
    return locomotorChoice.text();
}

std::string RobotCreationWindow::GetBatteryChoiceOne() const {
    return batteryChoice1.text();
}

std::string RobotCreationWindow::GetBatteryChoiceTwo() const {
    return batteryChoice2.text();
}

std::string RobotCreationWindow::GetBatteryChoiceThree() const {
    return batteryChoice3.text();
}

