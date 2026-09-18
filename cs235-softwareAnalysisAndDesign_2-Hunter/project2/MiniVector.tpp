// File name: MiniVector.tpp  (submit this file, renamed if needed, to Gradescope)
// Name:
// Email:
//
// CSCI 235 -- Project 1B: MiniVector (template)
// Hunter College, CUNY | Fall 2026
//
// Implement every function marked "TODO" below. Do not change any
// function's signature, and do not modify MiniVector.hpp.
//
// This file is a .tpp, not a .cpp, because MiniVector is now a template:
// the compiler needs to see a template function's full body at the point
// where it is used, for whatever type T that use asks for. MiniVector.hpp
// already #includes this file at the bottom, so you never #include
// MiniVector.tpp yourself, and you never compile it directly -- just
// implement the TODOs here exactly as you would in a .cpp file.
//
// Compile (with MiniVectorTest.cpp, which is provided and already runs a
// battery of self-checks):
//   g++ -std=c++17 -Wall -Wextra -pedantic MiniVectorTest.cpp Rectangle.cpp -o MiniVectorTest
// Tests may fail or terminate with a runtime memory error until the
// corresponding and prerequisite TODO sections are completed. Complete the
// tasks in order:
//   Task A, then Task B, then Task C, then Task D.

#include <stdexcept>
#include <string>   // std::to_string, for at()'s exception message

// ============================================================
// Task A -- Construction and destruction
// ============================================================

// TODO (Task A): Default constructor.
// Allocate data_ as a new array of capacity 2, with every element
// value-initialized. Use `new T[2]{}` so built-in types such as int
// are initialized to zero; class types invoke their default constructor.
// size_ = 0, capacity_ = 2.
template <typename T>
MiniVector<T>::MiniVector() {
  data_ = nullptr;       // placeholder -- replace with `new T[2]{}`
  size_ = 0;
  capacity_ = 0;          // placeholder -- replace with 2
}

// TODO (Task A): Count constructor.
// If count > 0: capacity_ = size_ = count; allocate data_ with count
// value-initialized elements (`new T[count]{}`).
// If count == 0: behave exactly like the default constructor above
// (capacity_ == 2, data_ pointing to a real 2-element allocation) --
// do not leave data_ null in this case.
template <typename T>
MiniVector<T>::MiniVector(std::size_t count) {
  (void)count;            // placeholder -- remove once you use count
  data_ = nullptr;
  size_ = 0;
  capacity_ = 0;
}

// TODO (Task A): Destructor.
// Release the array data_ points to. That is the only cleanup needed --
// size_ and capacity_ do not need to be reset, since the object is about
// to stop existing.
template <typename T>
MiniVector<T>::~MiniVector() {
  // TODO
}

// ============================================================
// PROVIDED -- study these, you do not need to change them.
// ============================================================

// Unchecked element access. Out-of-range pos is undefined behavior,
// exactly like std::vector::operator[].
template <typename T>
T& MiniVector<T>::operator[](std::size_t pos) {
  return data_[pos];
}

template <typename T>
const T& MiniVector<T>::operator[](std::size_t pos) const {
  return data_[pos];
}

template <typename T>
bool MiniVector<T>::empty() const {
  return size_ == 0;
}

template <typename T>
std::size_t MiniVector<T>::size() const {
  return size_;
}

template <typename T>
std::size_t MiniVector<T>::capacity() const {
  return capacity_;
}

// ============================================================
// Task B -- Growth and capacity
// ============================================================

// TODO (Task B): Ensure capacity for at least newCapacity elements.
// If newCapacity > capacity_, allocate a new array of exactly newCapacity
// elements, copy the existing size_ elements into it, and delete[] the
// old array, then point data_ at the new one. (capacity_ starts at 2 from
// the constructors above, so you never need a special case for
// capacity_ == 0.) If newCapacity <= capacity_, do nothing.
template <typename T>
void MiniVector<T>::reserve(std::size_t newCapacity) {
  (void)newCapacity;        // placeholder -- remove once you use newCapacity
  // TODO
}

// TODO (Task B): Append element at the end.
// If size_ == capacity_, there is no room: call reserve(2 * capacity_) to
// grow before inserting. reserve() (above) already contains the
// allocate/copy/free logic -- push_back() should not duplicate it. Then
// write element into data_[size_] and increment size_.
template <typename T>
void MiniVector<T>::push_back(T element) {
  (void)element;            // placeholder -- remove once you use element
  // TODO
}

// ============================================================
// Task C -- Removal and checked access
// ============================================================

// TODO (Task C): Bounds-checked element access.
// If pos >= size_, throw std::out_of_range with a helpful message.
// Otherwise, behave exactly like operator[].
template <typename T>
T& MiniVector<T>::at(std::size_t pos) {
  // TODO: bounds check, then `return data_[pos];`
  return data_[pos];   // placeholder -- currently unchecked, fix this
}

template <typename T>
const T& MiniVector<T>::at(std::size_t pos) const {
  // TODO: bounds check, then `return data_[pos];`
  return data_[pos];   // placeholder -- currently unchecked, fix this
}

// TODO (Task C): Remove the last element.
// Precondition: !empty(). Like std::vector::pop_back(), calling this on
// an empty MiniVector is undefined behavior -- do not add a check, and
// do not throw. Decrement size_ by one. Do not touch capacity_ or the
// underlying array -- the removed element's old slot is simply no longer
// considered "in use."
template <typename T>
void MiniVector<T>::pop_back() {
  // TODO
}

// TODO (Task C): Remove all elements.
// Set size_ to 0. No precondition -- calling this on an already-empty
// MiniVector is safe. Do not touch capacity_ or the underlying array.
template <typename T>
void MiniVector<T>::clear() {
  // TODO
}

// ============================================================
// Task D -- Rule of Three (copy constructor & copy assignment)
// ============================================================

// TODO (Task D): Copy constructor.
// Allocate a new array of other.capacity_ elements, then copy
// other.size_ elements from other into it. Set size_/capacity_ to
// match other.
template <typename T>
MiniVector<T>::MiniVector(const MiniVector& other) {
  (void)other;             // placeholder -- remove once you use other
  data_ = nullptr;
  size_ = 0;
  capacity_ = 0;
}

// TODO (Task D): Copy-assignment operator.
// 1. If this == &other, return *this immediately (self-assignment guard).
// 2. Allocate a NEW array sized other.capacity_ -- do this BEFORE
//    touching this object's existing array, so that if allocation ever
//    fails, *this still has its original, valid data.
// 3. Copy other.size_ elements into the new array.
// 4. delete[] this object's old array.
// 5. Install the new pointer, and update size_/capacity_.
template <typename T>
MiniVector<T>& MiniVector<T>::operator=(const MiniVector& other) {
  (void)other;             // placeholder -- remove once you use other
  return *this;
}