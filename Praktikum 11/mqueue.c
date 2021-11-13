#include <stdio.h>
#include "queue_linked.h"

int main(){
  Queue pq;
  CreateQueue(&pq);
  int d;
  scanf("%d", &d);
  for(int i = 0; i < d; i++){
    int x;
    scanf("%d", &x);
    enqueue(&pq, x);
    while(x - HEAD(pq) > 300){
      int val;
      dequeue(&pq, &val);
    }
    printf("%d\n", length(pq));
  }
}