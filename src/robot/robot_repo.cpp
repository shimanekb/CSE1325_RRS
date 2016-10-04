#include "robot_repo.hpp"
#include "rss_error.hpp"

int RobotRepo::GetRobotByModelNumber(int model_number, std::unique_ptr<Robot> &robot) {
    int error_code = RssError::NOT_FOUND;
    for (std::unique_ptr<Robot> const &bot : robots) {
       if (bot->GetModelNumber() == model_number) {
           error_code = RssError::NO_ERROR;
           robot = std::move(CreateRobotCopy(bot));
       } 
    }

    return error_code;
}

int RobotRepo::DeleteRobotByModelNumber(int model_number) {
    int error_code = RssError::GENERIC_ERROR;
    int i = 0;
    for (std::unique_ptr<Robot> &bot : robots) {
       if (bot->GetModelNumber() == model_number) {
           error_code = RssError::NO_ERROR;
           robots.erase(robots.begin() + i);
           break;
       } 

       ++i;
    }

    return error_code;
}

int RobotRepo::SaveRobot(std::unique_ptr<Robot> robot) {
    int error_code = RssError::NO_ERROR;
    std::unique_ptr<Robot> tmp_robot;

    if (GetRobotByModelNumber(robot->GetModelNumber(), tmp_robot) == RssError::NO_ERROR) {
        error_code = DeleteRobotByModelNumber(robot->GetModelNumber());
    }

    if (error_code == RssError::NO_ERROR) {
        robots.push_back(std::move(robot));
    }

    return error_code;
}

std::unique_ptr<Robot> RobotRepo::CreateRobotCopy(
            std::unique_ptr<Robot> const &robot) {
    std::unique_ptr<Robot> my_robot{new Robot{robot->GetName(), 
        robot->GetModelNumber(), robot->GetPrice()}};
    
    for (const std::unique_ptr<Part> &part : robot->GetParts()) {
        my_robot->AddPart(part->GetCopy());
    }

    return std::move(my_robot);
}
