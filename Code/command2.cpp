#include "library.h"

void command2(string algo_name, function<long long(int [], int)> algo, int Size, int order, string order_name, string output_para) {
    cout << "ALGORITHM MODE\n";
    cout << "Algorithm: " << algo_name << '\n';
    cout << "Input size: " << Size << '\n';
    cout << "Input order: " << order_name << '\n';
    cout << "-------------------------\n";

    // Sinh dữ liệu
    int* a = new int[Size];
    GenerateData(a, Size, order);

    // Ghi dữ liệu đã sinh ra file input.txt
    fstream fout_in("input.txt", ios::out);
    fout_in << Size << '\n';
    for (int i = 0; i < Size; i++) {
        fout_in << a[i] << (i == Size - 1 ? "" : " "); // Các phần tử cách nhau bởi khoảng trắng
    }
    fout_in.close();

    // Bắt đầu tính thời gian và số phép so sánh
    auto start = chrono::high_resolution_clock::now();
    long long comp = algo(a, Size);
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
    fstream fout_out("output.txt", ios::out);
    fout_out << Size << '\n';
    for (int i = 0; i < Size; i++) {
        fout_out << a[i] << (i == Size - 1 ? "" : " "); // Các phần tử cách nhau bởi khoảng trắng
    }
    fout_out.close();

    delete[] a;
}