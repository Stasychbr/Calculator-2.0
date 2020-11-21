#include "Source.h"

Sin::Sin() :Lexem({Priority::FUNC, 1, false, true}) {
}

double Sin::proceed(stack<double>& args) const {
    if (args.empty()) {
        throw "Not enough arguments";
    }
    double arg = args.top();
    args.pop();
    return sin(arg);
}

Lexem* getLexem() {
    return new Sin();
}

const char* getName() {
    static const char* name = "sin";
    return name;
}