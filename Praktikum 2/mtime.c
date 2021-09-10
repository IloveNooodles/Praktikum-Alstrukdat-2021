#include <stdio.h>
#include "time.h"

int main(){
  int r;
  TIME a, b, c, d;
  scanf("%d", &r);
  for(int i = 0; i < r; i++){
    printf("[%d]\n", i+1);
    BacaTIME(&a);
    BacaTIME(&b);
    TIME min, max;
    if(TLT(a, b)){
      min = a;
      max = b;
    }else if(TGT(a, b)){
      min = b;
      max = a;
    }else if(TEQ(a, b)){
      min = a;
      max = a;
    }

    if(i == 0){
      c = min;
      d = max;
    }else{
      if(!TLT(c, min)){
        c = min;
      }
      if(!TGT(d, max)){
        d = max;
      }
    }
    printf("%d\n", Durasi(min, max));
  }
  TulisTIME(c);
  printf("\n");
  TulisTIME(d);
  printf("\n");
}