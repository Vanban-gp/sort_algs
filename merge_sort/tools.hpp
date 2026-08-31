#pragma once
#include <iostream>

namespace tls {
    using Value = int;
    using Index = int;

    void swap (Value& first, Value& second);
    void term (Value* a, Index n);
}

void tls::swap(Value& frst, Value& scnd) {
    int c = 0;
    c = frst;
    frst = scnd;
    scnd = c;
}

void tls::term(Value* a, Index n) {
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << std::endl;
    }
}