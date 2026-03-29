# Lab 03: Sorting Algorithms Project

This repository contains the implementation, benchmarking, and analysis of 12 classic sorting algorithms.  

This project is conducted by **Group 04** for the **Data Structures & Algorithms** course, class **25C11**, Faculty of Information Technology, University of Science (VNU-HCM).

GitHub: https://github.com/benalexx007/Sort

## Table of Contents
- [Project Overview](#project-overview)
- [Compilation Instructions](#compilation-instructions)
- [Usage & Commands](#usage--commands)
  - [Algorithm Mode (-a)](#1-algorithm-mode--a)
  - [Comparison Mode (-c)](#2-comparison-mode--c)
- [Evaluation Metrics](#evaluation-metrics)
- [File Structure](#file-structure)
- [Notes](#notes)

## Project Overview

The main goal of this project is to:
- Analyze execution time
- Count number of comparisons
- Evaluate performance across different input sizes and data distributions

### Implemented Algorithms
- `selection-sort`
- `insertion-sort`
- `binary-insertion-sort`
- `bubble-sort`
- `shaker-sort`
- `shell-sort`
- `heap-sort`
- `merge-sort`
- `quick-sort`
- `counting-sort`
- `radix-sort`
- `flash-sort`

### Data Arrangements (Input Orders)

| Flag | Description |
|------|-------------|
| `-rand` | Randomized data |
| `-sorted` | Sorted (ascending) |
| `-rev` | Reversed (descending) |
| `-nsorted` | Nearly sorted data |

## Evaluation Metrics

| Flag | Description |
|------|-------------|
| `-time` | Running time (milliseconds) |
| `-comp` | Number of comparisons |
| `-both` | Measure both time and comparisons |

## Compilation Instructions

This project uses only the GNU C++ Standard Library.  
No external dependencies are required.

### Stack Increasing Commands

To run benchmarks with massive stack required (such as `quick-sort` worst case on large input), it is necessary to increase local stack of the running system.

On Cmd: 
```bash
doskey g++=g++ -Wl,--stack,268435456 $*.
```

On PowerShell: 
```bash
function g++ { & g++.exe -Wl,--stack,268435456 $args }.
```

On Unix-style terminal: 
```bash
alias g++="g++ -Wl,--stack,268435456".
```

### Compile Command

We will use only this command to compile, as per the requirement of the project.

```bash
g++ *.cpp -std=c++17 -o 04.exe
````

**NOTE:** Some compilers cannot run this command properly. If that's the case, manually expand the `*.cpp` into a list of actual files or change to another compiler.

## Usage & Commands

The program supports two modes:

* Algorithm Mode (`-a`)
* Comparison Mode (`-c`)

## 1. Algorithm Mode (`-a`)

### Command 1: Run with input file

```bash
# Prototype
> 04.exe -a [Algorithm] [Input_file] [Output_parameter]

# Example
> 04.exe -a radix-sort input.txt -both
```

Output:

* Sorted result → `output.txt`

### Command 2: Run with generated data

```bash
# Prototype
> 04.exe -a [Algorithm] [Input_size] [Input_order] [Output_parameter]

# Example
> 04.exe -a selection-sort 50000 -rand -time
```

Output:

* Generated input → `input.txt`
* Sorted result → `output.txt`

### Command 3: Run on all input orders

```bash
# Prototype
> 04.exe -a [Algorithm] [Input_size] [Output_parameter]

# Example
> 04.exe -a quick-sort 70000 -comp
```

Output:

* `input_1.txt` → random
* `input_2.txt` → nearly sorted
* `input_3.txt` → sorted
* `input_4.txt` → reversed

## 2. Comparison Mode (`-c`)

### Command 4: Compare using input file

```bash
# Prototype
> 04.exe -c [Algorithm_1] [Algorithm_2] [Input_file]

# Example
> 04.exe -c heap-sort merge-sort input.txt
```

### Command 5: Compare using generated data

```bash
# Prototype
> 04.exe -c [Algorithm_1] [Algorithm_2] [Input_size] [Input_order]

# Example
> 04.exe -c quick-sort merge-sort 100000 -nsorted
```

Output:

* Generated input → `input.txt`

## File Structure

```text
.
├── README.md              # Project documentation
├── Report.pdf             # Report documentaion
└── source/                # Folder contains all codes
    ├── *.cpp              # Implementation
    ├── *.h                # Header files
    ├── input*.txt         # Generated input datasets
    └── output.txt         # Sorted output
```

## Notes

* All code is implemented from scratch.
* The program is designed for performance comparison and analysis.
* Ensure input files follow the correct format before execution.
* Large input sizes may require significant runtime.
