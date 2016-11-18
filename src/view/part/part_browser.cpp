#include "view/part/part_browser.hpp"

#include <sstream>
#include <FL/Fl.H>

#include "model/part/torso.hpp"
#include "model/part/arm.hpp"
#include "model/part/battery.hpp"
#include "model/part/locomotor.hpp"
#include "model/part/part.hpp"

PartBrowser::PartBrowser(int x, int y, int w, int h) 
    : RrsBrowser(x, y, w, h) {
        std::stringstream ss{}; 
        column_widths(widths);
        type(FL_MULTI_BROWSER);

        ss << "@bPART NUMBER\t@bNAME\t@bCOST\t@bTYPE\t@bWEIGHT\t@bPOWER CONSUMED"
            << "\t@bKILOWATT HOURS\t@bMAX MPH\t@bBATTERY SIZE\t@bDESCRIPTION";
        add(ss.str().c_str());

        end();
}

int PartBrowser::AddPart(const std::unique_ptr<Part> &part) {
    std::stringstream ss{}; 
    ss << part->GetPartNumber() << "\t" << part->GetName() << "\t"
        << part->GetCost() << "\t" << part->GetPartTypeString() << "\t"
        << part->GetWeight();


    ss << FormatPartDetails(part);

    add(ss.str().c_str());

    return 0;
}

std::string PartBrowser::FormatPartDetails(const std::unique_ptr<Part> &part) {
    std::stringstream ss{}; 
    Part::PartType type = part->GetPartType();
    Part *tmpPart = part->Clone();
        
    if (Part::PartType::TORSO == type) {
        Torso *torso = static_cast<Torso*>(tmpPart);
        ss << "\tNONE\tNONE\tNONE\t" << torso->GetBatteryCompartmentSize()
            << "\t" << torso->GetDescription();
    }
    else if (Part::PartType::HEAD == type) {
        ss << "\tNONE\tNONE\tNONE\tNONE\t" <<  part->GetDescription();
    }
    else if (Part::PartType::LOCOMOTOR == type) {
        Locomotor *locomotor = static_cast<Locomotor*>(tmpPart);
        ss << "\t" << locomotor->GetPowerConsumedWatts() << "\tNONE\t"
            << locomotor->GetMaxMphSpeed() << "\tNONE\t" 
            << locomotor->GetDescription();
    }
    else if (Part::PartType::ARM == type) {
        Arm *arm = static_cast<Arm*>(tmpPart);
        ss << "\t" << arm->GetPowerConsumedWatts() << "\tNONE\tNONE\tNONE\t"
            << arm->GetDescription();
    }
    else if (Part::PartType::BATTERY == type) {
        Battery *battery = static_cast<Battery*>(tmpPart);
        ss << "\tNONE\t" << battery->GetKilowattHours() << "\tNONE\tNONE\t"
            << battery->GetDescription();
    }

    delete tmpPart;

    return ss.str();
}
