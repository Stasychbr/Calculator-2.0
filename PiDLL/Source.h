#pragma once
#include "../Plugin.h"

class Pi :public Lexem {
public:
    Pi();
    double proceed(stack<double>& args) const override;
};