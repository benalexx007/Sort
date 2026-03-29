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
//#include "DataGenerator.cpp"

void GenerateRandomData(int a[], int n);
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);
void GenerateData(int a[], int n, int dataType);

using namespace std;

long long selection (int a[], int n);
long long insertion (int a[], int n);
long long bin_insertion (int a[], int n);
long long bubble (int a[], int n);
long long shaker (int a[], int n);
long long shell (int a[], int n);
long long heap (int a[], int n);
long long Merge (int a[], int n); 
long long quick (int a[], int n);
long long counting (int a[], int n);
long long radix (int a[], int n);
long long flash (int a[], int n);

void command1(string algo_name, function<long long(int [], int)> algo, string File, string output_para);
void command2(string algo_name, function<long long(int [], int)> algo, int Size, int order, string order_name, string output_para);
void command3(string algo_name, function<long long(int [], int)> algo, int Size, string output_para);
void command4(string algo_name1, string algo_name2, function<long long(int [], int)> algo1, function<long long(int [], int)> algo2, string File);
void command5(string algo_name1, string algo_name2, function<long long(int [], int)> algo1, function<long long(int [], int)> algo2, int Size, int order, string order_name);

#endif