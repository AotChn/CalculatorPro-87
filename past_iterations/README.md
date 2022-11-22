IN THIS FOLDER CONTAINS PAST ITERATIONS OF VARIOUS COMPONENTS OF THE CALCULATOR 
Outlined below are brief explanations why those iterations fell short

--------------------------------------------------------------------------------
[ tk_string.cpp + tk_string.h ]

Purpose: 
Convert string input to tokenized infix {1st try}

Design:
-purpose separated into 3 main processes 
to filter types and edge cases; Each case represented as a switch;

Status:
-Compiles 
-Completes main functionality 
-Does not handle composite functions 
-Does not handle multiple calls of same functions i.e (sinx + sinx)

Problems:
-Code was very messy with no structure;
-Very hard to implement new cases as they would interfere with existing cases;
(does not scale well)
-Too many variables to keep track of;
-Each function does too much;
-Each function passes too many variables;

What I learned:
-First function to implement recursion (able to handle composite functions);
-Large switch statements presents scaleability problems;
-Found a way to introduce user stored functions (by txt file);
-Gained a better understanding of how to filter char into tokens

--------------------------------------------------------------------------------
[tokenizerV2.cpp + tokenizerV2.h ]

Purpose: 
Convert string input to tokenized infix {2nd try}

Design: 
-FSM where each state is a type; state map represented by 2d array;

Status:
-Does not compile

Problems:
-Unsure best way to traverse the 2d array
-Method for obtaining some states were not consistent with other states
i.e some used char and others used strings 
-Utilized a static arrays which left wasted memory with shorter state paths
-Did not know how to iterate string

What I learned:
-First class to implement FSM design
-First class to implement function pointers
-FSM allows for better scalability
-Having multiple functions reduced large switch statements 
-Each state is independent of unnecessary conditions m
-In theory less checks as programs do not check all conditions 
only conditions relevant to current state
-Approach has less variables to pass
-Realized we need a standardized passing variable for FSM

--------------------------------------------------------------------------------