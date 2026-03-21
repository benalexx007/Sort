#include "library.h"
void command2(function<int(int [], int n, int mode)> algo, int Size, int order, string output_para){
    double time = 0; 
    int comp = 0;
    int* a = new int[Size];
    GenerateData(a, Size, order);
    fstream fout("../input.txt", ios::out);
    fout << Size << '\n';
    for(int i = 0; i < Size ; i++)
        fout << a[i];
    fout.close();
    auto start = chrono::high_resolution_clock::now();
    comp = algo(a, Size, 0);
    auto stop = chrono::high_resolution_clock::now();
    cout << "Input size: " << Size << '\n';
    output(output_para, {time, 0}, {comp, 0}, 0);
    fstream fout("../output.txt", ios::out);
    fout << Size << '\n';
    for(int i = 0; i < Size ; i++)
        fout << a[i];
    fout.close();
}