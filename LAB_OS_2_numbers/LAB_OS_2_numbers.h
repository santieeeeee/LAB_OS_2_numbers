// LAB_OS_2_numbers.h
#pragma once

#include <windows.h>

// Простая структура параметров для потоков
struct ThreadParams {
    int* arr;        // указатель на массив
    size_t n;        // размер массива
    size_t minIndex; // индекс минимума
    size_t maxIndex; // индекс максимума
    double average;  // среднее
};

// Прототипы функций-потоков
DWORD WINAPI MinMaxThread(LPVOID lpParam);
DWORD WINAPI AverageThread(LPVOID lpParam);
