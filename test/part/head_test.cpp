#include "catch.hpp"

#include <string>

#include "part/head.hpp"

TEST_CASE("Head ToString") {
   std::string kName = "FOO"; 
   std::string kDescription = "Test";
   constexpr int kPartNumber = 1234;
   constexpr double kWeight = 10;
   constexpr double kCost = 20;

   const Head& head = Head{kName, kPartNumber, kWeight, kCost,kDescription};

   REQUIRE(head.ToString() != "");
}

TEST_CASE("Head GetCopy") {
   std::string kName = "FOO"; 
   std::string kDescription = "Test";
   constexpr int kPartNumber = 1234;
   constexpr double kWeight = 10;
   constexpr double kCost = 20;

   const Head& head = Head{kName, kPartNumber, kWeight, kCost,kDescription};

   std::unique_ptr<Part> headptr{head.Clone()};
   REQUIRE(headptr->GetName() == kName);
}
