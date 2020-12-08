#include <cstddef>

#include "coordinate.cpp"

// Macro to define YOUR_STORAGE_TYPE
#define YOUR_STORAGE_TYPE storage

// !! ATTENTION !!//
// Copy your code from Part 1 AND Part 3 here!
// !! ATTENTION !!//

// The storage class represents a "square matrix" of
// arbitrary objects (the template argument T)
// Each element in the square matrix
// corresponds to a point2d. So the element in the ith-row
// and j-th column is associated to the point2d{i, j}
// We need to be able to resize the matrix, access/modify its elements
// and check for a given point whether or not it is within the matrix.
// Attention the following code is incomplete. You are not allowed
// to change the given signature but you can add member functions and variables
// to the class as you see fit

// Make it a template class
// todo
class storage
{
public:
  storage() = delete;
  // n is expected to be the total number of elements,
  // not the number of rows/cols
  // If n != (std::sqrt(n))*(std::sqrt(n))
  // a runtime_error has to be thrown
  explicit storage(size_t n);
  // todo
  storage(const storage &other) = default;
  storage &operator=(const storage &other) = default;

  // Accessing a point outside of the
  // storage has to throw an exception
  // Use operator() to acces elements
  // We need a const and a non-const version
  // todo

  coord max_coord() const;
  // todo

  // Check if a given point exists within this representation
  bool has_point(const point2d &p) const;
  // todo

  // This function should RESERVE (like the function for std::vector)
  // at least n elements (and verify that it is still a square matrix)
  void reserve(unsigned n);
  // todo

  // This function should RESIZE (like the function for std::vector)
  // the storage to hold at least n elements
  // (and verify that it is still a square matrix)
  void resize(unsigned n);
  // todo

  // Convenience accessor
  YOUR_STORAGE_TYPE &get_storage();
  // todo

protected:
  // todo
};
