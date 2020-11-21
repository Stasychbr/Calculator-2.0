#include "LexemManager.h"
#include "Number.h"
#include "Addition.h"
#include "Brackets.h"


LexemManager::LexemManager() {
    shared_ptr<Lexem> addition(new Addition);
    shared_ptr<Lexem> openBrac(new OpenBracket(0));
    shared_ptr<Lexem> closeBrac(new CloseBracket(0));
    addLexem(move(addition), "+");
    addLexem(move(openBrac), "(");
    addLexem(move(closeBrac), ")");
}


shared_ptr<Lexem> LexemManager::getLexem(string& line) {
    double num;
    bool notNum = false;
    size_t read;
    if (isdigit(line[0])) {
        num = stod(line, &read);
        line.erase(0, read);
        return shared_ptr<Lexem>(new Number(num));
    }
    if (_lexems[line[0]].empty()) {
        throw "Unknown operation";
    }
    for (auto it = _lexems[line[0]].begin(); it != _lexems[line[0]].end(); it++) {
        if (line.find(it->first) == 0) {
            line.erase(0, it->first.length());
            return it->second;
        }
    }
    throw "Unknown operation";
}

void LexemManager::sortLexems() {
    auto comparator = [](const pair<string, shared_ptr<Lexem>>& a, const pair<string, shared_ptr<Lexem>>& b)
    {
        return a.first.length() > b.first.length();
    };
    for (auto it = _lexems.begin(); it != _lexems.end(); it++) {
        sort(it->second.begin(), it->second.end(), comparator);
    }
}

void LexemManager::addLexem(shared_ptr<Lexem>&& op, string&& name) {
    _lexems[name[0]].emplace_back(make_pair(name, op));
}
