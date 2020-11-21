#pragma once
#include <Windows.h>
#include "ExprParser.h"
#include "ArithEngine.h"

class Calculator {
private:
    vector<HMODULE> _libs;
    ExprParser _parser;
    ArithEngine _arEng;
public:
    Calculator();
    void run();
    ~Calculator();
};

