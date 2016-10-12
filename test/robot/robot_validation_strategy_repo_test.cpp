#include "robot_validation_strategy_repo.hpp"

#include <string>
#include <memory>

#include "robot.hpp"
#include "torso.hpp"
#include "battery.hpp"
#include "catch.hpp"
#include "rss_error.hpp"

TEST_CASE("Battery Validation Strategy From Repo Add Torso and Batteries") {
   RobotValidationStrategyRepo repo;
   const std::string kName = "FOO";
   constexpr int kModelNumber = 1234;
   constexpr double kPrice = 20.0;
   
   Robot robot{kName, kModelNumber, kPrice};

   REQUIRE(robot.GetName() == kName);
   REQUIRE(robot.GetModelNumber() == kModelNumber);
   REQUIRE(robot.GetPrice() == kPrice);
   
   //Torso
   constexpr int kPartNumber = 1235;
   constexpr double kWeight = 20;
   constexpr double kCost = 30;
   const std::string kDescription = "Test";
   constexpr int kBatteryCompartments = 1;
   std::unique_ptr<Part> torso{ new Torso{kName, kPartNumber, 
            kWeight, kCost,kDescription,kBatteryCompartments}};

   REQUIRE(robot.AddPart(std::move(torso)) == true);
   REQUIRE(robot.GetParts().size() == 1);

   //Battery
   constexpr double kKilowattHour = 1;
   Battery battery{kName, kPartNumber, 
            kWeight, kCost,kDescription,kKilowattHour};

   REQUIRE(robot.AddPart(std::unique_ptr<Part>{new Battery{battery}}) == true);
   REQUIRE(robot.GetParts().size() == 2);

   std::unique_ptr<RobotValidationStrategy> strategy;
   REQUIRE(repo
       .DetermineStrategy(battery.GetPartType(), strategy) == RssError::NO_ERROR);

   //Should fail because of exceeding max battery compartments
   REQUIRE(strategy->Validate(robot, battery) == RssError::OUT_OF_RANGE);
}
