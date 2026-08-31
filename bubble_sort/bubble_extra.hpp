#pragma once

#include "tools.hpp"

namespace bs
{
    using tls::Index, tls::Value;

    void sort(Value *array, Index null_el, Index size);
}

void bs::sort(Value *a, Index n, Index s)
{
    if (n < s)
    {
        for (int i = n; i < s; i++)
        {
            if (a[i] < a[n])
            {
                tls::swap(a[i], a[n]);
            }
        }
        bs::sort(a, n + 1, s);
    } else 
    {
        return;
    }
}
