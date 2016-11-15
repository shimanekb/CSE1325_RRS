#include "model/robot/robot.hpp"

#include <sstream>
#include "rrs_error.hpp"
#include "model/robot/robot_validation_strategy_repo.hpp"

Robot::Robot(const std::string name, const int model_number, const double price, 
        const std::string imagePath) : kName(name), kModelNumber(model_number), 
    kPrice(price), kImagePath(imagePath) {}

std::string Robot::GetName() const {
    return kName;
}

int Robot::GetModelNumber() const {
    return kModelNumber;
}

double Robot::GetPrice() const {
    return kPrice;
}

const std::vector<std::unique_ptr<Part>>& Robot::GetParts() const {
    return parts;
}


void Robot::GetPartsByType(Part::PartType type, std::vector<std::unique_ptr<Part>> &in) const {
    in.clear();
    for (const std::unique_ptr<Part> &tmpPart : parts) {
        if (tmpPart->GetPartType() == type)
            in.push_back(std::unique_ptr<Part>{tmpPart->Clone()});
    } 
}

bool Robot::AddPart(std::unique_ptr<Part> part) {
    bool added = false;
    Part *tmp_part = part->Clone();
    Part &ref_part = *tmp_part;

    if (ValidatePart(ref_part) == RrsError::NO_ERROR) {
        parts.push_back(std::move(part));    
        added = true;
    }

    delete tmp_part;
    return added;
}

std::string Robot::ToString() const {
    std::stringstream ss;
    ss << "\tRobot Model Name: " << GetName() << std::endl 
        << "\tRobot Model Number: " << GetModelNumber() << std::endl 
        << "\tRobot Model Price: $" << GetPrice() << std::endl << std::endl
        << "\tParts" << std::endl << "\t*****************" << std::endl;

    int index = 1;
    for (std::unique_ptr<Part> const &part : GetParts()) {
        ss <<  part->ToString() << "\t-----------------" << std::endl;
    }

    return ss.str();
}

Robot* Robot::Clone() const {
    Robot* tmp_bot = new Robot{GetName(), GetModelNumber(), 
    GetPrice(), GetImagePath()};
    for (std::unique_ptr<Part> const &part : GetParts()) {
        tmp_bot->AddPart(std::unique_ptr<Part>{part->Clone()});
    }

    return tmp_bot;
}

std::string Robot::GetImagePath() const {
    return kImagePath;
}

int Robot::ValidatePart(const Part &part) {
    int error_code = RrsError::NO_ERROR;

    std::unique_ptr<RobotValidationStrategy> strategy;
    RobotValidationStrategyRepo validationRepo{};
    error_code = validationRepo.DetermineStrategy(part.GetPartType(), strategy);

    if (!error_code) {
        error_code = strategy->Validate(*this, part);   
    }

    return error_code;
}

Fl_PNG_Image * Robot::GetImage() {
    return new Fl_PNG_Image{kImagePath.c_str()};
}


