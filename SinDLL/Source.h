#pragma once
#include "../Plugin.h"

class Sin :public Lexem {
public:
    Sin();
    double proceed(stack<double>& args) const override;
};