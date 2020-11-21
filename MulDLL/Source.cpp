#include "Source.h"

Multiplication::Multiplication() :Lexem({Priority::MUL, 2, false, false}) {
}

double Multiplication::proceed(stack<double>& args) const {
    double arg1, arg2;
    arg1 = args.top();
    args.pop();
    arg2 = args.top();
    args.pop();
    return arg1 * arg2;
}

Lexem* getLexem() {
    return new Multiplication();
}

const char* getName() {
    static const char* name = "*";
    return name;
}

