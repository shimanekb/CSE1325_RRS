#include "robot_repo.hpp"
#include "rss_error.hpp"

int RobotRepo::AddRobot(std::unique_ptr<Robot> robot) {
    robots.push_back(std::move(robot));
    return RssError::NO_ERROR;
}

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


std::unique_ptr<Robot> RobotRepo::CreateRobotCopy(
            std::unique_ptr<Robot> const &robot) {
    std::unique_ptr<Robot> my_robot{new Robot{robot->GetName(), 
        robot->GetModelNumber(), robot->GetPrice()}};

    return std::move(my_robot);
}
