#include "Source.h"

Pi::Pi() :Lexem({Priority::NUM, 0, false, false}) {
}

double Pi::proceed(stack<double>& args) const {
    return 3.141592653589793;
}

Lexem* getLexem() {
    return new Pi();
}

const char* getName() {
    static const char* name = "pi";
    return name;
}

