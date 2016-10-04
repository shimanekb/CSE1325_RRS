#ifndef RRS_ROBOT_ROBOT_REPO_HPP_
#define RRS_ROBOT_ROBOT_REPO_HPP_

#include "robot.hpp"

class RobotRepo {
    public:
        static RobotRepo& GetInstance() {
            static RobotRepo instance;
            return instance;
        }
        bool AddRobot(Robot robot);
        Robot GetByModelNumber(int model_number);
        bool Save(Robot robot);
    private:
        RobotRepo() {};
        RobotRepo(RobotRepo const&);
        void operator=(RobotRepo const&);
        std::vector<Robot> robots;
};
#endif
