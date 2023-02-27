#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
#include <sstream>
#include <iomanip>
#include "Sort.h"
#include <algorithm>

using namespace std;
using namespace std::chrono;

const int SIZE{ 50'000 };
const string INFILE{ "BJTest50K.txt" };

void WriteHeader();
bool ReadFile(string filename, int arr[]);
double TimedSort(void sortFunc(int a[], int size), int a[]);
string GetFormattedTimeString(int arr[]);
void ArrayCopy(int src[], int size, int dest[]);
bool CheckSort(int arr[]);

#endif