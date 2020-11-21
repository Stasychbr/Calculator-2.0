#pragma once
#include "Lexem.h"

class OpenBracket:public Lexem {
private:
    double _id;
public:
    OpenBracket(double id);
    double proceed(stack<double>& args) const override;
};

class CloseBracket :public Lexem {
private:
    double _id;
public:
    CloseBracket(double id);
    double proceed(stack<double>& args) const override;
};

