# Building Block View

## Whitebox Overall System

```mermaid
flowchart LR
user["User"]

subgraph border["System"]
    subgraph python["Python App"]
        view["GUI"]
        presenter["Presenter"]
        motorRepo["Motor Repository"]
        db[("SQLite Database")]
    end

    subgraph cpp["C++ App"]
        sim["Motor Simulation"]
    end
end

user --> view
view --> user
view --> presenter
presenter --> view
presenter --> motorRepo
presenter -->|"CLI"| sim
sim -->|"console output / .csv file"| presenter
motorRepo --> db

style border fill:none,stroke:#777,stroke-dasharray:5 5
style python fill:none,stroke:#777,stroke-dasharray:5 5
style cpp fill:none,stroke:#777,stroke-dasharray:5 5
```
**Motivation**

**Contained Building Blocks**

| Name | Responsibility |
| --- | --- |
| GUI | Collect user input and display simulation settings and results. |
| Presenter | Coordinate GUI interactions, motor parameter access, simulation execution, and result preparation. |
| Motor Repository | Provide access to stored motor parameters and encapsulate database operations. |
| SQLite Database | Persist motor parameters locally. |
| Motor Simulation | Execute motor simulations with control algorithms and provide results through console output and CSV files. |

**Important Interfaces**

| Name | Responsibility |
| --- | --- |
| GUI–User | Allow the user to configure simulations, manage motor parameters, and view simulation results. |
| Motor Simulation CLI | Accept simulation configuration as JSON and start simulation execution. |
| Motor Simulation Console Output | Provide execution status and diagnostic messages monitored by the presenter. |
| Motor Simulation Result Export | Transfer simulation results from the C++ application to the Python application as CSV files. |


## Level 2

### Whitebox Motor Simulation
```mermaid
flowchart LR
presenter["Presenter"]

subgraph sim["Motor Simulation"]
    cli["CLI"]
    simEnv["Simulation"]
    motorFactory["Motor Factory"]
    settings["Simulation Settings"]
    control["Motor Control"]
    motorModel["Motor Model"]
    results["Simulation Results"]
    exporter["Result Exporter"]
    maths["Mathematics"]
end

presenter --> cli
cli --> presenter
cli --> simEnv
cli --> motorFactory
cli --> settings
cli --> exporter
simEnv --> settings
simEnv --> control
simEnv --> motorModel
simEnv --> results
motorFactory --> motorModel
control --> maths
motorModel --> maths
exporter --> results
exporter -.->|".csv file"| presenter

style sim fill:none,stroke:#777,stroke-dasharray:5 5
```

## Level 3

### Whitebox Motor Model
```mermaid
classDiagram
direction TB

    class Motor {
        <<abstract>>
        #double acceleration_rad_s2
        #double velocity_rad_s
        #double position_rad
        +initialize() void
        +step(double dt) void*
        +getTorque() double*
        +getSpeed() double
    }

    class DCMotor {
        -double resistance
        -double inductance
        -double torqueConstant
        +step(double dt) void
        +getTorque() double
    }

    class BLDCMotor {
        -double phaseResistance
        -double phaseInductance
        -int polePairs
        +step(double dt) void
        +getTorque() double
    }

    Motor <|-- DCMotor
    Motor <|-- BLDCMotor
```
