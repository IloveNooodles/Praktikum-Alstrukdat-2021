// MUHAMMAD GAREBALDHIE ER RAHMAN
// 13520029
// 4 NOVEMBER 2021
// PRAKTIKUM 9
// ROUNDROBIN

#include <stdio.h>
#include "list_circular.h"

void deleteRR(List *l, ElType tQ){
  int val;
  if(isEmpty(*l)){
    printf("List kosong\n");
  }else{
    Address p = FIRST(*l);
    while(NEXT(p) != FIRST(*l)){
      p = NEXT(p);
    }
    if(INFO(p) > tQ){
      INFO(p) = INFO(p) - tQ;
      FIRST(*l) = p;
      printf("%d\n", tQ);
    }else if(INFO(p) <= tQ){
      deleteLast(l, &val);
      printf("%d\n", val);
    }
  }
}

float average(List l){
  Address p = FIRST(l);
  float sum = 0;
  float i = 0;
  while(NEXT(p) != FIRST(l)){
    sum += INFO(p);
    i += 1;
    p = NEXT(p);
  }
  sum += INFO(p);
  i += 1;
  return sum/i;
}

int main(){
  List l;
  CreateList(&l);
  int tQ;
  scanf("%d", &tQ);
  while(tQ <= 0){
    scanf("%d", &tQ);
  }
  char a;
  scanf(" %c", &a);
  int value;
  while(a != 'F'){
    if(a == 'A'){
      scanf("%d", &value);
      if(value > 0){
        insertFirst(&l, value);
      }
    }else if(a == 'D'){
      deleteRR(&l, tQ);
    }else{
      printf("Kode salah\n");
    }
    scanf(" %c", &a);
  }
  if(!isEmpty(l)){
    printf("%.2f\n", average(l));
  }else{
    printf("Proses selesai\n");
  }
}