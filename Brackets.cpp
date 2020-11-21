#include "Brackets.h"

OpenBracket::OpenBracket(double id):Lexem({ Priority::OPEN_BRACKET, 0, false, false }) {
    _id = id;
}

double OpenBracket::proceed(stack<double>& args) const {
    return _id;
}

CloseBracket::CloseBracket(double id) :Lexem({ Priority::CLOSE_BRACKET, 0, false, false }) {
    _id = id;
}

double CloseBracket::proceed(stack<double>& args) const {
    return _id;
}