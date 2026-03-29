#include "library.h"

void DataGeneration() {
    int sizes[] = {10000, 30000, 50000, 100000, 300000, 500000};
    int orders[] = {0, 1, 2, 3};
    string names[] = {"rand", "sorted", "rev", "nsorted"};
    for (int size : sizes) {
        for (int i = 0; i < 4; i++) {
            int* a = new int[size];
            GenerateData(a, size, orders[i]);
            string filename = "../Experiment/" + names[i] + "/"  + to_string(size) + ".txt";
            fstream fout(filename, ios::out);
            fout << size << '\n';
            for (int j = 0; j < size; j++) {
                fout << a[j] << " ";
            }
            fout.close();
            cout << "-> Da tao file: " << filename << '\n';
            delete[] a;
        }
    }
}