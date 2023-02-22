[![docs-badge][]][docs]

# pmeta

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

## Documentation

There is [online documentation built][docs] from the latest commit from the
`master` branch. If you want a local copy of the documentation, you will need:

- Doxygen
- Sphinx
- Furo theme
- Python3 (for Sphinx and Furo)

You will also have to run CMake with the `PMETA_BUILD_DOCS` option enabled:

```
$ cmake ... -DPMETA_BUILD_DOCS=ON
```

You can then build the docs with:

```
$ cmake --build <builddir> --target sphinx
```

The generated documentation can be then found in `<builddir>/docs/sphinx`, which
can be opened in a web browser.

## License

This project is under the jurisdiction of the [Boost Software License](LICENSE).

[docs]: https://acdenissk.github.io/pmeta/
[docs-badge]: https://img.shields.io/badge/docs-online-5023dd.svg?style=flat-square
