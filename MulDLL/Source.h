#pragma once
#include "../Plugin.h"

class Multiplication :public Lexem {
public:
    Multiplication();
    double proceed(stack<double>& args) const override;
};