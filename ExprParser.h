#pragma once
#include <unordered_map>
#include "LexemManager.h"

using namespace std;

class ExprParser:public LexemManager {
public:
    vector<shared_ptr<Lexem>> parseLexems(string& expression);
};

