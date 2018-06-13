#include <vector>

#include "matrix.hpp"
#include "test.hpp"
#include "range.hpp"

bool test_small() {
  const int N = 4;
  morton::matrix<char> small(N);

  // Fill with standard C array layout 1D index
  for (auto i: range(N))
    for (auto j: range(N))
      small(i, j) = i*N + j;

  // Matrix contains:
  //  0  4  8 12
  //  1  5  9 13
  //  2  6 10 14
  //  3  7 11 15
  
  auto data = small.data();
  const std::vector<char> expected = {
    0, 4, 1, 5, 8, 12, 9, 13,
    2, 6, 3, 7,10, 14,11, 15
  };
  for (auto z : range(N*N)) {
    TEST_ASSERT_EQUAL(expected[z], data[z]);
  }
  return true;
}

bool test_large() {
  const int logN = 10;
  const int N = 1 << logN;
  morton::matrix<double> mat(N);
  // fill diagonal 
  for (auto i: range(N))
    mat(i,i) = i;

  auto data = mat.data();
  uint64_t z = 0;
  // pretty easy to convince yourself that the "last" index in each
  // successively bigger quad (starting at the origin) is (n^2 - 1)
  // where n is the linear size of that.
  
  // So in the below we're talking about the values 0, 3, 15

  // 0  1  4  5
  // 2  3  6  7
  // 8  9 12 13
  //10 11 14 15

  
  for (auto i: range(logN+1)) {
    auto n = 1 << i;
    auto z = n*n - 1;
    TEST_ASSERT_EQUAL(n - 1, data[z]);
  }
  
  return true;
}

// Try to ensure we really are deleting used memory
bool test_free() {
  const int logN = 10;
  const int N = 1 << logN;
  for (auto j: range(10000)) {
    morton::matrix<double> mat(N);
    // fill diagonal to ensure memory pages really are allocated
    for (auto i: range(N))
      mat(i,i) = i;
  }
  return true;
}

int main() {
  RUN_TEST(test_small());
  RUN_TEST(test_large());
  RUN_TEST(test_free());
  return 0;
}
