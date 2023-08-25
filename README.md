# Plotting prime numbers

Explore plotting prime numbers in polar coordinates. Inspired by:
https://www.youtube.com/watch?v=EK32jo7i5LQ

Uses plotting library matplotplusplus - https://github.com/alandefreitas/matplotplusplus

## Configure and build project

For linux:
```sh
mkdir build
cmake -S .. -B . -DCMAKE_CXX_COMPILER=clang++ -DWARNINGS=ON -DWARNINGS_AS_ERRORS=ON -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
cmake --build . -j12
```

### Runtime dependencies

Install gnuplot. For Fedora:
```sh
sudo dnf install -y gnuplot
```

### Formatting files

```sh
clang-format ../src/*.cpp -i
```