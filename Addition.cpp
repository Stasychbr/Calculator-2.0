#include "Addition.h"

Addition::Addition() :Lexem({Priority::ADD, 2, false, false}) {
}

double Addition::proceed(stack<double>& args) const {
    if (args.size() < argNum) {
        throw "Not enough arguments";
    }
    double arg1, arg2;
    arg1 = args.top();
    args.pop();
    arg2 = args.top();
    args.pop();
    return arg1 + arg2;
}
