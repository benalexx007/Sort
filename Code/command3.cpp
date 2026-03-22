#include "library.h"

void command3(string algo_name, function<long long(int [], int)> algo, int Size, string output_para) {
    cout << "ALGORITHM MODE\n";
    cout << "Algorithm: " << algo_name << '\n';
    cout << "Input size: " << Size << "\n\n";
    int orders[] = {0, 3, 1, 2}; // Từ DataGenerator: 0: rand, 1: sorted, 2: rev, 3: nsorted
    string order_names[] = {"Randomize", "Nearly Sorted", "Sorted", "Reversed"};
    string file_names[] = {"input_1.txt", "input_2.txt", "input_3.txt", "input_4.txt"};
    for (int i = 0; i < 4; i++) {
        int* a = new int[Size];
        GenerateData(a, Size, orders[i]);
        fstream fout(file_names[i], ios::out);
        fout << Size << '\n';
        for (int j = 0; j < Size; j++) fout << a[j] << " ";
        fout.close();
        cout << "Input order: " << order_names[i] << "\n";
        cout << "-------------------------\n";
        auto start = chrono::high_resolution_clock::now();
        long long comp = algo(a, Size);
        auto stop = chrono::high_resolution_clock::now();
        double duration = chrono::duration<double, milli>(stop - start).count();
        if (output_para == "-time" || output_para == "-both") cout << "Running time (if required): " << duration << " ms\n";
        if (output_para == "-comp" || output_para == "-both") cout << "Comparisions (if required): " << comp << "\n";
        cout << "\n";
        delete[] a;
    }
}