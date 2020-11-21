#pragma once
#include "Lexem.h"

extern "C" {
    __declspec(dllexport) Lexem* getLexem();
    __declspec(dllexport) const char* getName();
}


