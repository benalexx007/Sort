#include "library.h"

void command1(string algo_name, function<int(int [], int)> algo, string File, string output_para) {
    cout << "ALGORITHM MODE\n";
    cout << "Algorithm: " << algo_name << '\n';
    cout << "Input file: " << File << '\n';

    // Đọc file input
    fstream fin(File, ios::in);
    if (!fin) {
        cout << "Cannot open file!\n";
        return;
    }
    int n;
    fin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        fin >> a[i];
    }
    fin.close();

    cout << "Input size: " << n << '\n';
    cout << "-------------------------\n";

    // Bắt đầu tính thời gian và số phép so sánh
    auto start = chrono::high_resolution_clock::now();
    int comp = algo(a, n);
    auto stop = chrono::high_resolution_clock::now();
    double duration = chrono::duration<double, milli>(stop - start).count();

    // In theo tham số output_para
    if (output_para == "-time" || output_para == "-both") {
        cout << "Running time (if required): " << duration << " ms\n";
    }
    if (output_para == "-comp" || output_para == "-both") {
        cout << "Comparisions (if required): " << comp << '\n';
    }

    // Ghi mảng đã sắp xếp ra file output.txt
    fstream fout("output.txt", ios::out);
    fout << n << '\n';
    for (int i = 0; i < n; i++) {
        fout << a[i] << (i == n - 1 ? "" : " "); // Các phần tử cách nhau bởi khoảng trắng
    }
    fout.close();

    delete[] a;
}