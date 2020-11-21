#pragma once
#include <string>
#include <functional>
#include <queue>
#include <stack>

using namespace std;
typedef unsigned int uint;

enum class Priority {
    NUM,
    OPEN_BRACKET,
    CLOSE_BRACKET,
    ADD,
    MUL,
    POW,
    FUNC,
};

struct LexemStruct {
    Priority prior;
    uint argNum;
    bool rightAss = false;
    bool prefix = false;
};

class Lexem:protected LexemStruct {
public:
    Lexem(LexemStruct&& initStruct) :LexemStruct(initStruct) {};
    virtual double proceed(stack<double>& args) const = 0;
    Priority getPrior() const;
    bool isPrefix() const;
    bool isRightAss() const;
};

