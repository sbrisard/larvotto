#include <pybind11/pybind11.h>

#include "larvotto/larvotto.hpp"

PYBIND11_MODULE(larvotto, m) {
  m.doc() = "Python bindings to the larvotto library";
  m.attr("__author__") = pybind11::cast(larvotto::author());
  m.attr("__version__") = pybind11::cast(larvotto::version());
  m.def("return_one", &larvotto::return_one, "Return one in all circumstances.");
}
