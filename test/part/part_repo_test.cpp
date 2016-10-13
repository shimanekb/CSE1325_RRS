#include "catch.hpp"

#include <string>
#include <memory>

#include "part/battery.hpp"
#include "part/part_repo.hpp"
#include "rss_error.hpp"

TEST_CASE("PartRepo Crud Operations") {
   std::string kName = "FOO"; 
   std::string kDescription = "Test";
   constexpr int kPartNumber = 1234;
   constexpr double kWeight = 10;
   constexpr double kCost = 20;
   constexpr double kKilowattHour = 2;

   PartRepo& repo = PartRepo::GetInstance();

   REQUIRE(repo.Add(std::unique_ptr<Part>{new Battery{kName, 
               kPartNumber, kWeight, kCost,kDescription, kKilowattHour}})
               == true);

   SECTION("Part Repo GetParts") {
        REQUIRE(repo.GetAll().size() == 1);
   }
}

TEST_CASE("PartRepo GetByPartNumber") {
   std::string kName = "FOO"; 
   std::string kDescription = "Test";
   constexpr int kPartNumber = 1234;
   constexpr double kWeight = 10;
   constexpr double kCost = 20;
   constexpr double kKilowattHour = 2;

   std::unique_ptr<Part> tmp;
   PartRepo& repo = PartRepo::GetInstance();

   REQUIRE(repo.Add(std::unique_ptr<Part>{new Battery{kName, 
               kPartNumber, kWeight, kCost,kDescription, kKilowattHour}})
               == true);

   REQUIRE(repo.GetByPartNumber(kPartNumber, tmp) == RssError::NO_ERROR);
   REQUIRE(tmp->GetPartNumber() == kPartNumber);
}
