#include "stack_linked.h"
#include <stdio.h>

int main(){
  Stack s1;
  Stack s2;
  CreateStack(&s1);
  CreateStack(&s2);
  int a, b, x, temp;
  scanf("%d %d", &a, &b);
  for(int i = 0; i < a+b; i++){
    scanf("%d", &x);
    if(i < a){
      if(x == 0){
        if(!isEmpty(s1)){
          pop(&s1, &temp);
        }
      }else{
        push(&s1, x);
      }
    }else{
      if(x == 0){
        if(!isEmpty(s2)){
          pop(&s2, &temp);
        }
      }else{
        push(&s2, x);
      }
    }
  }

  int val;
  Address p = ADDR_TOP(s1);
  if(isEmpty(s2) && !isEmpty(s1)){
      printf("Tidak sama\n");
  }else{
    while(p != NULL){
      if(INFO(p) == TOP(s2)){
        pop(&s2, &temp);
      }
      p = NEXT(p);
    }
    if(!isEmpty(s2)){
      printf("Tidak sama\n");
    }else{
      printf("Sama\n");
    }
  }
}