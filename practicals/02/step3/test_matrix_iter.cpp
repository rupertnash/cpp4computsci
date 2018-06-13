#include <vector>

#include "matrix.hpp"
#include "test.hpp"
#include "range.hpp"

bool test_small_iter() {
  const int N = 4;
  morton::matrix<char> mat(N);

  // Fill with standard C array layout 1D index
  for (auto i: range(N))
    for (auto j: range(N))
      mat(i, j) = i*N + j;

  // Matrix contains:
  //  0  4  8 12
  //  1  5  9 13
  //  2  6 10 14
  //  3  7 11 15

  // This will store the count of elements visited before the current
  // and so should be the Morton index of the element.
  int z = 0;
  for (auto it = mat.begin(); it != mat.end(); ++it) {
    uint32_t i, j;
    morton::decode(z, i, j);
    char expect = i*N + j;
    TEST_ASSERT_EQUAL(expect, *it);
    
    TEST_ASSERT_EQUAL(i, it.x());
    TEST_ASSERT_EQUAL(j, it.y());
    z++;
  }
  TEST_ASSERT_EQUAL(N*N, z);

  {
    // Do the same for the const iterator
    const auto& const_mat = mat;
    int z = 0;
    for (auto it = mat.begin(); it != mat.end(); ++it) {
      uint32_t i, j;
      morton::decode(z, i, j);
      char expect = i*N + j;
      TEST_ASSERT_EQUAL(expect, *it);
      
      z++;
    }
  }
  
  return true;
}

int main() {
  RUN_TEST(test_small_iter());
  return 0;
}
