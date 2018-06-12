#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>

template <class T>
class Array {
public:
  Array();
  Array(unsigned n);
  Array(const Array& other);
  Array(Array&& other);
  
  ~Array();
  
  Array& operator=(const Array& other);
  Array& operator=(Array&& other);

  unsigned size() const {
    return _size;
  }
  
  const T& operator[](unsigned i) const;
  T& operator[](unsigned i);
  
private:
  
  void release();
  void steal(Array& other);
  void acquire(unsigned);
  void copy(const Array& other);
  void swap(Array& other);
  unsigned _size;
  T* _data;
  
};

template<class T>
Array<T>::Array() : _size(0), _data(nullptr) {}
  
template<class T>
Array<T>::Array(unsigned n) {
  std::cout << "n ctor" << std::endl;
  acquire(n);
}
  
template<class T>
Array<T>::Array(const Array& other) {
  std::cout << "copy ctor" << std::endl;
  acquire(other._size);
  copy(other);
}

template<class T>
Array<T>::Array(Array&& other) : Array() {
  std::cout << "move ctor" << std::endl;
  swap(other);
  //steal(other);
}
  
template<class T>
Array<T>::~Array() {
  std::cout << "dtor" << std::endl;
  release();
}

template<class T>
auto Array<T>::operator=(const Array& other) -> Array& {
  std::cout << "copy assign" << std::endl;
  release();
  acquire(other._size);
  copy(other);
}

template<class T>
auto Array<T>::operator=(Array&& other) -> Array& {
  std::cout << "move assign" << std::endl;
  swap(other);
  // release();
  // steal();
}

template<class T>
void Array<T>::acquire(unsigned n) {
  _size = n;
  _data = new T[n];
}
template<class T>
void Array<T>::release() {
  delete[] _data;
  _data = nullptr;
  _size = 0;
}
template<class T>
void Array<T>::steal(Array& other) {
  _size = other._size;
  _data = other._data;
  other.release();
}
template<class T>
void Array<T>::copy(const Array& other) {
  for (auto i = 0; i<_size; ++i)
    _data[i] = other._data[i];
}
template<class T>
void Array<T>:: swap(Array& other) {
  std::swap(_size, other._size);
  std::swap(_data, other._data);
}

template<class T>
const T& Array<T>::operator[](unsigned i) const {
  return _data[i];
}

template<class T>
T& Array<T>::operator[](unsigned i) {
  return _data[i];
}

template<class T>
std::ostream& operator<<(std::ostream& os, const Array<T>& a) {
  os << "[";
  bool first = true;
  for (auto i = 0; i < a.size(); ++i) {
    if (!first)
      os << ", ";
    first = false;
    os << a[i];
  }
  os << "]";
  return os;
}
#endif
