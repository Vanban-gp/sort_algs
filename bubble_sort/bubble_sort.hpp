#pragma once

#include "tools.hpp"

namespace bs {
    using tls::Index, tls::Value;

    void sort(Value* a, Index n);
}

void bs::sort(Value* a, Index n) {
    for (int k = 0; k < n - 1; k++) {
        for (int i = k; i < n; i++) {
            if (a[i] < a[k]) {
                tls::swap(a[i], a[k]);
            }
        }
    }
}