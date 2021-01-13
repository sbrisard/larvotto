#include <iostream>
#include "larvotto/larvotto.hpp"

int main() {
  std::cout << "version = " << larvotto::version() << std::endl;
  std::cout << "author = " << larvotto::author() << std::endl;
  std::cout << "return_one() = " << larvotto::return_one() << std::endl;
  return 0;
}
