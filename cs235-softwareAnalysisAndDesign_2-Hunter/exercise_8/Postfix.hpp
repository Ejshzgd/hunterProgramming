// Postfix.hpp
// CSCI 235 -- Exercise 8: Shunting-Yard Trace
// Provided file -- do not modify. Gradescope compiles your submission
// against the original version of this file.

#ifndef POSTFIX_HPP
#define POSTFIX_HPP

#include <queue>
#include <string>
#include <vector>

// Input assumptions for every function below (a VALID-INPUT exercise):
//   * numbers are nonnegative integers such as 7 or 120 (no decimals, no
//     unary minus);
//   * operators are the four binary operators + - * /;
//   * parentheses are balanced;
//   * "/" is real (floating-point) division: 7 / 2 is 3.5, as in Project 4.
// Project 4 will ask you to reject bad input; this exercise does not.
// The only empty-input case that is specified is tokenize() (see Task A);
// the other functions assume a nonempty, valid expression.

// Task A -- split text into tokens. A token is one whole number ("12"), or a
// single operator or parenthesis character. Spaces separate tokens but are
// never tokens themselves, and spaces are optional: "12+3" and "12 + 3"
// give the same tokens {"12", "+", "3"}. Skipping any whitespace character
// (std::isspace) is fine. tokenize("") and tokenize("   ") return an
// empty vector.
std::vector<std::string> tokenize(const std::string& text);

// Task B -- evaluate a postfix expression with a stack. The queue holds
// tokens in postfix order, for example 3 4 2 * +  (which is 11).
// For each operator, the value popped FIRST is the RIGHT operand.
// If an operator "/" would divide by zero (right operand == 0.0, an exact
// test), throw std::runtime_error.
// Values are doubles, so the result can have a fractional part.
double evalPostfix(std::queue<std::string> postfix);

// Task C -- convert infix tokens to postfix with the shunting-yard
// algorithm. All four operators are left-associative: * and / bind tighter
// than + and -, and an operator of EQUAL precedence already on the stack
// leaves first, so 8 - 3 - 2 becomes 8 3 - 2 - . Parentheses are never
// written to the output.
std::queue<std::string> toPostfix(const std::vector<std::string>& tokens);

// Task D -- evaluate infix text from start to finish by combining the three
// tasks above: tokenize, convert, then evaluate. A division by zero throws
// std::runtime_error, exactly as in Task B.
double evaluate(const std::string& text);

#endif