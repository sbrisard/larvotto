#define _USE_MATH_DEFINES

#include "catch2/catch.hpp"
#include "larvotto/larvotto.hpp"

TEST_CASE("Test case #1") {
  SECTION("Section #1") {
    REQUIRE(larvotto::author() == "S. Brisard");
    REQUIRE(larvotto::version() == "0.1");
    REQUIRE(larvotto::return_one() == 1);
  }
}
