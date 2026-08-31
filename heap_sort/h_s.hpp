#pragma once
#include "tools.hpp"

namespace hs
{
    using tls::Index, tls::Value;
    void sort(Value *arr, Index size);
    void heapiup(Value *a, Index i);
    // int Max(Index a, Index b);
}

void hs::sort(Value *a, Index s)
{
    if (s != 1)
    {
        for(int i = s - 1; i > 0; --i)
        {
            hs:heapiup(a, i);
        }
        tls::swap(a[0], a[s - 1]);
        hs::sort(a, s - 1);
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

    
//попытка оптимизации( не удалась... )


//     if (*i % 2 != 0)
//     {
//         if(a[*i] > a[(*i - 1) / 2])
//         {
//             tls::swap(a[*i], a[(*i - 1)/2]);
//         }
//     } else
//     {
//         int max = hs::Max(a[*i], a[*i - 1]);
//         if(max == a[*i])
//         {
//             tls::swap(a[*i], a[(*i - 2) / 2]);
//         } else
//         {
//             tls::swap(a[*i - 1], a[(*i - 2) / 2]);
//         }
//         *i = *i - 1;
//     }
// }


// int hs::Max(Index a, Index b)
// {
//     if(a <= b)
//     {
//         return b;
//     }
//     if (a >= b)
//     {
//         return a;
//     }
}