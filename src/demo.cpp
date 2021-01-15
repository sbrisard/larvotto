#include <iostream>

#include "larvotto/larvotto.hpp"

int main() {
  constexpr size_t dim = 3;
  larvotto::SimulationBox<dim> box{{1., 2., 3.}};
  std::cout << box << std::endl;
}