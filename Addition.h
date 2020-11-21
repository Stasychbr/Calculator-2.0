#pragma once
#include "Lexem.h"
class Addition :public Lexem {
public:
    Addition();
    double proceed(stack<double>& args) const override;
};

