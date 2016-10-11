#ifndef RRS_ROBOT_ROBOT_REPO_HPP_
#define RRS_ROBOT_ROBOT_REPO_HPP_

#include <memory>
#include <vector>
#include "robot.hpp"

class RobotRepo {
    public:
        static RobotRepo& GetInstance() {
            static RobotRepo instance;
            return instance;
        }
        int GetRobotByModelNumber(int model_number, std::unique_ptr<Robot> &robot);
        int SaveRobot(std::unique_ptr<Robot> robot);
        int DeleteRobotByModelNumber(int model_number);
        std::vector<std::unique_ptr<Robot>> GetAll();
    private:
        RobotRepo() {};
        RobotRepo(RobotRepo const&);
        void operator=(RobotRepo const&);
        std::vector<std::unique_ptr<Robot>> robots;
        std::unique_ptr<Robot> CreateRobotCopy(
            std::unique_ptr<Robot> const &robot);
};

#endif
