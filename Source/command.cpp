#include "library.h"

void command1(string algo_name, function<long long(int [], int)> algo, string File, string output_para) {
    cout << "ALGORITHM MODE\n";
    cout << "Algorithm: " << algo_name << '\n';
    cout << "Input file: " << File << '\n';
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
    auto start = chrono::high_resolution_clock::now();
    long long comp = algo(a, n);
    auto stop = chrono::high_resolution_clock::now();
    double duration = chrono::duration<double, milli>(stop - start).count();
    if (output_para == "-time" || output_para == "-both") {
        cout << "Running time (if required): " << duration << " ms\n";
    }
    if (output_para == "-comp" || output_para == "-both") {
        cout << "Comparisions (if required): " << comp << '\n';
    }
    fstream fout("output.txt", ios::out);
    fout << n << '\n';
    for (int i = 0; i < n; i++) {
        fout << a[i] << (i == n - 1 ? "" : " ");
    }
    fout.close();
    delete[] a;
}

void command2(string algo_name, function<long long(int [], int)> algo, int Size, int order, string order_name, string output_para) {
    cout << "ALGORITHM MODE\n";
    cout << "Algorithm: " << algo_name << '\n';
    cout << "Input size: " << Size << '\n';
    cout << "Input order: " << order_name << '\n';
    cout << "-------------------------\n";
    int* a = new int[Size];
    GenerateData(a, Size, order);
    fstream fout_in("input.txt", ios::out);
    fout_in << Size << '\n';
    for (int i = 0; i < Size; i++) {
        fout_in << a[i] << (i == Size - 1 ? "" : " ");
    }
    fout_in.close();
    auto start = chrono::high_resolution_clock::now();
    long long comp = algo(a, Size);
    auto stop = chrono::high_resolution_clock::now();
    double duration = chrono::duration<double, milli>(stop - start).count();
    if (output_para == "-time" || output_para == "-both") {
        cout << "Running time (if required): " << duration << " ms\n";
    }
    if (output_para == "-comp" || output_para == "-both") {
        cout << "Comparisions (if required): " << comp << '\n';
    }
    fstream fout_out("output.txt", ios::out);
    fout_out << Size << '\n';
    for (int i = 0; i < Size; i++) {
        fout_out << a[i] << (i == Size - 1 ? "" : " ");
    }
    fout_out.close();
    delete[] a;
}

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

void command4(string algo_name1, string algo_name2, function<long long(int [], int)> algo1, function<long long(int [], int)> algo2, string File) {
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
        a2[i] = a1[i];
    }
    fin.close();
    auto start1 = chrono::high_resolution_clock::now();
    long long comp1 = algo1(a1, n);
    auto stop1 = chrono::high_resolution_clock::now();
    double time1 = chrono::duration<double, milli>(stop1 - start1).count();
    auto start2 = chrono::high_resolution_clock::now();
    long long comp2 = algo2(a2, n);
    auto stop2 = chrono::high_resolution_clock::now();
    double time2 = chrono::duration<double, milli>(stop2 - start2).count();
    cout << "Running time: " << time1 << " ms | " << time2 << " ms\n";
    cout << "Comparisions: " << comp1 << " | " << comp2 << "\n";
    delete[] a1; delete[] a2;
}

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