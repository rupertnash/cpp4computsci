#include "Complex.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
  Complex zero;
  Complex imaginary_unit(0, 1);
  Complex copy_of_i(imaginary_unit);
  Complex sum = zero + copy_of_i;

  std::cout << sum << std::endl;

  std::cout << sum/sum << std::endl;
}
