<div align="center">

# Sorting Performance Lab

Benchmark bubble, insertion, and selection sort against different input shapes and plot the results.

[![CI](https://github.com/Abdelkrim7Be/Sorting_Performance_Mesuring/actions/workflows/ci.yml/badge.svg)](https://github.com/Abdelkrim7Be/Sorting_Performance_Mesuring/actions/workflows/ci.yml)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

![C](https://img.shields.io/badge/C-11-A8B9CC?style=for-the-badge&logo=c&logoColor=white)
![CMake](https://img.shields.io/badge/CMake-3.10%2B-064F8C?style=for-the-badge&logo=cmake&logoColor=white)
![gnuplot](https://img.shields.io/badge/gnuplot-plotting-5D9E48?style=for-the-badge)

</div>

## Overview

This project measures and compares the runtime of three classic sorting algorithms (bubble, insertion, selection) on arrays of growing size, under three input shapes: already ascending, fully descending, and alternating sign. It times each run, smooths the series, prints a results table, and renders a performance chart with gnuplot.

## Features

- Three sorting algorithms benchmarked side by side
- Three fill modes: ascending, descending, alternating positive/negative
- Timed runs across 10 array sizes (1000 to 10000, configurable)
- Simple moving-average smoothing on the timing series
- PNG chart output via gnuplot, no GUI required

## How it works

1. The user picks a fill mode at the prompt.
2. For each of 10 array sizes, a fresh array is allocated and filled, then each sort is timed with `clock()`.
3. The three timing series are smoothed with a 3-point moving average.
4. Results print to the terminal and are piped to gnuplot to produce `results.png`.

## Project structure

```
.
├── include/
│   ├── sorting_algorithms.h
│   ├── benchmark.h
│   └── plot.h
├── src/
│   ├── main.c
│   ├── sorting_algorithms.c
│   ├── benchmark.c
│   └── plot.c
├── CMakeLists.txt
└── .github/workflows/ci.yml
```

- `sorting_algorithms`: array fill + bubble/insertion/selection sort
- `benchmark`: timing and moving-average smoothing
- `plot`: gnuplot pipe, renders the PNG chart

## Build & run

Requires a C compiler, CMake, and gnuplot.

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
./build/sorting_performance
```

Pick a fill mode when prompted. The program prints a timing table and writes `results.png` in the working directory.

## Sample output

<div align="center">
<img src="docs/cli-output.png" alt="CLI output" width="700">
</div>

<div align="center">
<img src="docs/results.png" alt="Performance chart" width="700">
</div>

## License

MIT license. Full text in [LICENSE](LICENSE).
