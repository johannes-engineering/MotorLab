# Architecture Decisions

## ADR-001: Use C++20 as the C++ language standard

**Status:** Accepted

### Context

MotorLab needs a modern C++ baseline for numerical simulation and controller
development. The code should remain portable across development environments
and allow later reuse of controller logic on microcontrollers.

### Decision

Use C++20 as the required language standard for all C++ components.

### Rationale

C++20 provides modern language facilities sufficient for the current simulation
and controller requirements. It is chosen as the minimum standard to retain
compatibility with older toolchains rather than require C++23 without a
concrete project benefit.

C++23 is a viable alternative; no specific incompatibility has been identified
for MotorLab. This decision prioritizes a lower toolchain baseline over access
to newer features and can be revisited when those features offer a concrete
benefit.

### Consequences

- Contributors and build environments need a compiler and standard library that
support the C++20 features used by the project.
- C++23-only features are excluded until this decision is revisited for a
concrete requirement.
- Support for the features used must be verified on each target toolchain; C++
alone does not guarantee embedded portability.

## ADR-002: Use GoogleTest for C++ unit tests

**Status:** Accepted

### Context

MotorLab needs repeatable tests for the motor model and PID controller.
These tests exercise state across simulation steps, compare floating-point
results, and check how components handle invalid inputs.

### Decision

Use GoogleTest as the unit testing framework for C++ components. Register its
tests with CTest through CMake.

### Rationale

CTest is a proven industry standard for running tests in CMake-based C++ projects.

### Consequences

- The current CMake configuration requires a GoogleTest package compatible with
the selected C++ toolchain.
- C++ unit tests build into the `MotorLabTest` executable. CTest discovers new
cases in that executable without a separate list of test names.
