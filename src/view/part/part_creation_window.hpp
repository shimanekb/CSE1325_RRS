#ifndef RRS_VIEW_PART_PART_CREATION_WINDOW_HPP_
#define RRS_VIEW_PART_PART_CREATION_WINDOW_HPP_

#include <string>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Float_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Spinner.H>
#include <FL/Fl_Multiline_Input.H>

#include "view/rrs/rrs_window.hpp"

class PartCreationWindow : public RrsWindow {
    public:
        PartCreationWindow();
        std::string GetPartName() const;
        std::string GetPartNumber() const;
        std::string GetPartWeight() const;
        std::string GetPartCost() const;
        std::string GetPartDescription() const;
        int GetPartTypeIndex() const;
        int GetTorsoBatteryCount() const;
        std::string GetArmPowerConsumedWatts() const;
        std::string GetLocomotorMaxSpeed() const;
        std::string GetLocomotorPowerConsumedWatts() const;
        std::string GetBatteryEnergy() const;
        void ResetInputs();
    private:
        Fl_Box partTypeLabel;
        Fl_Input partName;
        Fl_Int_Input partNumber;
        Fl_Float_Input partWeight;
        Fl_Float_Input partCost;
        Fl_Multiline_Input partDescription;
        Fl_Choice partType;        
        Fl_Box torsoTypeLabel;
        Fl_Spinner torsoBatteryCount;
        Fl_Box armTypeLabel;
        Fl_Float_Input powerConsumedWatts; 
        Fl_Box locomotorTypeLabel;
        Fl_Float_Input locomotorMaxSpeed;
        Fl_Float_Input locomotorPowerUsedWatts;
        Fl_Box batteryTypeLabel;
        Fl_Float_Input batteryEnergy;
        Fl_Button createButton;
        Fl_Button cancelButton;
        void CreatePart();
        static void CreatePartCallback(Fl_Widget *w, void* v);
};
#endif
