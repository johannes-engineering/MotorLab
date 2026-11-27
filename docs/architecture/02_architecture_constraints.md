# Architecture Constraints

## Organizational Constraints

A single developer builds and maintains MotorLab. The effort required to
integrate, test, and maintain each additional component must fit that capacity.

## Technical Constraints

A standard Windows user must be able to run the simulator without administrator
privileges. Any files MotorLab writes during normal use, including simulation
results, must go to locations where that user has write access.

## Open Hardware Choice

Porting the controller logic to a microcontroller is a
[project goal](01_introduction_and_goals.md). The target is still open.
The ESP32 is one possible candidate.
