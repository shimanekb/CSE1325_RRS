#include <string>
#include <memory>
#include "robot_controller.hpp"
#include "rss_io.hpp"
#include "rss_error.hpp"

int RobotController::CreateRobot() { int error_code = RssError::NO_ERROR;
    std::string name;
    int model_number;
    double price;

    error_code = GetModelName(name);
    
    if (!error_code) 
        error_code = GetModelNumber(model_number);
    
    if (!error_code)
        error_code = GetModelPrice(price);

    if (!error_code)
        std::unique_ptr<Robot> robot{new Robot{name, model_number, price}};

    if (!error_code)
        error_code = SelectParts(robot);        

    return error_code;
}

int RobotController::SelectParts(std::unique<Robot> const &robot) {
    int error_code = RssError::NO_ERROR;
    int select;
    bool complete = false;
    std::vector<std::unique_ptr<Part>> tmp_parts;

    while(!complete) {
        robot_view.DisplayPartSelectionMenu();
        if (rss_io::IntIn(select) || select < 0 || select > 4) {
            error_code = RssError::BAD_INPUT_TYPE;
            robot_view.DisplayBadPartSelectionInput();
        }
        else {
            error_code = RssError::NO_ERROR;
            switch (select) {
                case 1:
                    //addpart
                    part_repo.
                    break;
                case 2:
                    //reset parts
                    tmp_parts.clear();
                    break;
                case 3:
                    //finish create
                    complete = true;
                    break;
                case 4:
                    //quit to main
                    error_code = RssError::DID_NOT_CREATE;
                    complete = true;
                    break;
            }
        }
    }

    return error_code;
}

int RobotController::GetModelPrice(double &price) {
    int error_code = RssError::NO_ERROR;

    robot_view.AskModelPrice();
    if (rss_io::DoubleIn(model_number))
        error_code = RssError::BAD_INPUT_TYPE;

    return error_code
}

int RobotController::GetModelNumber(int &model_number) {
    int error_code = RssError::NO_ERROR;

    robot_view.AskModelNumber();
    if (rss_io::IntIn(model_number))
        error_code = RssError::BAD_INPUT_TYPE;

    return error_code
}

int RobotController::GetModelName(std::string &name) {
    int error_code = RssError::NO_ERROR;

    robot_view.AskModelName();
    if (rss_io::StringIn(name))
        error_code = RssError::BAD_INPUT_TYPE;

    return error_code
}
