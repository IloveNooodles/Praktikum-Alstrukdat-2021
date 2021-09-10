// Nama: Muhammad Garebaldhie ER Rahman
// NIM: 1352029
// TANGGAL: 08 September 2021
// TOPIK: ADT LIST
// DESKRIPSI: Pra-Praktikum 3

#include <stdio.h>
#include "listpos.h"

void CreateListPos(ListPos *l){
  int i = 0;
  while(i != CAPACITY){
    ELMT(*l, i) = VAL_UNDEF;
    i++;
  }
}

int length(ListPos l){
  int length = 0;
  for(int i = 0; i < CAPACITY; i++){
    if(ELMT(l, i) != VAL_UNDEF)length++;
    else break;
  }
  return length;
}

boolean isIdxValid(ListPos l, int i){
  return ((i >= 0 && i < CAPACITY));
}

boolean isIdxEff(ListPos l, int i){
  return((i >= 0 && i < length(l)));
}

boolean isEmpty(ListPos l){
  return (length(l) == 0);
}

boolean isFull(ListPos l){
  return (length(l) == CAPACITY);
}

void readList(ListPos *l){
  CreateListPos(l);
  int n;
  scanf("%d", &n);
  while(n < 0 || n > CAPACITY){
      scanf("%d", &n);
    }
  int x;
  for(int i = 0; i < n; i++){
    scanf("%d", &x);
    ELMT(*l, i) = x;
  }
}

void displayList(ListPos l){ 
  if(isEmpty(l)){
    printf("[]");
  }else{
    printf("[");
    for(int i = 0; i < length(l); i++){
      printf("%d", ELMT(l, i));
      if(i != length(l) - 1){
        printf(",");
      }
    }
    printf("]");
  }
}

ListPos plusMinusTab(ListPos l1, ListPos l2, boolean plus){
  ListPos l;
  CreateListPos(&l);
  if(plus){
    for(int i = 0; i < length(l1); i++){
      ELMT(l, i) = ELMT(l1, i) + ELMT(l2, i);
    }
  }else{
    for(int i = 0; i < length(l1); i++){
      ELMT(l, i) = ELMT(l1, i) - ELMT(l2, i);
    }
  }
  return l;
}

boolean isListEqual(ListPos l1, ListPos l2){
  boolean eq = true;
  if(length(l1) == length(l2)){
    for(int i = 0; i < length(l1); i++){
      if(ELMT(l1, i) != ELMT(l2, i)){
        eq = false;
        break;
      }
    }
  }else{
    eq = false;
  }
  return eq;
}

int indexOf(ListPos l, ElType val){
  int ans = IDX_UNDEF;
  boolean ada = false;
  for(int i = 0; i < length(l); i++){
    if(ELMT(l, i) == val){
      ans = i;
      ada = true;
      break;
    }
  }
  if(ada)return ans;
  else return IDX_UNDEF;
}

void extremes(ListPos l, ElType *max, ElType *min){
  for(int i = 0; i < length(l); i++){
    if(i == 0){
      *min = ELMT(l, i);
      *max = ELMT(l, i);
    }
    if(*min > ELMT(l, i)){
      *min = ELMT(l, i);
    }
    if(*max < ELMT(l, i)){
      *max = ELMT(l, i);
    }
  }
}

boolean isAllEven(ListPos l){
  boolean genap = true;
  for(int i = 0; i < length(l); i++){
    if(ELMT(l,i) % 2 != 0){
      genap = false;
      break;
    }
  }
  return genap;
}

void sort(ListPos *l, boolean asc){
  if(!isEmpty(*l)){
    for(int i = 0; i < length(*l); i++){
      for(int j = i+1; j < length(*l); j++){
        int temp;
        if(asc){
          if(ELMT(*l, i) > ELMT(*l, j)){
            temp = ELMT(*l, i);
            ELMT(*l, i) = ELMT(*l, j);
            ELMT(*l, j) = temp;
          }
        }else{
          if(ELMT(*l, i) < ELMT(*l, j)){
            temp = ELMT(*l, i);
            ELMT(*l, i) = ELMT(*l, j);
            ELMT(*l, j) = temp;
          }
        }
      }
    }
  }
}

void insertLast(ListPos *l, ElType val){
  ELMT(*l, length(*l)) = val;
}

void deleteLast(ListPos *l, ElType *val){
  *val = ELMT(*l, length(*l) - 1);
  ELMT(*l, length(*l) - 1) = VAL_UNDEF;
}