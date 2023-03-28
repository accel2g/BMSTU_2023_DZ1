#include <iostream>
#include "Sorts.h"

void randfill(int* ar, int size){
  for(int i = 0; i < size; i++)
    ar[i] = 0 + rand() % 10000;
}

void Bubble_sort(int* ar, int size){
  bool flag;
  for(int i = 0; i < size - 1; i++){
    flag = false;
    for(int j = 0; j < size - i - 1; j++){
      if(ar[j] > ar[j+1]){
        int tmp = ar[j];
        ar[j] = ar[j+1];
        ar[j+1] = tmp;
        flag = true;
      }
    }
    if(flag == false) break;
  }
}

void Selection_sort(int* ar, int size){
  int i,j,minInd;
  for(i = 0; i < size - 1; i++){
    minInd = i;
    for(j = i + 1; j < size; j++){
      if(ar[j] < ar[minInd])
        minInd = j;
    }
    std::swap(ar[minInd], ar[i]);
  }
}

void Quick_sort(int* ar, int left, int right){
  int i = left;
  int j = right;
  int pivo = ar[(i+j) / 2];
  while(i <= j){
    while(ar[i] < pivo)
      i++;
    while(ar[j] > pivo)
      j--;
    if(i <= j){
      std::swap(ar[i], ar[j]);
      i++;
      j--;
    }
  }
  if(j > left) 
    Quick_sort(ar, left, j);
  if(i < right) 
    Quick_sort(ar, i, right);
}

void QuickSort_1(int* ar, int size){
  Quick_sort(ar, 0, size - 1);
}

void Insertion_sort(int* ar, int size){
  for(int i = 1; i < size; i++)
    for(int j = i; j > 0 && ar[j-1] > ar[j]; j--)
      std::swap(ar[j-1], ar[j]);
}

void Merge(int* arr1, int const first, int const mid, int const last){
  int const count1 = mid - first + 1;
  int const count2 = last - mid;
  int *Larr = new int[count1], *Rarr = new int[count2];
  for(int i = 0; i < count1; i++)
    Larr[i] = arr1[first + i];
  for(int j = 0; j < count2; j++)
    Rarr[j] = arr1[mid + 1 +j];
  int IndSub1 = 0, IndSub2 = 0;
  int IndMer = first;
  while(IndSub1 < count1 && IndSub2 < count2){
    if(Larr[IndSub1] <= Rarr[IndSub2]){
      arr1[IndMer] = Larr[IndSub1];
      IndSub1++;
    }
    else{
      arr1[IndMer] = Rarr[IndSub2];
      IndSub2++;
    }
    IndMer++;
  }
  while(IndSub1 < count1){
    arr1[IndMer] = Larr[IndSub1];
    IndSub1++;
    IndMer++;
  }
  while(IndSub2 < count2){
    arr1[IndMer] = Rarr[IndSub2];
    IndSub2++;
    IndMer++;
  }
  delete[] Larr;
  delete[] Rarr;
}

void MergeSort(int *arr1, int const beg, int const end){
  if(beg >= end)
    return;
  int mid = beg + (end - beg) / 2;
  MergeSort(arr1, beg, mid);
  MergeSort(arr1, mid + 1, end);
  Merge(arr1, beg, mid, end);
}

void Merge_sort(int* arr, int size){
  MergeSort(arr, 0, size - 1);
}

void Count_sort(int* ar, int size){
  int max_el = ar[0];
  for(int i = 1; i < size; i++){
    if(ar[i] > max_el)
      max_el = ar[i];
  }
  int* count_arr = new int[max_el + 1]();
  for(int i = 0; i < size; i++){
    count_arr[ar[i]]++;
  }
  int j = 0;
  for(int i = 0; i <= max_el; i++){
    while(count_arr[i] > 0){
      ar[j++] = i;
      count_arr[i]--;
    }
  }
  delete[] count_arr;
}

void Gnome_sort(int* ar, int size){
  int i = 0;
  while(i < size){
    if(i == 0 || ar[i] >= ar[i-1]){
      i++;
    }
    else{
      int tmp = ar[i];
      ar[i] = ar[i-1];
      ar[i-1] = tmp;
      i--;
    }
  }
}

void Shell_sort(int* ar, int size){
  for(int gap = size/2; gap > 0; gap /=2){
    for(int i = gap; i < size; i++){
      int tmp = ar[i];
      int j;
      for(j = i; j >= gap && ar[j-gap] > tmp; j-= gap){
        ar[j] = ar[j-gap];
      }
      ar[j] = tmp;
    }
  }
}

void Heapify(int* ar, int size, int i){
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  if(l < size && ar[l] > ar[largest])
    largest = l;
  if(r < size && ar[r] > ar[largest])
    largest = r;
  if(largest != i){
    std::swap(ar[i], ar[largest]);
    Heapify(ar, size, largest);
  }
}

void Heap_sort(int* ar, int size){
  for(int i = size / 2 - 1; i >= 0; i--)
    Heapify(ar, size, i);
  for(int i = size - 1; i >= 0; i--){
    std::swap(ar[0], ar[i]);
    Heapify(ar, i, 0);
  }
}

void FOT(void (*testSort)(int*, int), int size, int* ar){
  testSort(ar, size);
}

void test_sort(){
  void(*sort[])(int*, int) = {Bubble_sort, Selection_sort, QuickSort_1, Insertion_sort, Merge_sort, Count_sort, Gnome_sort, Shell_sort, Heap_sort};
  int size = 100;
  bool z  = false;
  int* ar = new int[size];
  for(int i = 0; i < N; i++){
    randfill(ar, size);
    FOT(sort[i], size, ar);
    z = true;
    for(int x = 0; x < size; x++){
      if(ar[x] > ar[x+1]){
        z = false;
      }
    }
    if(z){
      std::cout << "NO\n";
      continue;
    }
    std::cout << "YES\n";
  }
}

float test_sort(void (*testSort)(int*, int), int size, int &flag){
  int* ar = new int[size];
  auto start = std::chrono::steady_clock::now();
  auto end = std::chrono::steady_clock::now();
  randfill(ar, size);
  start = std::chrono::steady_clock::now();
  testSort(ar, size);
  end = std::chrono::steady_clock::now();
  if(std::chrono::duration<float>(end-start).count()  > 20){
    flag = 1;
  }
  delete[] ar;
  return std::chrono::duration<float>(end-start).count();
}
