#include "catch.hpp"

#include <string>
#include <memory>

#include "robot/robot.hpp"
#include "part/torso.hpp"
#include "part/battery.hpp"

TEST_CASE("Robot Creation") {
   const std::string kName = "FOO";
   constexpr int kModelNumber = 1234;
   constexpr double kPrice = 20.0;
   
   Robot robot{kName, kModelNumber, kPrice};


   REQUIRE(robot.GetName() == kName);
   REQUIRE(robot.GetModelNumber() == kModelNumber);
   REQUIRE(robot.GetPrice() == kPrice);

   constexpr int kPartNumber = 1235;
   constexpr double kWeight = 20;
   constexpr double kCost = 30;
   const std::string kDescription = "Test";
   constexpr int kBatteryCompartments = 1;
   std::unique_ptr<Part> torso{ new Torso{kName, kPartNumber, 
            kWeight, kCost,kDescription,kBatteryCompartments}};

   REQUIRE(robot.AddPart(std::move(torso)) == true);
   REQUIRE(robot.GetParts().size() == 1);


   SECTION("Robot Get Parts") {
        constexpr int kPartNumber = 1235;
        constexpr double kWeight = 20;
        constexpr double kCost = 30;
        const std::string kDescription = "Test";
        constexpr double kKilowattHour = 30;

        std::unique_ptr<Part> part{ new Battery{kName, kPartNumber, 
            kWeight, kCost,kDescription,kKilowattHour}};
        REQUIRE(robot.AddPart(std::move(part)) == true);
        REQUIRE(robot.GetParts().size() == 2);
   }
}

TEST_CASE("Robot Part Add Torso and Batteries") {
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
   std::unique_ptr<Part> battery{ new Battery{kName, kPartNumber, 
            kWeight, kCost,kDescription,kKilowattHour}};


   REQUIRE(robot.AddPart(battery->GetCopy()) == true);
   REQUIRE(robot.GetParts().size() == 2);

   //Should fail because of exceeding max battery compartments
   REQUIRE(robot.AddPart(battery->GetCopy()) == false);
   REQUIRE(robot.GetParts().size() == 2);
}

TEST_CASE("Robot ToString") {
   const std::string kName = "FOO";
   constexpr int kModelNumber = 1234;
   constexpr double kPrice = 20.0;
   
   Robot robot{kName, kModelNumber, kPrice};


   REQUIRE(robot.GetName() == kName);
   REQUIRE(robot.GetModelNumber() == kModelNumber);
   REQUIRE(robot.GetPrice() == kPrice);

   constexpr int kPartNumber = 1235;
   constexpr double kWeight = 20;
   constexpr double kCost = 30;
   const std::string kDescription = "Test";
   constexpr int kBatteryCompartments = 1;
   std::unique_ptr<Part> torso{ new Torso{kName, kPartNumber, 
            kWeight, kCost,kDescription,kBatteryCompartments}};

   REQUIRE(robot.AddPart(std::move(torso)) == true);
   REQUIRE(robot.GetParts().size() == 1);

   REQUIRE(robot.ToString() != "");
}
