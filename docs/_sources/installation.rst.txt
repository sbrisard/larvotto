************
Installation
************


Installing the C++ library
==========================

This is a CMake_ based project. The installation procedure is standard. First,
clone the repository. Then, ``cd`` into the root directory of the
larvotto project. Let
``larvotto_INSTALL_PREFIX`` be the path to the directory
where larvotto should be installed::

  $ git clone https://github.com/sbrisard/larvotto
  $ cd larvotto
  $ mkdir build
  $ cd build
  $ cmake -DCMAKE_INSTALL_PREFIX=larvotto_INSTALL_PREFIX ..
  $ cmake --build . --config Release
  $ cmake --install . --config Release

.. note:: The ``--config`` option might not be available, depending on the
   selected generator.

At this point, larvotto should be installed. You can now
run the tests::

  $ ctest . -C Release

.. note:: Depending on the system, you might need to add
   ``larvotto_INSTALL_PREFIX`` to your ``PATH`` environment
   variable.


Compiling your first larvotto program
=====================================

``cd`` into the ``example`` subdirectory. The provided example program should be
compiled and linked against larvotto::

  $ mkdir build
  $ cd build
  $ cmake -Dlarvotto_DIR=larvotto_INSTALL_PREFIX/lib/cmake/larvotto ..
  $ cmake --build . --config Release

An executable called ``example_larvotto`` should be present
in the ``build/Release`` subdirectory.


Building the documentation
==========================

The documentation of larvotto requires Sphinx_. The C++ API
docs are built with Doxygen_ and the Breathe_ extension to Sphinx_.

To build the HTML version of the docs in the ``public`` subdirectory::

  $ cd sphinx
  $ sphinx-build -b html . ../docs

To build the LaTeX version of the docs::

  $ cd sphinx
  $ make latex


Installing the Python bindings
==============================

To install the larvotto module, ``cd`` into the
``python`` subdirectory and edit the ``setup.cfg`` file. Set the ``include_dir``
and ``library_dir`` to the appropriate paths. These should be::

  [larvotto]
  include_dir = ${CMAKE_INSTALL_PREFIX}/include
  library_dir = ${CMAKE_INSTLAL_PREFIX}/lib

Then, issue the following command::

  $ python setup.py install --user

or (if you intend to edit the project)::

  $ python setup.py develop --user

To run the tests with Pytest_::

  $ python -m pytest tests

.. _Breathe: https://breathe.readthedocs.io/
.. _CMake: https://cmake.org/
.. _Doxygen: https://www.doxygen.nl/
.. _Pytest: https://docs.pytest.org/
.. _Sphinx: https://www.sphinx-doc.org/
