#include "controller/robot/robot_controller.hpp"

#include <string>

#include "rrs_io.hpp"
#include "rrs_error.hpp"

int RobotController::CreateRobot(std::unique_ptr<Robot> &robotIn, 
        const RobotCreationWindow* window) {
    constexpr int kMax = 99999999999;
    const std::string kEmptyChoice = "None";
    int error_code = RrsError::NO_ERROR;
    std::unique_ptr<Part> tmp_part;
    int tmpNum;
    std::string name = window->GetRobotName();
    std::string numberStr = window->GetRobotNumber();
    std::string costStr = window ->GetRobotCost();
    int model_number;
    double price;
            
    error_code = rrs_io::StringToInt(numberStr, model_number,
            0, kMax) + rrs_io::StringToDouble(costStr, price, 0,
                kMax);

    robotIn = std::unique_ptr<Robot>{new Robot{name, model_number, price}};

    if (!error_code && (window->GetTorsoChoice()).compare(kEmptyChoice)) {
        error_code = rrs_io::StringToInt(window->GetTorsoChoice() , tmpNum, 0,
                kMax); 
        part_repo.GetByPartNumber(tmpNum, tmp_part);
        if (!robotIn->AddPart(std::move(tmp_part)))
            error_code = RrsError::BAD_INPUT_TYPE;
    }

    if (!error_code && (window->GetHeadChoice().compare(kEmptyChoice))) {
        error_code = rrs_io::StringToInt(window->GetHeadChoice() , tmpNum, 0,
                kMax); 
        part_repo.GetByPartNumber(tmpNum, tmp_part);

        if (!robotIn->AddPart(std::move(tmp_part)))
            error_code = RrsError::BAD_INPUT_TYPE;
    }

    if (!error_code && (window->GetArmChoiceOne().compare(kEmptyChoice))) {
        error_code = rrs_io::StringToInt(window->GetArmChoiceOne() , tmpNum, 0,
                kMax); 
        part_repo.GetByPartNumber(tmpNum, tmp_part);

        if (!robotIn->AddPart(std::move(tmp_part)))
            error_code = RrsError::BAD_INPUT_TYPE;
    }

    if (!error_code && (window->GetArmChoiceTwo().compare(kEmptyChoice))) {
        error_code = rrs_io::StringToInt(window->GetArmChoiceTwo() , tmpNum, 0,
                kMax); 
        part_repo.GetByPartNumber(tmpNum, tmp_part);

        if (!robotIn->AddPart(std::move(tmp_part)))
            error_code = RrsError::BAD_INPUT_TYPE;
    }

    if (!error_code && (window->GetLocomotorChoice().compare(kEmptyChoice))) {
        error_code = rrs_io::StringToInt(window->GetLocomotorChoice() , tmpNum, 0,
                kMax); 
        part_repo.GetByPartNumber(tmpNum, tmp_part);

        if (!robotIn->AddPart(std::move(tmp_part)))
            error_code = RrsError::BAD_INPUT_TYPE;
    }

    if (!error_code && (window->GetBatteryChoiceOne().compare(kEmptyChoice))) {
        error_code = rrs_io::StringToInt(window->GetBatteryChoiceOne() , tmpNum, 0,
                kMax); 
        part_repo.GetByPartNumber(tmpNum, tmp_part);

        if (!robotIn->AddPart(std::move(tmp_part)))
            error_code = RrsError::BAD_INPUT_TYPE;
    }

    if (!error_code && (window->GetBatteryChoiceTwo().compare(kEmptyChoice))) {
        error_code = rrs_io::StringToInt(window->GetBatteryChoiceTwo() , tmpNum, 0,
                kMax); 
        part_repo.GetByPartNumber(tmpNum, tmp_part);

        if (!robotIn->AddPart(std::move(tmp_part)))
            error_code = RrsError::BAD_INPUT_TYPE;
    }

    if (!error_code && (window->GetBatteryChoiceThree().compare(kEmptyChoice))) {
        error_code = rrs_io::StringToInt(window->GetBatteryChoiceThree() , tmpNum, 0,
                kMax); 
        part_repo.GetByPartNumber(tmpNum, tmp_part);

        if (!robotIn->AddPart(std::move(tmp_part)))
            error_code = RrsError::BAD_INPUT_TYPE;
    }

    if (!error_code) {
        error_code = robot_repo.SaveRobot(std::unique_ptr<Robot>{robotIn->Clone()});
    }

    return error_code;
}

int RobotController::GetRobotComponentsByType(Part::PartType type, 
                        std::vector<std::unique_ptr<Part>> &parts) {
    part_repo.GetRobotComponentsByType(type, parts);
    return RrsError::NO_ERROR;
}
int RobotController::ShowRobots() {
    robot_view.DisplayRobotModels(robot_repo.GetAll());
    return RrsError::NO_ERROR;
}
