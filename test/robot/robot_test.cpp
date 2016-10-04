#include <string>
#include <memory>
#include "robot.hpp"
#include "battery.hpp"
#include "catch.hpp"

TEST_CASE("Robot Creation") {
   const std::string kName = "FOO";
   constexpr int kModelNumber = 1234;
   constexpr double kPrice = 20.0;
   
   Robot robot{kName, kModelNumber, kPrice};


   REQUIRE(robot.GetName() == kName);
   REQUIRE(robot.GetModelNumber() == kModelNumber);
   REQUIRE(robot.GetPrice() == kPrice);

   SECTION("Robot Get Parts") {
        constexpr int kPartNumber = 1235;
        constexpr double kWeight = 20;
        constexpr double kCost = 30;
        const std::string kDescription = "Test";
        constexpr double kKilowattHour = 30;

        std::unique_ptr<const Part> part{ new Battery{kName, kPartNumber, 
            kWeight, kCost,kDescription,kKilowattHour}};
        REQUIRE(robot.AddPart(std::move(part)) == true);
        REQUIRE(robot.GetParts().size() == 1);
   }
}
