#ifndef RRS_VIEW_ROBOT_ROBOT_CREATION_WINDOW_HPP_
#define RRS_VIEW_ROBOT_ROBOT_CREATION_WINDOW_HPP_

#include <string>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Float_Input.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Button.H>

#include <memory>
#include <vector>

#include "view/rrs/rrs_window.hpp"
#include "model/part/part.hpp"

class RobotCreationWindow : public RrsWindow {
    public:
        RobotCreationWindow();
        void SetTorsoChoice(const std::vector<std::unique_ptr<Part>> &torsos);
        void SetHeadChoice(const std::vector<std::unique_ptr<Part>> &parts);
        void SetArmChoice(const std::vector<std::unique_ptr<Part>> &parts);
        void SetLocomotorChoice(const std::vector<std::unique_ptr<Part>> &parts);
        void SetBatteryChoice(const std::vector<std::unique_ptr<Part>> &parts);
        std::string GetTorsoChoice() const;
        std::string GetHeadChoice() const;
        std::string GetArmChoiceOne() const;
        std::string GetArmChoiceTwo() const;
        std::string GetLocomotorChoice() const;
        std::string GetBatteryChoiceOne() const;
        std::string GetBatteryChoiceTwo() const;
        std::string GetBatteryChoiceThree() const;
        std::string GetRobotName() const;
        std::string GetRobotNumber() const;
        std::string GetRobotCost() const;
    private:
        Fl_Box robotTypeLabel;
        Fl_Input robotName;
        Fl_Int_Input robotNumber;
        Fl_Float_Input robotCost;
        Fl_Box componentsTypeLabel;
        Fl_Choice torsoChoice;
        Fl_Choice headChoice;
        Fl_Choice armChoice1;
        Fl_Choice armChoice2;
        Fl_Choice locomotorChoice;
        Fl_Box batteryTypeLabel;
        Fl_Choice batteryChoice1;
        Fl_Choice batteryChoice2;
        Fl_Choice batteryChoice3;
        Fl_Button createButton;
        Fl_Button cancelButton;
        void CreateRobot();
        static void CreateRobotCallback(Fl_Widget *w, void* v);
};
#endif
