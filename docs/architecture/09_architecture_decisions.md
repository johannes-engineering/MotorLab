# Architecture Decisions

## ADR-001: Use C++20 as the C++ language standard

**Status:** Accepted

### Context

MotorLab needs a modern C++ baseline for numerical simulation and controller development. The code should remain portable across development environments and allow later reuse of controller logic on microcontrollers.

### Decision

Use C++20 as the required language standard for all C++ components.

### Rationale

C++20 provides modern language facilities sufficient for the current simulation and controller requirements. It is chosen as the minimum standard to retain compatibility with older toolchains rather than require C++23 without a concrete project benefit.

C++23 is a viable alternative; no specific incompatibility has been identified for MotorLab. This decision prioritizes a lower toolchain baseline over access to newer features and can be revisited when those features offer a concrete benefit.

### Consequences

- Contributors and build environments need a compiler and standard library that support the C++20 features used by the project.
- C++23-only features are excluded until this decision is revisited for a concrete requirement.
- Support for the features used must be verified on each target toolchain; C++20 alone does not guarantee embedded portability.
