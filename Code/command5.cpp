#include "library.h"

void command5(string algo_name1, string algo_name2, function<long long(int [], int)> algo1, function<long long(int [], int)> algo2, int Size, int order, string order_name) {
    cout << "COMPARE MODE\n";
    cout << "Algorithm: " << algo_name1 << " | " << algo_name2 << '\n';
    cout << "Input size: " << Size << '\n';
    cout << "Input order: " << order_name << '\n';
    cout << "-------------------------\n";

    int* a1 = new int[Size];
    int* a2 = new int[Size];
    GenerateData(a1, Size, order);

    fstream fout("input.txt", ios::out);
    fout << Size << '\n';
    for (int i = 0; i < Size; i++) {
        fout << a1[i] << " ";
        a2[i] = a1[i]; // Chép mảng
    }
    fout.close();

    auto start1 = chrono::high_resolution_clock::now();
    long long comp1 = algo1(a1, Size);
    auto stop1 = chrono::high_resolution_clock::now();
    double time1 = chrono::duration<double, milli>(stop1 - start1).count();

    auto start2 = chrono::high_resolution_clock::now();
    long long comp2 = algo2(a2, Size);
    auto stop2 = chrono::high_resolution_clock::now();
    double time2 = chrono::duration<double, milli>(stop2 - start2).count();

    cout << "Running time: " << time1 << " ms | " << time2 << " ms\n";
    cout << "Comparisions: " << comp1 << " | " << comp2 << "\n";

    delete[] a1; delete[] a2;
}