#include "robot/robot.hpp"

#include <sstream>

#include "rss_error.hpp"
#include "robot/robot_validation_strategy_repo.hpp"

Robot::Robot(const std::string name, const int model_number, const double price) : kName(name), kModelNumber(model_number), kPrice(price) {};

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

bool Robot::AddPart(std::unique_ptr<Part> part) {
    bool added = false;
    Part *tmp_part = part->Clone();
    Part &ref_part = *tmp_part;

    if (ValidatePart(ref_part) == RssError::NO_ERROR) {
        parts.push_back(std::move(part));    
        added = true;
    }

    delete tmp_part;
    return added;
}

std::string Robot::ToString() const {
    std::stringstream ss;
    ss << "Robot Model Name: " << GetName() << std::endl 
        << "Robot Model Number: " << GetModelNumber() << std::endl 
        << "Robot Model Price: $" << GetPrice() << std::endl
        << "Parts" << std::endl << "*****************" << std::endl;

    int index = 1;
    for (std::unique_ptr<Part> const &part : GetParts()) {
        ss << index++ << ". " << part->ToString();
    }

    return ss.str();
}


std::unique_ptr<Robot> Robot::GetCopy() const {
    std::unique_ptr<Robot> tmp_bot{new Robot{GetName(), GetModelNumber(), 
    GetPrice()}};
    for (std::unique_ptr<Part> const &part : GetParts()) {
        tmp_bot->AddPart(std::unique_ptr<Part>{part->Clone()});
    }

    return std::move(tmp_bot);
}


int Robot::ValidatePart(const Part &part) {
    int error_code = RssError::NO_ERROR;

    std::unique_ptr<RobotValidationStrategy> strategy;
    RobotValidationStrategyRepo validationRepo{};
    error_code = validationRepo.DetermineStrategy(part.GetPartType(), strategy);

    if (!error_code) {
        error_code = strategy->Validate(*this, part);   
    }

    return error_code;
}
