#ifndef RRS_PART_VIEW_PART_CREATION_WINDOW_HPP_
#define RRS_PART_VIEW_PART_CREATION_WINDOW_HPP_

#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Spinner.H>
#include <FL/Fl_Multiline_Input.H>

class PartCreationWindow : public Fl_Window {
    public:
        PartCreationWindow();
    private:
        Fl_Box partTypeLabel;
        Fl_Input partName;
        Fl_Input partNumber;
        Fl_Input partWeight;
        Fl_Input partCost;
        Fl_Multiline_Input partDescription;
        Fl_Choice partType;        
        Fl_Box torsoTypeLabel;
        Fl_Spinner torsoBatteryCount;
        Fl_Box armTypeLabel;
        Fl_Input powerConsumedWatts; 
        Fl_Box locomotorTypeLabel;
        Fl_Input locomotorMaxSpeed;
        Fl_Input locomotorPowerUsedWatts;
        Fl_Box batteryTypeLabel;
        Fl_Input batteryEnergy;
        Fl_Button createButton;
        Fl_Button cancelButton;
};
#endif
