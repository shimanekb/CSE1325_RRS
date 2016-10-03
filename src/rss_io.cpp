#include <iostream>
#include "rss_io.hpp"

Part::PartType PartTypeByIndex(int index);

namespace rss_io {

    constexpr int kPartTypeIndexMax = 4;

    int PartTypeIn(Part::PartType &part_type) {
        int error = 0;

        try {
            std::string input;
            std::getline(std::cin, input);
            
            int index = std::stoi(input) - 1;
            if (index < 0 || index > kPartTypeIndexMax) {
                error = 1;
            }
            else {
                part_type = PartTypeByIndex(index);
            }
        }
        catch (std::invalid_argument& e) {
            error = 1;
        }
        return error;
    }

    int DoubleIn(double& in) {
        int error = 0;
        std::string input;
        std::getline(std::cin, input);

        try {
            in = std::stod(input);
        }
        catch (std::invalid_argument& e) {
            error = 1;
        }

        return error; 
    }

    int StringIn(std::string& in) {
        std::getline(std::cin, in);
        return 0;
    }

    int IntIn(int& in) {
        int error = 0;
        std::string input;
        std::getline(std::cin, input);

        try {
            in = std::stoi(input);
        }
        catch (std::invalid_argument& e) {
            error = 1;
        }

        return error; 
    }
    
}

Part::PartType PartTypeByIndex(int index) {
    Part::PartType type;
    switch(index) {
        case 0:
            type = Part::PartType::TORSO;
            break;
        case 1:
            type = Part::PartType::HEAD;
            break;
        case 2:
            type = Part::PartType::ARM;
            break;
        case 3:
            type = Part::PartType::LOCOMOTOR;
            break;
        case 4:
            type = Part::PartType::BATTERY;
            break;
    }

    return type;
}
