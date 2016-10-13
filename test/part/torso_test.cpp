#include "catch.hpp"

#include <string>

#include "part/torso.hpp"

TEST_CASE("Torso ToString") {
   std::string kName = "FOO"; 
   std::string kDescription = "Test";
   constexpr int kPartNumber = 1234;
   constexpr double kWeight = 10;
   constexpr double kCost = 20;
   constexpr int kBatteryCompartments = 2;

   const Torso& torso = Torso{kName, kPartNumber, kWeight, kCost,kDescription, 
     kBatteryCompartments};

   REQUIRE(torso.ToString() != "");
}
