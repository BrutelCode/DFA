## Deterministic Finite Automaton

**Before you run the 'dfa_prog.c'**

1) Change the file path in "DFA prog.c" (line '28') and redirect to your own "DFA.text" file.

2) Compile and Run

3) Give the Input and take the Results

### Description dfa.text file
3      // The DFA has 3 states

0 1    // The alphabet has 2 symbols, 0 and 1

0      // Initial state is q0

0 1    // Final state is q0 and q1

0 1 1  // If the automatic is in state q0, with 1 it will go to state q1

0 0 0  // If the automatic is in state q0, with 0 it will go to state q0

1 1 2  // If the automatic is in state q1, with 1 it will go to state q2

1 0 0  // If the automatic is in state q1, with 0 it will go to state q0

2 1 2  // If the automatic is in state q2, with 1 it will go to state q2

2 0 2  // If the automatic is in state q2, with 0 it will go to state q2
