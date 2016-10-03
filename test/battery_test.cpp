#include <string>
#include "battery.hpp"
#include "catch.hpp"

TEST_CASE("Battery ToString") {
   std::string kName = "FOO"; 
   std::string kDescription = "Test";
   constexpr int kPartNumber = 1234;
   constexpr double kWeight = 10;
   constexpr double kCost = 20;
   constexpr double kKilowattHour = 2;

   const Part& battery = Battery{kName, kPartNumber, kWeight, kCost,kDescription, 
       Part::PartType::BATTERY, kKilowattHour};

   REQUIRE(battery.ToString() == "FOO");
}
