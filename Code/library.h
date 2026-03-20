#ifndef LIBRARY_SORT
#define LIBRARY_SORT
#include <string>
#include <utility>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>
#include <chrono>
#include <functional>
#include <iostream>

using namespace std;

int selection (int a[], int n, int mode);
int insertion (int a[], int n, int mode);
int bin_insertion (int a[], int n, int mode);
int bubble (int a[], int n, int mode);
int shaker (int a[], int n, int mode);
int shell (int a[], int n, int mode);
int heap (int a[], int n, int mode);
int quick (int a[], int n, int mode);
int counting (int a[], int n, int mode);
int radix (int a[], int n, int mode);
int flash (int a[], int n, int mode);

int output (string para, pair<double, double> time, pair<int, int> comp, bool mode){
    cout<<"-------------------------\n";
    if(para == "-time" || para == "-both")
        cout << "Running time: " << time.first << " ms" << (mode ? (" | " + to_string(time.second) + " ms"): "")<<'\n';
    if(para == "-both" || para == "-comp")
        cout << "Comparisions: " << comp.first << " comparisons" <<(mode ? (" | " + to_string(comp.second) +" comparisons"): "")<<'\n';
}

void command1(function<int(int [], int n, int mode)> algo, string File, string output_para);
void command2(function<int(int [], int n, int mode)> algo, int Size, string order, string output_para);
void command3(function<int(int [], int n, int mode)> algo, int Size, string output_para);
void command4(function<int(int [], int n, int mode)> algo1, function<int(int [], int n, int mode)> algo2, string File);
void command5(function<int(int [], int n, int mode)> algo1, function<int(int [], int n, int mode)> algo2, int Size, string order);

#endif