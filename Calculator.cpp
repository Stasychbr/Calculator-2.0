#include <iostream>
#include <filesystem>
#include "Calculator.h"

typedef Lexem* (*lexLoader)();
typedef const char* (*nameLoader)();

Calculator::Calculator() {
#ifdef _DEBUG
    const char* path = "./Debug/Plugins";
#else
    const char* path = "./Plugins";
#endif // DEBUG
    try {
        filesystem::directory_iterator dir(path);
        for (auto& dll : dir) {
            if (dll.path().extension().string() != ".dll") {
                continue;
            }
            HMODULE lib = LoadLibrary(dll.path().string().c_str());
            if (!lib) {
                cout << "Unable to connect " << dll.path().filename().string() << endl;
                continue;
            }
            lexLoader loadLexeme = (lexLoader)GetProcAddress(lib, "getLexem");
            nameLoader loadName = (nameLoader)GetProcAddress(lib, "getName");
            if (!loadLexeme || !loadName) {
                cout << "Unable to load plugin from " << dll.path().filename().string() << endl;
                FreeLibrary(lib);
                continue;
            }
            _libs.push_back(lib);
            _parser.addLexem(shared_ptr<Lexem>(loadLexeme()), string(loadName()));
            cout << "Plugin " << dll.path().filename().string() << " is connected" << endl;
        }
    }
    catch (exception exc) {
        cout << "Unable to find " << path <<  endl;
    }
    _parser.sortLexems();
}

void Calculator::run() {
    string line;
    while (cin.good()) {
        getline(cin, line);
        if (line.empty()) {
            break;
        }
        try {
            auto tokens = _parser.parseLexems(line);
            cout << "Answer: " << _arEng.calculate(tokens) << endl;
        }
        catch (const char* msg) {
            cout << "Error: " << msg << endl;
        }
    }
}

Calculator::~Calculator() {
    for (auto lib : _libs) {
        FreeLibrary(lib);
    }
}
