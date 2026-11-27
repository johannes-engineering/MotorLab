# Introduction and Goals
- create an app called "MotorLab" for simulating several types of electric motors
- implement control mechanisms that can later be ported to a microcontroller
- support motor, generator, and controller sizing
- easily extensible with respect to new motors and controllers
- user-friendly graphical configuration and chart-based evaluation

## Requirements Overview

The desktop application should support the following workflow.

1. **Configure and run a simulation.** Choose a motor model and its parameters, set the simulation duration and time step, and configure the controller for closed-loop runs.
2. **Evaluate results.** Plot quantities such as angular velocity over time, compare runs with different motor or controller parameters, and export results as CSV for further analysis.

The current example runs a fixed simulation of a PID-controlled DC motor and prints the results. The [use cases](03_context_and_scope.md#business-context) describe the intended user workflow, and the [roadmap](../../README.md#roadmap) tracks implementation progress.

## Quality Goals

The following priorities guide architectural decisions. The IDs refer to the
[quality requirements](10_quality_requirements.md#quality-requirements-overview).

| Quality goal | Why it matters for MotorLab |
| --- | --- |
| Numerical correctness ([Q4](10_quality_requirements.md)) | Users rely on simulated motor behavior when making sizing decisions. |
| Extensibility ([Q1](10_quality_requirements.md)) | Adding motor types is a recurring task for the sole developer. |
| Portability ([Q2](10_quality_requirements.md)) | Reusing the simulated controller on a future test bench allows the developer to compare its behavior in simulation and on hardware. |

## Stakeholders

| Role | Expectations |
|------|--------------|
| Developer | Can build and test MotorLab locally, add motor models and controllers independently, and reuse controller logic on a future microcontroller. |
| User | Can configure motors and controllers through the graphical interface, run simulations, and compare the results in charts to support sizing decisions. |
