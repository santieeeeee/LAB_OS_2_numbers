#include "LAB_OS_2_numbers.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

DWORD WINAPI MinMaxThread(LPVOID lpParam) {
    ThreadParams* p = reinterpret_cast<ThreadParams*>(lpParam);
    if (!p || !p->arr || p->n == 0) return 1;

    size_t minI = 0, maxI = 0;
    for (size_t i = 1; i < p->n; ++i) {
        if (p->arr[i] < p->arr[minI]) minI = i;
        Sleep(7);
        if (p->arr[i] > p->arr[maxI]) maxI = i;
        Sleep(7);
    }

    p->minIndex = minI;
    p->maxIndex = maxI;

    cout << "min_max: min = " << p->arr[minI] << " (i=" << minI << "), "
        << "max = " << p->arr[maxI] << " (i=" << maxI << ")\n";
    return 0;
}

DWORD WINAPI AverageThread(LPVOID lpParam) {
    ThreadParams* p = reinterpret_cast<ThreadParams*>(lpParam);
    if (!p || !p->arr || p->n == 0) return 1;

    long long sum = 0;
    for (size_t i = 0; i < p->n; ++i) {
        sum += p->arr[i];
        Sleep(12);
    }
    p->average = static_cast<double>(sum) / static_cast<double>(p->n);

    cout << "average = " << p->average << "\n";
    return 0;
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    cout << "Введите размер массива: ";
    size_t n;
    if (!(cin >> n) || n == 0) {
        cerr << "Неверный размер\n";
        return 1;
    }

    vector<int> v(n);
    cout << "Введите " << n << " целых чисел:\n";
    for (size_t i = 0; i < n; ++i) cin >> v[i];

    ThreadParams* params = new ThreadParams;
    params->n = n;
    params->arr = new int[n];
    for (size_t i = 0; i < n; ++i) params->arr[i] = v[i];
    params->minIndex = params->maxIndex = 0;
    params->average = 0.0;

    DWORD tid1 = 0, tid2 = 0;
    HANDLE hMinMax = CreateThread(NULL, 0, MinMaxThread, params, 0, &tid1);
    if (hMinMax == NULL) {
        cerr << "CreateThread(minmax) failed, error=" << GetLastError() << "\n";
        delete[] params->arr;
        delete params;
        return 1;
    }

    HANDLE hAverage = CreateThread(NULL, 0, AverageThread, params, 0, &tid2);
    if (hAverage == NULL) {
        cerr << "CreateThread(average) failed, error=" << GetLastError() << "\n";
        WaitForSingleObject(hMinMax, INFINITE);
        CloseHandle(hMinMax);
        delete[] params->arr;
        delete params;
        return 1;
    }

    WaitForSingleObject(hMinMax, INFINITE);
    WaitForSingleObject(hAverage, INFINITE);

    CloseHandle(hMinMax);
    CloseHandle(hAverage);

    int avgRounded = static_cast<int>(std::lround(params->average));
    if (params->minIndex == params->maxIndex) {
        params->arr[params->minIndex] = avgRounded;
    }
    else {
        params->arr[params->minIndex] = avgRounded;
        params->arr[params->maxIndex] = avgRounded;
    }

    cout << "Результирующий массив:\n";
    for (size_t i = 0; i < params->n; ++i) {
        cout << params->arr[i] << (i + 1 < params->n ? ' ' : '\n');
    }

    delete[] params->arr;
    delete params;
    return 0;
}
