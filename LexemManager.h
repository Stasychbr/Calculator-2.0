#pragma once
#include <unordered_map>
#include <map>
#include <string>
#include <memory>
#include <functional>
#include "Lexem.h"

using namespace std;


class LexemManager {
private:
    //static function<bool(const string&, const string&)> comparator;
    //unordered_map<char, map<string, shared_ptr<Lexem>>> _lexems;
    unordered_map<char, vector<pair<string, shared_ptr<Lexem>>>> _lexems;
protected:
    shared_ptr<Lexem> getLexem(string& line);
public:
    LexemManager();
    void sortLexems();
    void addLexem(shared_ptr<Lexem>&& op, string&& name);
};

