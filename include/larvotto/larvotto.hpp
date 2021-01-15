#pragma once

#if _WIN32
#define DllExport __declspec(dllexport)
#else
#define DllExport
#endif

#include <algorithm>
#include <array>
#include <sstream>
#include <string>

namespace larvotto {
/** Return the author of the larvotto library. */
std::string author();

/** Return the version of the larvotto library. */
std::string version();

/** Return 1. */
int return_one();

/**
 * Convert an iterator to a string.
 *
 * The string is delimited by square brackets. The elements are separated by a
 * comma.
 */
template <class Iterator>
std::string repr(Iterator begin, Iterator end) {
  std::ostringstream stream;
  stream << "[";
  for (auto i = begin; i < end; i++) {
    stream << *i;
    if (i < end - 1) {
      stream << ",";
    }
  }
  stream << "]";
  return stream.str();
}

/**
 * This class defines a simulation box.
 *
 * @tparam DIM The number of spatial dimensions
 */
template <size_t DIM>
class SimulationBox {
 public:
  /** Dimensions of the box. */
  const std::array<double, DIM> L;

  /** Default type for a spatial vector. */
  typedef std::array<double, DIM> Vector;

  /** Create a new instance with specified dimensions. */
  explicit SimulationBox(const Vector L) : L(L){};

  /** Return a representation of this object as a string. */
  [[nodiscard]] std::string repr() const {
    std::ostringstream stream;
    stream << "SimulationBox<" << DIM
           << ">(L=" << larvotto::repr(L.cbegin(), L.cend()) << ")";
    return stream.str();
  }

  /**
   * Return the minimum image `r` of the difference `r₀ = y - x`.
   *
   * This vector is defined as follows
   * @code
   * rᵢ = r₀ᵢ + nᵢ × Lᵢ,
   * @endcode
   * where
   * @code
   * nᵢ = arg min {|r₀ᵢ + m × Lᵢ|, m = …, -2, -1, 0, 1, 2, …}.
   * @endcode
   */
  Vector minimum_image(const Vector x, const Vector y) const {
    Vector r{};
    for (auto i = 0; i < DIM; i++) {
      r[i] = y[i] - x[i];
      if (2 * r[i] > L[i]) {
        r[i] -= L[i];
      }
      if (2 * r[i] < -L[i]) {
        r[i] += L[i];
      }
    }
    return r;
  }
};

template <size_t DIM>
std::ostream& operator<<(std::ostream& os, const SimulationBox<DIM> box) {
  return os << box.repr();
}
}  // namespace larvotto
