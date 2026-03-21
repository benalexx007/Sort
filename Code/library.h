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
#include "DataGenerator.cpp"

using namespace std;

// Bỏ biến mode
int selection (int a[], int n);
int insertion (int a[], int n);
int bin_insertion (int a[], int n);
int bubble (int a[], int n);
int shaker (int a[], int n);
int shell (int a[], int n);
int heap (int a[], int n);
int Merge (int a[], int n); // Thêm merge
int quick (int a[], int n);
int counting (int a[], int n);
int radix (int a[], int n);
int flash (int a[], int n);

// Cập nhật lại parameters cho các command để nhận đúng tên thuật toán
void command1(string algo_name, function<int(int [], int)> algo, string File, string output_para);
void command2(string algo_name, function<int(int [], int)> algo, int Size, int order, string order_name, string output_para);
void command3(string algo_name, function<int(int [], int)> algo, int Size, string output_para);
void command4(string algo_name1, string algo_name2, function<int(int [], int)> algo1, function<int(int [], int)> algo2, string File);
void command5(string algo_name1, string algo_name2, function<int(int [], int)> algo1, function<int(int [], int)> algo2, int Size, int order, string order_name);

#endif