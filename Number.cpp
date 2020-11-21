#include "Number.h"

Number::Number(double value) :Lexem({ Priority::NUM, 0, false, false }) {
    _val = value;
}
double Number::proceed(stack<double>& args) const {
    return _val;
}
;