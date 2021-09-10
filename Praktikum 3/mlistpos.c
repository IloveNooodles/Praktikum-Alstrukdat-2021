// Nama: Muhammad Garebaldhie ER Rahman
// NIM: 1352029
// TANGGAL: 09 September 2021
// TOPIK: ADT LIST
// DESKRIPSI: Praktikum 3

#include <stdio.h>
#include "listpos.h"

int main(){
  int x, min, max, median, idx;
  ListPos l;
  readList(&l);
  scanf("%d", &x);
  displayList(l);
  printf("\n");
  idx = indexOf(l, x);
  sort(&l, 1);
  extremes(l, &max, &min);
  if(length(l) % 2 != 0){
    median = ELMT(l, length(l)/2);
  }else{
    median = ELMT(l, length(l)/2 - 1);
  }
  if(idx == -1){
    printf("%d tidak ada\n", x);
  }else{
    printf("%d\n", idx);
    if(x == max) printf("maksimum\n");
    if(x == min)printf("minimum\n");
    if(x == median)printf("median\n");
  }
}