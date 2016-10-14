#include "rrs_io.hpp"

#include <iostream>

#include "rrs_error.hpp"

Part::PartType PartTypeByIndex(int index);

namespace rrs_io {

    constexpr int kPartTypeIndexMax = 4;

    int PartTypeIn(Part::PartType &part_type) {
        int error = RrsError::NO_ERROR;
        try {
            std::string input;
            std::getline(std::cin, input);
            
            int index = std::stoi(input) - 1;
            if (index < 0 || index > kPartTypeIndexMax) {
                error = RrsError::OUT_OF_RANGE;
            }
            else {
                part_type = PartTypeByIndex(index);
            }
        }
        catch (std::invalid_argument& e) {
            error = RrsError::BAD_INPUT_TYPE;
        }
        return error;
    }

    int DoubleIn(double& in) {
        int error = RrsError::NO_ERROR;
        std::string input;
        std::getline(std::cin, input);

        try {
            in = std::stod(input);
        }
        catch (std::invalid_argument& e) {
            error = RrsError::BAD_INPUT_TYPE;
        }

        return error; 
    }

    int StringIn(std::string& in) {
        std::getline(std::cin, in);
        return 0;
    }

    int IntIn(int& in) {
        int error = RrsError::NO_ERROR;
        std::string input;
        std::getline(std::cin, input);

        try {
            in = std::stoi(input);
        }
        catch (std::invalid_argument& e) {
            error = RrsError::BAD_INPUT_TYPE;
        }

        return error; 
    }
    
    int IntMinMaxIn(int& in, int min, int max) {
        int error = RrsError::NO_ERROR;
        std::string input;
        std::getline(std::cin, input);

        try {
            in = std::stoi(input);
        }
        catch (std::invalid_argument& e) {
            error = RrsError::BAD_INPUT_TYPE;
        }

        if (in < min || in > max)
            error = RrsError::OUT_OF_RANGE;

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
