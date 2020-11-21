#include "ExprParser.h"
#include <sstream>

vector<shared_ptr<Lexem>> ExprParser::parseLexems(string& expression) {
    vector<shared_ptr<Lexem>> lexems;
    while (!expression.empty()) {
        lexems.push_back(getLexem(expression));
    }
    return lexems;
}
