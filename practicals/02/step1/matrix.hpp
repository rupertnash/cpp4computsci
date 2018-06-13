#ifndef MORTON_MATRIX_HPP
#define MORTON_MATRIX_HPP

#include <cassert>

namespace morton {
  
  // 2D square matrix that stores data in Morton order
  
  // This first implementation requires that the size be a power of 2
  // (or zero indicating an empty matrix)
  template<class T>
  class matrix {
  public:
    // TODO
    matrix() : _rank(0) {
    }

    // TODO
    // Design decision: matrix is not resizeable
    matrix(uint32_t r) {
      // Would consider throwing an exception, but these are not in
      // the syllabus!
      assert((r & (r-1)) == 0);
    }

    // Design decision: implicit copying is not allowed - must use
    // explicit function (duplicate) below
    matrix(const matrix& other) = delete;
    matrix& operator=(const matrix& other) = delete;

    // TODO
    // Moving should be allowed - will the default implementations be OK?
    matrix(matrix&& other);
    matrix& operator=(matrix&& other);

    // TODO
    // Destructor - will the default implemenation be OK?
    ~matrix();

    // TODO
    // Create a new matrix with contents copied from this one
    matrix duplicate() const;
    
    // Get rank size
    uint32_t rank() const {
      return _rank;
    }
    
    // Get total size
    uint64_t size() const {
      return uint64_t(_rank) * uint64_t(_rank);
    }

    // TODO
    // Const element access
    const T& operator()(uint32_t i, uint32_t j) const;

    // TODO
    // Mutable element access
    T& operator()(uint32_t i, uint32_t j);

    // TODO
    // Raw data access (const and mutable versions)
    const T* data() const;
    T* data();
    
  private:
    // rank of matrix
    uint32_t _rank;
    // Data storage
    // TODO
  };
  
}
#endif
