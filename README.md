# PDA and CFG Project

## Members
- Samuel Herrera Galvis
- Emmanuel Alvarez Castrillon

## Student’s Class Number
SI2002-2 (7309)

## Development Environment
- **Operating System:** Windows 10 x64bits
- **Programming Language:** C++
- **IDE:** Visual Studio Code

## Running Instructions
### Context-Free Grammar Processing with C++
This repository contains the implementation of three C++ algorithms that work together to generate, recognize, and analyze strings based on the context-free grammar:
S → aSb | ε
Each algorithm plays a distinct role in processing the strings, and their correct execution depends on following the sequence outlined in the instructions below.

### Installation and Execution
#### Prerequisites
Ensure you have:

A C++ compiler (e.g., g++)

A terminal or command prompt to execute the compiled files

#### Compilation
Run the following commands in your terminal to compile the three algorithms:

g++ -o algorithm1 ALGORITHM_1_7309_2025_SHGEAC.cpp
g++ -o algorithm2 ALGORITHM_2_7309_2025_SHGEAC.cpp
g++ -o algorithm3 ALGORITHM_3_7309_2025_SHGEAC.cpp

#### Execution Order
The three algorithms must be executed in sequence:

1. Generate valid and invalid strings
./algorithm1
This will create a file cadenas_generadas.txt containing a mix of valid and invalid strings.

2. Recognize valid strings using a Pushdown Automaton (PDA)
./algorithm2
This will read cadenas_generadas.txt and write the recognized valid strings to cadenas_aceptadas.txt.

3. Perform leftmost derivation analysis
./algorithm3
This will analyze the strings stored in cadenas_aceptadas.txt, showing their derivations according to the grammar.

## Algorithm Descriptions
### Algorithm 1: String Generation
- Generates valid strings following the grammar S → aSb | ε.
- Generates invalid strings that contain a and b but do not follow the correct structure.
- The output is stored in cadenas_generadas.txt.

### Algorithm 2: Pushdown Automaton (PDA) Recognition
- Reads cadenas_generadas.txt and checks if each string is valid using a PDA.
- If a string follows the grammar rules, it is written to cadenas_aceptadas.txt.
- Uses a stack to ensure the number of as matches the number of bs in the correct order.

### Algorithm 3: Leftmost Derivation
- Reads cadenas_aceptadas.txt and reconstructs how each string was derived using leftmost derivation.
- Displays step-by-step transformations from S to the final string.

## Example Execution
### Algorithm 1 Output (cadenas_generadas.txt)
aabb
abb
aaabbb
baa

### Algorithm 2 Output (cadenas_aceptadas.txt)
aabb
aaabbb

### Algorithm 3 Output (Derivation Process)
Sentential forms in a leftmost derivation of "aabb" in G:
S
aSb
aaSbb
ε
Accepted string: "aabb"
This project demonstrates the interaction between formal grammars, pushdown automata, and derivation analysis in a structured way.
