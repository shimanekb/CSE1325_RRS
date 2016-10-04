#include "robot_repo.hpp"
#include "catch.hpp"

TEST_CASE("RobotRepo Crud Operations") {
   RobotRepo &repo = RobotRepo::GetInstance();

   REQUIRE(true == true);
}

