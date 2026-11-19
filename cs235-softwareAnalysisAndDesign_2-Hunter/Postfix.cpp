
#include "Postfix.hpp"

#include <cctype>
#include <cstddef>
#include <stack>
#include <stdexcept>

// ---- Provided helpers ----
static bool isOp(const std::string& t) {
    return t == "+" || t == "-" || t == "*" || t == "/";
}

static int prec(const std::string& op) {
    if (op == "*" || op == "/") { return 2; }
    return 1;
}

// Task A
std::vector<std::string> tokenize(const std::string& text) {
    std::vector<std::string> tokens;

    for (int i = 0; i < text.length(); i++)
    {
        char t = text.at(i);

        if (t == '(' || t == ')' || t == '+' ||
            t == '-' || t == '*' || t == '/')
        {
            tokens.push_back(std::string(1, t));
        }
        else if (isdigit(t))
        {
            std::string s;

            while (i < text.length() && isdigit(text.at(i)))
            {
                s += text.at(i);
                i++;
            }

            i--;
            tokens.push_back(s);
        }
    }

    return tokens;
}

// Task B
double evalPostfix(std::queue<std::string> postfix) {
    std::stack<double> s;

    while (!postfix.empty())
    {
        std::string text = postfix.front();
        postfix.pop();

        if (!text.empty() && isdigit(text[0]))
        {
            double num = std::stod(text);
            s.push(num);
        }
        else if (isOp(text))
        {
            double right = s.top();
            s.pop();

            double left = s.top();
            s.pop();

            switch (text[0])
            {
                case '+':
                    s.push(left + right);
                    break;

                case '-':
                    s.push(left - right);
                    break;

                case '*':
                    s.push(left * right);
                    break;

                case '/':
                    if (right == 0.0)
                    {
                        throw std::runtime_error("division by zero");
                    }
                    s.push(left / right);
                    break;
            }
        }
    }

    return s.top();
}

// Task C
std::queue<std::string> toPostfix(
    const std::vector<std::string>& tokens) {

    std::queue<std::string> output;
    std::stack<std::string> operators;

    for (int i = 0; i < tokens.size(); i++)
    {
        if (!tokens[i].empty() && isdigit(tokens[i][0]))
        {
            output.push(tokens[i]);
        }
        else if (tokens[i] == "(")
        {
            operators.push(tokens[i]);
        }
        else if (tokens[i] == ")")
        {
            while (!operators.empty() && operators.top() != "(")
            {
                output.push(operators.top());
                operators.pop();
            }

            if (!operators.empty())
            {
                operators.pop();
            }
        }
        else if (isOp(tokens[i]))
        {
            while (!operators.empty() &&
                   operators.top() != "(" &&
                   prec(operators.top()) >= prec(tokens[i]))
            {
                output.push(operators.top());
                operators.pop();
            }

            operators.push(tokens[i]);
        }
    }

    while (!operators.empty())
    {
        output.push(operators.top());
        operators.pop();
    }

    return output;
}

// Task D
double evaluate(const std::string& text) {
    std::vector<std::string> s = tokenize(text);
    std::queue<std::string> q = toPostfix(s);

    return evalPostfix(q);
}
