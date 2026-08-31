#pragma once
#include "tools.hpp"

namespace hs
{
    using tls::Index, tls::Value;
    void sort(Value *arr, Index size);
    void heapiup(Value *a, Index i);
    
}

void hs::sort(Value *a, Index s)
{
    for(int j = s - 1; j > 0; --j)
    {
        for(int i = j; i >= 0; --i)
        {
            hs:heapiup(a, i);
        }
        tls::swap(a[0], a[j]);
    }
}

void hs::heapiup(Value *a, Index i)
{
    if(i % 2 != 0 && a[i] > a[(i - 1) / 2])
    {
        tls::swap(a[i], a[(i - 1)/2]);
    }
    if(i % 2 == 0 && a[i] > a[(i - 2) / 2])
    {
        tls::swap(a[i], a[(i-2)/2]);
    }
}