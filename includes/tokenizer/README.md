tokenizer.ver3 logic 

OVERVIEW: fsm which takes in string input and then converts to infix tokens to be processed in a shunting yard class to convert to postfix-

start at s0 and then transions to according state until arriving at an accepting state-

once arriving at accepting state will pkg tokens in a wrapper (tk_data) to be sent to according class to create token-

implemented is an invalid state to process invalid inputs from user- since states are their own function we are able to add additional states by defining another function-

each state is mapped to a corresponding int and is stored as a function pointer which then will point to a sequence of event states eventually leading to accepting state-

encapsulating function can be called recursively to handle composite functions-
(in this process we will inject another string to tokenize in the middle of the main process) we are able to do this because tokens are getting pushed to the infix queue char by char instead of all at once;

we can also set a pre-infix and add on to it (store answer functionality?) this is my 3rd tokenizer iteration;

THE ID SYSTEM : all tokens will have an associative id which will correspond to their functionality though not particularly important to numerical it can serve as a way to map operations ids are int values and we can categorize functions by id i.e.

functions in 100-150 could be functions that take in 2 arguments while functions in 151-200 range can take in 2 arguments etc. this could eliminate the precedence system and even allow us to handle same name functions with different functions ie '-' operator vs '-' unary operator