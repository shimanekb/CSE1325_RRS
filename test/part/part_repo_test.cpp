#include <string>
#include <memory>
#include "battery.hpp"
#include "part_repo.hpp"
#include "catch.hpp"

TEST_CASE("PartRepo Crud Operations") {
   std::string kName = "FOO"; 
   std::string kDescription = "Test";
   constexpr int kPartNumber = 1234;
   constexpr double kWeight = 10;
   constexpr double kCost = 20;
   constexpr double kKilowattHour = 2;

   const Part& battery = Battery{kName, kPartNumber, kWeight, kCost,kDescription, 
       kKilowattHour};

   PartRepo& repo = PartRepo::GetInstance();

   REQUIRE(repo.AddPart(std::unique_ptr<const Part>{new Battery{kName, 
               kPartNumber, kWeight, kCost,kDescription, kKilowattHour}})
               == true);

   /*
   SECTION("Part Repo GetParts") {

   }
   */
}
