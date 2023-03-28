#include <iostream>
#include <chrono>

#ifndef SORTS_DZ_SORTS_H
#define SORTS_DZ_SORTS_H

const int N = 9;

void randfill(int* ar, int size);

float test_sort(void (*testSort)(int*, int), int size, int &flag);

void FOT(void (*testSort)(int*, int), int size, int* ar);

void test_sort();

void Bubble_sort(int* ar, int size);

void Selection_sort(int* ar, int size);

void Quick_sort(int* ar, int, int);

void QuickSort_1(int*, int);

void Insertion_sort(int* ar, int size);

void Merge(int arr1[], int const first, int const mid, int const last);

void MergeSort(int arr1[], int const beg, int const end);

void Merge_sort(int*, int);

void Count_sort(int arr[], int N);

void Gnome_sort(int* ar, int size);

void Shell_sort(int* ar, int size);

void Heap_sort(int* ar, int size);

#endif