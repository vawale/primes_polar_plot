# Plotting prime numbers

Explore plotting prime numbers in polar coordinates. Inspired by:
[Why do prime numbers make these spirals?](https://www.youtube.com/watch?v=EK32jo7i5LQ) and concept of primes as figure or ground introduced in [Godel, Escher, and Bach](https://www.google.no/books/edition/G%C3%B6del_Escher_Bach/grzEQgAACAAJ?hl=en).

Uses plotting library [matplotplusplus](https://github.com/alandefreitas/matplotplusplus).

## Setup requirements

* CMake version 3.20 or higher
* C++ compiler that supports C++20
* clang-format for formatting files

## Configure and build project

Example using clang++ compiler. Replace `clang++` with `g++` if using gcc.

```sh
mkdir build
cmake -S .. -B . -DCMAKE_CXX_COMPILER=clang++ -DWARNINGS=ON -DWARNINGS_AS_ERRORS=ON -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
cmake --build . -j12
```

### Buildtime dependencies

Needs [matplotplusplus](https://github.com/alandefreitas/matplotplusplus) library for build. The latest master branch of matplotplusplus is downloaded and built as part of cmake project.

### Runtime dependencies

Install gnuplot. For Fedora:
```sh
sudo dnf install -y gnuplot
```

### Formatting files

```sh
clang-format ../src/*.hpp -i
clang-format ../src/*.cpp -i
```

## Example plot

Polar plot of points (x,x) of all natural numbers x between 1-10000:
![alt text](https://github.com/vawale/primes_polar_plot/blob/master/examples/natural_numbers.svg?raw=true)

Polar plot of points (x,x) of all prime numbers x between 1-10000:
![alt text](https://github.com/vawale/primes_polar_plot/blob/master/examples/prime_numbers.svg?raw=true)
