#define _USE_MATH_DEFINES

#include "catch2/catch.hpp"
#include "larvotto/larvotto.hpp"

double minimum_image(double x, double y, double L) {
  int arg_min = -2;
  double r_min = std::numeric_limits<double>::max();
  for (int n = -1; n < 2; n++) {
    const double r = fabs(y - x + n * L);
    if (r < r_min) {
      arg_min = n;
      r_min = r;
    }
  }
  return y - x + arg_min * L;
}

TEST_CASE("Test case #1") {
  SECTION("Section #1") {
    REQUIRE(larvotto::author() == "S. Brisard");
    REQUIRE(larvotto::version() == "0.1");
    REQUIRE(larvotto::return_one() == 1);
  }
}

TEST_CASE("Minimum image (1D)") {
  larvotto::SimulationBox<1> box({0.9});
  std::array<double, 10> positions{0.0, 0.1, 0.2, 0.3, 0.4,
                                   0.5, 0.6, 0.7, 0.8, 0.9};
  for (auto x : positions) {
    for (auto y : positions) {
      auto actual = box.minimum_image({x}, {y})[0];
      auto expected = minimum_image(x, y, box.L[0]);
      REQUIRE(actual == expected);
    }
  }
}