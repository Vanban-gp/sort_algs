#pragma once
#include "tools.hpp"
#include <iostream>

namespace qs
{
    using tls::Index, tls::Value;
    void sort(Value *arr, Index size);
    int pivot(Index size);
    void parts(Value *arr, Index l, Index r);
}

void qs::sort(Value *a, Index s)
{
    parts(a, 0, s - 1);
}

int qs::pivot(Index s)
{
    return ((s + 1) / 2 - 1);
}

void qs::parts(Value *a, Index l, Index r)
{
    if (l < r)
    {
        int p = pivot(l + r);
        int i = l;
        int j = r;
        while (i <= j)
        {
            while (a[i] < a[p])
            {
                ++i;
            }
            while (a[j] > a[p])
            {
                --j;
            }
            if (i >= j)
            {
                break;
            }
            tls::swap(a[i], a[j]);
        }
        qs::parts(a, l, p);
        qs::parts(a, p + 1, r);
    }
}