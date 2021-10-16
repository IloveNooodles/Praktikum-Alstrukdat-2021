// Muhammad Garebaldhie ER Rahman
// 13520029
// 07/10/2021
// ADT Queue
// Praktikum 7

#include <stdio.h>
#include "queue.h"

float avgElmt(Queue Q){
  float sum = 0;
  for(int i = IDX_HEAD(Q); i <= IDX_TAIL(Q); i++){
    sum += Q.buffer[i];
  }
  return sum/length(Q);
}

int main(){
  int status= 999;
  Queue q;
  CreateQueue(&q);
  while(status != 0){
    scanf("%d", &status);
    if(status == 0){
      break;
    }
    int x;
    int temp = 0;
    if(status == 1){
      scanf("%d", &x);
      if(isFull(q)){
        printf("Queue penuh\n");
      }else{
        enqueue(&q, x);
      }
    }else if (status == 2){
      if(isEmpty(q)){
        printf("Queue kosong\n");
      }else{
        dequeue(&q, &temp);
      }
    }
  }
  if(isEmpty(q)){
    printf("0\n");
    printf("Tidak bisa dihitung\n");
  }else{
  printf("%d\n", length(q));
  printf("%.2f\n", avgElmt(q));
  }
}