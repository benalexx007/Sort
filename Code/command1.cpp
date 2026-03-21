#include "library.h"
void command1(function<int(int [], int n, int mode)> algo, string File, string output_para){
    double time = 0; 
    int comp = 0;
    fstream fin(File, ios::in);
    int n;
    fin >> n;
    int* a = new int[n];
    for(int i = 0; i < n; i++)
        fin >> a[i];
    fin.close();
    auto start = chrono::high_resolution_clock::now();
    comp = algo(a, n, 0);
    auto stop = chrono::high_resolution_clock::now();
    double duration = chrono::duration<double, milli>(stop - start).count();
    cout << "Input File: " + File + '\n';
    cout << "Input size: " << n << '\n';
    output(output_para, {time, 0}, {comp, 0}, 0);
    fstream fout("../output.txt", ios::out);
    fout << n << '\n';
    for(int i = 0; i < n; i++)
        fout << a[i];
    fout.close();
    delete[] a;
}