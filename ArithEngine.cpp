#include "ArithEngine.h"

double ArithEngine::calculate(vector<shared_ptr<Lexem>>& lexems) {
    stack<double> numStack;
    stack<shared_ptr<Lexem>> operStack;
    for (uint i = 0; i < (uint)lexems.size(); i++) {
        shared_ptr<Lexem>& curLex = lexems[i];
        if (curLex->getPrior() == Priority::NUM) {
            numStack.push(curLex->proceed(numStack));
        }
        else if (operStack.empty() || curLex->isPrefix() || 
            curLex->getPrior() == Priority::OPEN_BRACKET) {
            operStack.push(curLex);
        }
        else if (curLex->getPrior() == Priority::CLOSE_BRACKET) {
            while (!operStack.empty()) {
                if (operStack.top()->getPrior() == Priority::OPEN_BRACKET) {
                    if (operStack.top()->proceed(numStack) != curLex->proceed(numStack)) {
                        throw "Mixed brackets";
                    }
                    operStack.pop();
                    break;
                }
                numStack.push(operStack.top()->proceed(numStack));
                operStack.pop();
            }
        }
        else {
            preCalc(curLex, numStack, operStack);
            operStack.push(curLex);
        }
    }
    while (!operStack.empty()) {
        numStack.push(operStack.top()->proceed(numStack));
        operStack.pop();
    }
    if (numStack.size() != 1) {
        throw "Not enough operators";
    }
    return numStack.top();
}

void ArithEngine::preCalc(shared_ptr<Lexem>& curLex, stack<double>& numStack, stack<shared_ptr<Lexem>>& operStack) {
    if (operStack.empty()) {
        throw "Not enough operators";
    }
    while (!operStack.empty() && operStack.top()->getPrior() >= curLex->getPrior()) {
        shared_ptr<Lexem>& lastLex = operStack.top();
        if (operStack.top()->getPrior() == curLex->getPrior() && curLex->isRightAss()) {
            break;
        }
        numStack.push(operStack.top()->proceed(numStack));
        operStack.pop();
    }
}

