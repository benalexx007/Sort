#include "library.h"

void command4(string algo_name1, string algo_name2, function<int(int [], int)> algo1, function<int(int [], int)> algo2, string File) {
    cout << "COMPARE MODE\n";
    cout << "Algorithm: " << algo_name1 << " | " << algo_name2 << '\n';
    cout << "Input file: " << File << '\n';

    fstream fin(File, ios::in);
    if (!fin) { cout << "Cannot open file!\n"; return; }
    int n; fin >> n;
    cout << "Input size: " << n << '\n';
    cout << "-------------------------\n";

    int* a1 = new int[n];
    int* a2 = new int[n];
    for (int i = 0; i < n; i++) {
        fin >> a1[i];
        a2[i] = a1[i]; // Chép mảng
    }
    fin.close();

    auto start1 = chrono::high_resolution_clock::now();
    int comp1 = algo1(a1, n);
    auto stop1 = chrono::high_resolution_clock::now();
    double time1 = chrono::duration<double, milli>(stop1 - start1).count();

    auto start2 = chrono::high_resolution_clock::now();
    int comp2 = algo2(a2, n);
    auto stop2 = chrono::high_resolution_clock::now();
    double time2 = chrono::duration<double, milli>(stop2 - start2).count();

    cout << "Running time: " << time1 << " ms | " << time2 << " ms\n";
    cout << "Comparisions: " << comp1 << " | " << comp2 << "\n";

    delete[] a1; delete[] a2;
}