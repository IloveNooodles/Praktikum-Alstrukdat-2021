// MUHAMMAD GAREBALDHIE ER RAHMAN
// 13520029
// PRAKTIKUM 4
// LIST DINAMIS

#include <stdio.h>
#include "listdin.h"

int main(){
  ListDin l;
  int capacity;
  scanf("%d", &capacity);
  CreateListDin(&l, capacity);
  readList(&l);
  int a;
  scanf("%d", &a);
  for(int i = 0; i < a; i++){
    int op;
    scanf("%d", &op);
    if(op == 1){
      int num;
      scanf("%d", &num);
      if(isFull(l)){
        printf("list sudah penuh\n");
      }else{
        insertLast(&l, num);
        printf("%d ", CAPACITY(l));
        displayList(l);
        printf("\n");
      }
    }else if(op == 2){
      int num;
      scanf("%d", &num);
      growList(&l, num);
      printf("%d ", CAPACITY(l));
      displayList(l);
      printf("\n");
    }else if(op == 3){
      int num;
      scanf("%d", &num);
      if(CAPACITY(l) - num < 0){
        printf("list terlalu kecil\n");
      }else{
        shrinkList(&l, num);
        printf("%d ", CAPACITY(l));
        displayList(l);
        printf("\n");
      }
    }else if (op == 4){
      compactList(&l);
      printf("%d ", CAPACITY(l));
      displayList(l);
      printf("\n");
    }
  }
}