#include <string>
#include "head.hpp"
#include "catch.hpp"

TEST_CASE("Head ToString") {
   std::string kName = "FOO"; 
   std::string kDescription = "Test";
   constexpr int kPartNumber = 1234;
   constexpr double kWeight = 10;
   constexpr double kCost = 20;

   const Head& head = Head{kName, kPartNumber, kWeight, kCost,kDescription, 
       Part::PartType::HEAD};

   REQUIRE(head.ToString() != "");
}
