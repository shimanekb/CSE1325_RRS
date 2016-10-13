#include "catch.hpp"

#include <string>
#include <sstream>

#include "part/battery.hpp"

TEST_CASE("Battery ToString") {
   std::string kName = "FOO"; 
   std::string kDescription = "Test";
   constexpr int kPartNumber = 1234;
   constexpr double kWeight = 10;
   constexpr double kCost = 20;
   constexpr double kKilowattHour = 2;

   const Part& battery = Battery{kName, kPartNumber, kWeight, kCost,kDescription, 
       kKilowattHour};

   std::stringstream expected_string;
   expected_string << "Part Number: " << kPartNumber << std::endl 
       << "Part Type: " << "Battery" << std::endl
       << "Part Name: " << kName << std::endl << "Part Weight: " 
       << kWeight << " kg" << std::endl << "Part Cost: $" << kCost << std::endl
       << "Kilowatt Hours: " << kKilowattHour << std::endl << "Description: " 
       << kDescription << std::endl;

   REQUIRE(battery.ToString() == expected_string.str());
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

   std::unique_ptr<Part> part{battery.GetCopy()};
   REQUIRE(part->ToString() != "Part Number: 1234\n");
}
