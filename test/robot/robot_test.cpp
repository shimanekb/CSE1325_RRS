#include <string>
#include "robot.hpp"
#include "catch.hpp"

TEST_CASE("Robot Creation") {
   const std::string kName = "FOO";
   constexpr int kModelNubmer = 1234;
   constexpr double kPrice = 20.0;

   Robot robot{kName, kModelNubmer, kPrice};

   REQUIRE(true == true);
}
