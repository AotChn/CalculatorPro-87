#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
#include <vector>
#include <iostream>

enum TOKEN_TYPES {INTEGER,
                  DOUBLE,
                  ALPHA,
                  FUNCTION,
                  DELIMITER,
                  OPERATOR,
                  LPAREN,
                  RPAREN,
                  COMP,
                  NON_TYPE};

enum TASKS {MULTIPLY=1,
            DIVIDE,
            SUBTRACT,
            ADD,
            EXPONENT};


enum FUNCTION_TYPES {TRIG,
                    MINUS,
                    HYPERBOLIC,
                    CONSANT,
                    LOGRITHMN,
                    VARIABLE=99};

enum TRIG_FUNCTS {SINE=1,
                  COSINE,
                  TANGENT,
                  ARCSIN,
                  ARCCOS,
                  ARCTRAN};

enum HYPERBOLIC_FUNCTS {SINH=7,
                        COSH,
                        TANH};

enum CONSTANT_FUNCTS {PI=10};

enum LOG_FUNCTS {LOG=11,
                 LN,
                 EXP};

static const std::vector<std::string> NUMERALS_ = {{"0"},{"1"},{"2"},{"3"},{"4"},{"5"},{"6"},{"7"},{"8"},{"9"}};
static const std::vector<std::string> OPERATORS_ = {{"^"},{"*"},{"/"},{"+"},{"%"},{"("},{")"}};
static const std::vector<std::string> ALPHAS_ = {{"a"},{"b"},{"c"},{"d"},{"e"},{"f"},{"g"},{"h"},{"i"},{"j"},{"k"},
                                     {"l"},{"m"},{"n"},{"o"},{"p"},{"q"},{"r"},{"s"},{"t"},{"u"},{"v"},
                                     {"w"},{"x"},{"y"},{"z"},{"A"},{"B"},{"C"},{"D"},{"E"},{"F"},{"G"},
                                     {"H"},{"I"},{"J"},{"K"},{"L"},{"M"},{"N"},{"O"},{"P"},{"Q"},{"R"},
                                     {"S"},{"T"},{"U"},{"V"},{"W"},{"X"},{"Y"},{"Z"}};

#endif // CONSTANTS_H



