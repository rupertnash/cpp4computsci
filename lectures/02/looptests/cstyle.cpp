#include <cassert>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "util.cpp"

void scale(float* data, unsigned n, const float x) {
  for (unsigned i=0; i!=n; ++i)
    data[i] *= x;
}

int main(int argc, char** argv) {
  // Requires one argument, the size of the list to generate
  assert(argc == 2);
  int size = std::atoi(argv[1]);

  std::vector<float> data(size);
  for (auto el: data)
    el = rand(1000);

  Timer t;
  for (auto i = 0; i!=100; ++i) {
    scale(data.data(), data.size(), 0.5);
  }
  std::cout << __FILE__ ", " << size << ", " << t.GetSeconds()/100 << std::endl;
}
