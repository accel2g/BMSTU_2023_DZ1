#include "Sorts.h"

int main(){
  FILE* pFile;
  float sum;
  int count = N;
  pFile = fopen("Sorts.txt", "w");
  void(*sort[])(int*, int) = {Count_sort, QuickSort_1, Merge_sort, Shell_sort, Heap_sort, Selection_sort, Gnome_sort, Insertion_sort, Bubble_sort};
  int k = 1000000;
  int* flag = new int[N];
  for(int i = 0; i < N; i++){
    flag[i] = 0;
  }
  fprintf(pFile, "%s\t\t%-8s\t%-8s\t%-8s\t%-8s\t%-8s\t%-8s\t%-8s\t%-8s\t%-8s\n", "Size", "Count", "Quick", "Merge", "Shell", "Heap", "Selection", "Gnome", "Insertion", "Bubble");
  fflush(pFile);
  for(int size = 1000; size < 10e+7 && count; size += size/3){
    fprintf(pFile, "%d\t", size);
    fflush(pFile);
    if(size < 10e+6){
      size *= 3/2;
      fprintf(pFile, "\t");
      fflush(pFile);
    }
    for(int j = 0; j < N; j++){
      if(!flag[j]){
        int l = flag[j];
        sum = test_sort(sort[j], size, flag[j]);
        if(l != flag[j]){
          count--;
        }
        fprintf(pFile, "%f\t", sum);
        fflush(pFile);
        continue;
      }
      fprintf(pFile, "\t");
      fflush(pFile);
    }
    fprintf(pFile, "\n");
    fflush(pFile);
  }
  fclose(pFile);
  return 0;
}
