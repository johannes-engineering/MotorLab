# Context and Scope

## Business Context

**\<Diagram or Table\>**

**\<optionally: Explanation of external domain interfaces\>**

## Technical Context
```mermaid
flowchart LR
user["User"]

subgraph border["System"]
    app["MotorLab"]
end

user -->|"inputs / actions"| app
app -->|"outputs / results"| user
style border fill:none,stroke:#777,stroke-dasharray:5 5
```

**\<Diagram or Table\>**

**\<optionally: Explanation of technical interfaces\>**

**\<Mapping Input/Output to Channels\>**
