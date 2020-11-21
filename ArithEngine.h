#pragma once
#include "Lexem.h"
#include <stack>
#include <memory>

class ArithEngine {
private:
    double _lastBracketID = 0;
    void preCalc(shared_ptr<Lexem>& curLex, stack<double>& numStack, stack<shared_ptr<Lexem>>& operStack);
public:
    double calculate(vector<shared_ptr<Lexem>>& lexems);
};

