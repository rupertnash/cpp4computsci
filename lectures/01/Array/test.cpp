#include "Array.hpp"

#include <iostream>

Array<char> make() {
  Array<char> string(5);
  string[0] = 'h';
  string[1] = 'e';
  string[2] = 'l';
  string[3] = 'l';
  string[4] = 'o';
  return string;
}
int main() {
  auto var = make();
  std::cout << var << std::endl;
}
