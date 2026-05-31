#include "calc.h"

#include <cstdio>
#include <string>

// Non-Apple command-line front end for calc_lib. Joins the args into a single
// expression, evaluates it, and prints the result. With no args it reads one
// expression per line from stdin.
static int evaluate(const std::string& expr) {
    double result = calc_evaluate(expr.c_str());
    std::printf("%g\n", result);
    return 0;
}

int main(int argc, char** argv) {
    if (argc > 1) {
        std::string expr;
        for (int i = 1; i < argc; ++i) {
            if (i > 1) expr += ' ';
            expr += argv[i];
        }
        return evaluate(expr);
    }

    std::string line;
    int c;
    while ((c = std::getchar()) != EOF) {
        if (c == '\n') {
            evaluate(line);
            line.clear();
        } else {
            line += static_cast<char>(c);
        }
    }
    if (!line.empty()) evaluate(line);
    return 0;
}
