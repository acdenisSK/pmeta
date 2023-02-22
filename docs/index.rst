Introduction
============

`pmeta` is a header-only library for the preprocessor used by the C and C++ languages.

It defines several macros useful for situations like conditional compilation,
where an entity is compiled only under certain conditions. This can range from
the target platform (Windows, MacOS, Linux, \*BSD, etc.), the compiler
(Microsoft `cl.exe`, GNU `g++`, LLVM `clang++`, etc.), the language standard
(C++11, C++14, C++17, C++20, etc.), and more.

Additionally, it provides attribute-like macros for portability. These are
useful when applying compiler-specific or standard-specific attributes only in
cases where they are supported. When programming in C++, for instance, marking a
function as `constexpr` only when compiling with standards C++17 and above,
otherwise marking the function as `inline`.

Indices and tables
==================

* :ref:`genindex`
* :ref:`search`

Table of Contents
^^^^^^^^^^^^^^^^^

.. toctree::
   :maxdepth: 2

   self
   api/index
   license
