#include "catch.hpp"

#include <string>
#include <sstream>

#include "model/part/battery.hpp"

TEST_CASE("Battery ToString") {
   std::string kName = "FOO"; 
   std::string kDescription = "Test";
   constexpr int kPartNumber = 1234;
   constexpr double kWeight = 10;
   constexpr double kCost = 20;
   constexpr double kKilowattHour = 2;

   const Part& battery = Battery{kName, kPartNumber, kWeight, kCost,kDescription, 
       kKilowattHour};

   REQUIRE(battery.ToString() != "");
}

TEST_CASE("Battery GetCopy") {
   std::string kName = "FOO"; 
   std::string kDescription = "Test";
   constexpr int kPartNumber = 1234;
   constexpr double kWeight = 10;
   constexpr double kCost = 20;
   constexpr double kKilowattHour = 2;

   const Part& battery = Battery{kName, kPartNumber, kWeight, kCost,kDescription, 
       kKilowattHour};

   std::unique_ptr<Part> part{battery.Clone()};
   REQUIRE(part->ToString() != "Part Number: 1234\n");
}
