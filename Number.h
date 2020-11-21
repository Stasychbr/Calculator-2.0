#pragma once
#include "Lexem.h"
class Number:public Lexem {
    double _val;
public:
    Number(double value);
    double proceed(stack<double>& args) const override;
};

