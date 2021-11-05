// Muhammad Garebaldhie ER Rahman
// 13520029
// 28 Oktober 2021
// praktikum 9
// linked list

#include <stdio.h>
#include "list_linked.h"

int main(){
  List l;
  CreateList(&l);
  int x;
  scanf("%d", &x);
  for(int i = 1; i <= x; i++){
    insertLast(&l, i);
  }
  int n;
  scanf("%d", &n);
  while(n--){
    int a;
    scanf("%d", &a);
    int b = indexOf(l, a);
    int tempVal;
    if(b == -1){
      deleteLast(&l, &tempVal);
      insertFirst(&l, a);
      printf("miss ");
    }else{
      deleteAt(&l, b, &tempVal);
      insertFirst(&l, a);
      printf("hit ");
    }
    displayList(l);
    printf("\n");
  }
}