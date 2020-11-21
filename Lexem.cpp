#include "Lexem.h"

Priority Lexem::getPrior() const {
    return prior;
}

bool Lexem::isPrefix() const {
    return prefix;
}

bool Lexem::isRightAss() const {
    return rightAss;
}