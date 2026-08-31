#pragma once
#include "tools.hpp"

namespace ms
{
    using tls::Index, tls::Value;
    void sort(Value *a, Index n);
    void merge(Value *res, Value *left, Value *right, Index l, Index r);
    int split(Index n);
}

void ms::sort(Value *a, Index n)
{
    ms::Index c = split(n); // нашли средний элемент
    if (c + 1 < n)          // если средний элемент + 1 меньше размера массива - работаем дальше
    {
        ms::Value *left{new ms::Value[c]}; // создали левый массив
        for (int i = 0; i <= c; ++i)
        { // заполнили элементами из исходного
            left[i] = a[i];
        }
        ms::Value *right{new ms::Value[n - c]}; // создали правый массив
        for (int i = 0; i < n - c - 1; ++i)
        { // заполнили элементами из исходного
            right[i] = a[c + 1 + i];
        }
        sort(left, c + 1);                    // рекурсия для левых массивов
        sort(right, n - c - 1);               // рекурсия для правых массивов
        merge(a, left, right, c + 1, n - c - 1); // слияние массивов

    }
    else
    { // если средний элемент равен 0 - возвращаемся в прошлый вызов
        return;
    }
}

ms::Index ms::split(Index n)
{
    return (n + 1) / 2 - 1;
}

void ms::merge(Value *res, Value *left, Value *right, Index l, Index r)
{
    int s = 0, i = 0, j = 0;
    for (; s < l + r; ++s)
    {
        if (j >= r)
        {
            for (; s < l + r; ++s)
            {
                res[s] = left[i];
                ++i;
            }
        }
        else
        {
            if (i >= l)
            {
                for (; s < l + r; ++s)
                {
                    res[s] = right[j];
                    ++i;
                }
            }
            else
            {
                if (left[i] < right[j])
                {
                    res[s] = left[i];
                    ++i;
                }
                else
                {
                    res[s] = right[j];
                    ++j;
                }
            }
        }
    }
}