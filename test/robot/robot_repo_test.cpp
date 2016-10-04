#include <string>
#include <memory>
#include "rss_error.hpp"
#include "robot.hpp"
#include "robot_repo.hpp"
#include "catch.hpp"

TEST_CASE("RobotRepo Crud Operations") {
   RobotRepo &repo = RobotRepo::GetInstance();
   const std::string kName = "FOO";
   constexpr int kModelNumber = 1324;
   constexpr double kPrice = 20;

   std::unique_ptr<Robot> robot{new Robot{kName, kModelNumber, kPrice}};

   REQUIRE(repo.AddRobot(std::move(robot)) == RssError::NO_ERROR);
}

