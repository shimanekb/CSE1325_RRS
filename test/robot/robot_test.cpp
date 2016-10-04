#include <string>
#include "robot.hpp"
#include "catch.hpp"

TEST_CASE("Robot Creation") {
   const std::string kName = "FOO";
   constexpr int kModelNumber = 1234;
   constexpr double kPrice = 20.0;

   Robot robot{kName, kModelNumber, kPrice};

   REQUIRE(robot.GetName() == kName);
   REQUIRE(robot.GetModelNumber() == kModelNumber);
   REQUIRE(robot.GetPrice() == kPrice);
}
