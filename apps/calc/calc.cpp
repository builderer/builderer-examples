#include "calc.h"

#include <cctype>
#include <cmath>
#include <cstdlib>

// Recursive-descent expression evaluator. Grammar:
//   expr   = term (('+' | '-') term)*
//   term   = factor (('*' | '/') factor)*
//   factor = number | '(' expr ')' | ('-' | '+') factor
//   number = digits ('.' digits)?  (parsed by strtod)

namespace {

struct Parser {
    const char* p;
    bool error = false;

    void skip_ws() {
        while (*p && std::isspace(static_cast<unsigned char>(*p))) ++p;
    }

    double parse_number() {
        char* end = nullptr;
        double v = std::strtod(p, &end);
        if (end == p) { error = true; return 0.0; }
        p = end;
        return v;
    }

    double parse_factor() {
        skip_ws();
        if (*p == '(') {
            ++p;
            double v = parse_expr();
            skip_ws();
            if (*p == ')') ++p; else error = true;
            return v;
        }
        if (*p == '-') { ++p; return -parse_factor(); }
        if (*p == '+') { ++p; return  parse_factor(); }
        return parse_number();
    }

    double parse_term() {
        double v = parse_factor();
        while (!error) {
            skip_ws();
            char op = *p;
            if (op != '*' && op != '/') break;
            ++p;
            double rhs = parse_factor();
            v = (op == '*') ? v * rhs : v / rhs;
        }
        return v;
    }

    double parse_expr() {
        double v = parse_term();
        while (!error) {
            skip_ws();
            char op = *p;
            if (op != '+' && op != '-') break;
            ++p;
            double rhs = parse_term();
            v = (op == '+') ? v + rhs : v - rhs;
        }
        return v;
    }
};

}  // namespace

double calc_evaluate(const char* expr) {
    if (!expr) return NAN;
    Parser parser{expr};
    double result = parser.parse_expr();
    parser.skip_ws();
    if (parser.error || *parser.p != '\0') return NAN;
    return result;
}
