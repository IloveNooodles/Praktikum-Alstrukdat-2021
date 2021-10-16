// Muhammad Garebaldhie ER Rahman
// 13520029
// 07/10/2021
// ADT Queue
// Praktikum 7

#include <stdio.h>
#include <stdlib.h>
#include "prioqueue.h"

int main(){
  int n;
  PrioQueue pq;
  CreatePrioQueue(&pq);
  scanf("%d", &n);
  ElType *val;
  val = (ElType*)malloc(sizeof(ElType)*n);
  if(n == 0){
    printf("Tidak ada layanan\n");
  }
  else{

    for(int j = 0; j < n; j++){
      int t,i,m,d;
      ElType el;
      scanf("%d %d %d %d", &t, &i, &m, &d);
      el.id = i;
      el.dService = d;
      el.score = m;
      el.tArrival = t; 
      val[j] = el;
    }

    int t = 1;
    int i = 0;
    boolean proccess = false;
    ElType a;
    int jumlah = 0;
    while(jumlah != n){
      if(val[i].tArrival == t){
        enqueue(&pq, val[i]);
        i++;
      }
      if(!proccess && !isEmpty(pq)){
        dequeue(&pq, &a);
        printf("%d %d %d\n", t, a.id, t - a.tArrival);
        proccess = true;
      }
      
      if(proccess){
        a.dService--;
      }

      if(proccess && a.dService == 0){
        jumlah++;
        proccess = false;
      }
      t++;
    }
  }
}