#include "catch.hpp"

#include <string>
#include <memory>

#include "part/head.hpp"
#include "robot/robot.hpp"
#include "robot/robot_repo.hpp"
#include "rss_error.hpp"

TEST_CASE("RobotRepo GetRobotByModelNumber") {
   RobotRepo &repo = RobotRepo::GetInstance();
   const std::string kName = "FOO";
   constexpr int kModelNumber = 1324;
   constexpr double kPrice = 20;

   std::unique_ptr<Robot> robot{new Robot{kName, kModelNumber, kPrice}};

   REQUIRE(repo.SaveRobot(std::move(robot)) == RssError::NO_ERROR);

   SECTION("GetByModelNumber Without Error") {
        std::unique_ptr<Robot> tmp_robot;
        REQUIRE(repo.GetRobotByModelNumber(kModelNumber, tmp_robot) == 
                RssError::NO_ERROR);
        REQUIRE(tmp_robot->GetPrice() == kPrice);
   }

   SECTION("GetByModelNumber With Error") {
        constexpr int kFake = 000000000000;
        std::unique_ptr<Robot> tmp_robot;
        REQUIRE(repo.GetRobotByModelNumber(kFake, tmp_robot) == 
                RssError::NOT_FOUND);
   }

   REQUIRE(repo.DeleteRobotByModelNumber(kModelNumber) ==
                RssError::NO_ERROR);
   REQUIRE(repo.GetRobotByModelNumber(kModelNumber, robot) == 
                RssError::NOT_FOUND);
}

TEST_CASE("RobotRepo Basic Save Operations") {
   RobotRepo &repo = RobotRepo::GetInstance();
   const std::string kName = "FOO";
   constexpr int kModelNumber = 1324;
   constexpr double kPrice = 20;

   std::unique_ptr<Robot> robot{new Robot{kName, kModelNumber, kPrice}};

   REQUIRE(repo.SaveRobot(std::move(robot)) == RssError::NO_ERROR);

   REQUIRE(repo.DeleteRobotByModelNumber(kModelNumber) ==
                RssError::NO_ERROR);
   REQUIRE(repo.GetRobotByModelNumber(kModelNumber, robot) == 
                RssError::NOT_FOUND);
}

TEST_CASE("RobotRepo Basic Save With Mod Operations") {
   RobotRepo &repo = RobotRepo::GetInstance();
   const std::string kName = "FOO";
   constexpr int kModelNumber = 1324;
   constexpr double kPrice = 20;
   const std::string kPartName = "Frank";
   constexpr int kPartNumber = 1;
   constexpr double kWeight = 30;
   constexpr double kPartCost = 20;
   const std::string kPartDescription = "FOO";


   std::unique_ptr<Robot> robot{new Robot{kName, kModelNumber, kPrice}};
   robot->AddPart(std::unique_ptr<Part>{new Head{kPartName, kPartNumber, 
            kWeight, kPartCost, kPartDescription}});  

   REQUIRE(robot->GetParts().size() == 1);

   REQUIRE(repo.SaveRobot(std::move(robot)) == RssError::NO_ERROR);
   REQUIRE(repo.GetRobotByModelNumber(kModelNumber, robot) == 
            RssError::NO_ERROR);
   REQUIRE(robot->GetParts().size() == 1);


   REQUIRE(repo.DeleteRobotByModelNumber(kModelNumber) ==
                RssError::NO_ERROR);
   REQUIRE(repo.GetRobotByModelNumber(kModelNumber, robot) == 
                RssError::NOT_FOUND);
}
