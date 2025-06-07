# C++ Utility Function Toolkit

A simple C++ project showcasing a collection of utility functions. This project is configured with CMake for building and Google Test for unit testing.

It serves as a starting point and a reference for creating robust, testable C++ applications.

## Features

- Modern C++ (C++17)
- CMake-based build system
- Integrated with Google Test for unit testing
- Example of a simple utility function (`add`)
- Example of a multi-dimensional vector printing utility

## Prerequisites

- C++17 compatible compiler (e.g., Clang, GCC)
- CMake (version 3.14 or higher)
- Git

## How to Build and Run

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/prettydong/cppLearning.git
    cd cppLearning
    ```

2.  **Create a build directory:**
    This project follows an out-of-source build approach.
    ```bash
    mkdir build
    cd build
    ```

3.  **Configure with CMake:**
    ```bash
    cmake ..
    ```

4.  **Build the project:**
    This will compile both the main application and the test suite.
    ```bash
    make
    ```

5.  **Run the application:**
    The main executable (`HelloWorld`) will be located in the `build` directory.
    ```bash
    ./HelloWorld
    ```

## How to Run Tests

The project uses Google Test for unit testing.

1.  **Build the project** (if you haven't already) following the steps above.

2.  **Run the tests using CTest:**
    From the `build` directory, run:
    ```bash
    ctest --verbose
    ```

## Project Structure

```
.
├── .gitignore          # Files and directories to be ignored by Git
├── CMakeLists.txt      # The main CMake configuration file
├── README.md           # This file
├── build/              # (Generated) All build artifacts
├── src/                # Source code
│   ├── main.cpp
│   └── math.hpp
└── test/               # Unit tests
    └── math_test.cpp
``` 