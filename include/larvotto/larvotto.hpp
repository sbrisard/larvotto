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
DllExport std::string author();

DllExport std::string version();

DllExport int return_one();

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

template <size_t DIM>
class SimulationBox {
 public:
  const std::array<double, DIM> L;

  typedef std::array<double, DIM> Vector;

  explicit SimulationBox(const Vector L) : L(L){};

  [[nodiscard]] std::string repr() const {
    std::ostringstream stream;
    stream << "SimulationBox<" << DIM
           << ">(L=" << larvotto::repr(L.cbegin(), L.cend()) << ")";
    return stream.str();
  }

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
