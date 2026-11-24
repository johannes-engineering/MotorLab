# MotorLab
**Status: Work in Progress**

A modular simulation and control platform for electric motor systems, developed using C++ and Python.

The project explores numerical simulation, motor control algorithms, software architecture, and the integration of Python-based graphical interfaces with C++ simulation applications.

A long-term objective is to enable the control of a physical motor and the comparison of experimental measurements with simulation results to evaluate and validate the developed models and control algorithms.

## Features
- C++ simulation engine for electric motor models
- Motor control algorithms

Planned:
- Python GUI for simulation configuration and results visualization
- CSV-based simulation data exchange
- SQLite database for motor parameter management
- Simulation results visualization and analysis

## Technology Stack
- **C++20 / CMake:** Simulation engine and build system
- **Mermaid / arc42:** Software architecture documentation
- **Git:** Versioning

Planned:
- **Python:** GUI, simulation orchestration and data analysis
- **SQLite / SQL:** Motor parameter persistence
- **GitHub Actions:** Continuous integration, automated builds and testing

## Project Status
This project is under active development. Features and architectural decisions may change as development progresses.

See the project roadmap and commit history for development progress.

## Getting Started

MotorLab requires CMake 3.23 or newer, a C++20 toolchain, and GoogleTest.
The test runner, CTest, is included with CMake. CMake looks for GoogleTest
during configuration. If you use vcpkg, install the `gtest` package for your
target triplet and configure CMake with the vcpkg toolchain file.

From the repository root, configure the project and build the default target:

```sh
cmake -S cpp -B build
cmake --build build
```

Run `MotorLab` (`MotorLab.exe` on Windows) from `build/` or its configuration subdirectory, such as `build/Debug/`.

The example simulates two seconds of PID-controlled DC motor operation and prints the angular acceleration, velocity, and position at each millisecond. Press Enter after the final sample to exit.

## Roadmap
- [x] Create a first version of the software architecture documentation
- [x] Implement a first electric motor model in C++
- [x] Implement a first control algorithm (PID) in C++
- [x] Create first tests for the existing components
- [ ] Introduce a simulation layer between the application entry point and the motor model/controllers
- [ ] Export simulation results as CSV
- [ ] Define and implement the C++ CLI (JSON parameter)
- [ ] Add a Python interface for configuration and visualization
- [ ] Add SQLite-based motor parameter management
- [ ] Extend the simulation to additional motor types
- [ ] Extend and improve the control algorithms

## Further Documentation
- [Software Architecture](docs/architecture/)
