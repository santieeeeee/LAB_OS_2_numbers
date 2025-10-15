#pragma once

#include <windows.h>
#include <vector>

struct ThreadParams {
    int* arr;
    size_t n;
    size_t minIndex;
    size_t maxIndex;
    double average;
};

DWORD WINAPI MinMaxThread(LPVOID lpParam);
DWORD WINAPI AverageThread(LPVOID lpParam);

void compute_min_max(const std::vector<int>& v, int& outMin, int& outMax);
double compute_average(const std::vector<int>& v);
void replace_min_max_with_average(std::vector<int>& v, double avg);
