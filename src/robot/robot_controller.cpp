#include "robot/robot_controller.hpp"

#include <string>

#include "rrs_io.hpp"
#include "rrs_error.hpp"

int RobotController::CreateRobot() { int error_code = RrsError::NO_ERROR;
    std::string name;
    int model_number;
    double price;

    error_code = GetModelName(name);
    
    if (!error_code) 
        error_code = GetModelNumber(model_number);
    
    if (!error_code)
        error_code = GetModelPrice(price);

    if (!error_code) {
        std::unique_ptr<Robot> robot{new Robot{name, model_number, price}};
        error_code = SelectParts(robot);        

        if (!error_code && robot_repo.SaveRobot(std::move(robot))) {
            robot_view.DisplayModelCreationSuccess();
        }
    }

    return error_code;
}

int RobotController::SelectParts(std::unique_ptr<Robot> const &robot) {
    int error_code = RrsError::NO_ERROR;
    int select;
    bool complete = false;
    int part_number = 0;
    std::unique_ptr<Part> tmp_part;

    while(!complete) {
        robot_view.DisplayPartSelectionMenu();
        if (rrs_io::IntIn(select) || select < 0 || select > 4) {
            error_code = RrsError::BAD_INPUT_TYPE;
            robot_view.DisplayBadPartSelectionInput();
        }
        else {
            error_code = RrsError::NO_ERROR;
            switch (select) {
                case 1:
                    //addpart
                    robot_view.AskPartNumberForModel();
                    if (rrs_io::IntIn(part_number)) {
                        error_code = RrsError::BAD_INPUT_TYPE;
                        robot_view.DisplayBadInput(); 
                        break;
                    }
                    
                    if((error_code = part_repo.GetByPartNumber(part_number, tmp_part))) {
                        robot_view.DisplayPartDoesNotExist();
                        break;
                    }
                    else if (robot->AddPart(std::move(tmp_part))){
                        robot_view.DisplayPartSelectionSuccess();
                    }
                    else {
                        error_code = RrsError::DID_NOT_CREATE;
                        robot_view.DisplayPartSelectionFailure();
                    }

                    break;
                case 2:
                    //List current selected parts
                    robot_view.DisplayRobotParts(robot->GetParts());
                    break;
                case 3:
                    //finish create
                    complete = true;
                    break;
                case 4:
                    //quit to main
                    error_code = RrsError::DID_NOT_CREATE;
                    complete = true;
                    break;
            }
        }
    }

    return error_code;
}

int RobotController::GetModelPrice(double &price) {
    int error_code = RrsError::NO_ERROR;

    robot_view.AskModelPrice();
    if (rrs_io::DoubleIn(price))
        error_code = RrsError::BAD_INPUT_TYPE;

    return error_code;
}

int RobotController::GetModelNumber(int &model_number) {
    int error_code = RrsError::NO_ERROR;

    robot_view.AskModelNumber();
    if (rrs_io::IntIn(model_number))
        error_code = RrsError::BAD_INPUT_TYPE;

    return error_code;
}

int RobotController::GetModelName(std::string &name) {
    int error_code = RrsError::NO_ERROR;

    robot_view.AskModelName();
    if (rrs_io::StringIn(name))
        error_code = RrsError::BAD_INPUT_TYPE;

    return error_code;
}

int RobotController::ShowRobots() {
    robot_view.DisplayRobotModels(robot_repo.GetAll());
    return RrsError::NO_ERROR;
}
