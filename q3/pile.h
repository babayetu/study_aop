#ifndef PILE
#define PILE
#include <iostream>
#include <string>
using namespace std;
void MinHeapInsertFix(int a[], int i);
void MinHeapFixDown(int a[], int i, int n);
void MinHeapDeleteIdxZero(int a[],int n);
void BuildMinPile(int a[],int n);
void printIntArray(int intArray[], int n);
#endif