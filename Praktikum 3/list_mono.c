// Nama: Muhammad Garebaldhie ER Rahman
// NIM: 1352029
// TANGGAL: 09 September 2021
// TOPIK: ADT LIST
// DESKRIPSI: Praktikum 3

#include <stdio.h>
#include "listpos.h"

int main(){
  ListPos l;
  readList(&l);
  boolean statics = true;
  boolean nonasc = true;
  boolean nondesc = true;
  for(int i = 0; i < length(l)-1; i++){
      if(ELMT(l, i) < ELMT(l, i+1) && nondesc){
        nondesc = false;
      }
      if(ELMT(l, i) > ELMT(l, i+1) && nonasc){
        nonasc = false;
      }
      if(ELMT(l, i) != ELMT(l, i+1) && statics){
        statics = false;
      }
    
  }
  if(statics){
    printf("Static Monotonic List\n");
  }else if(nonasc){
    printf("Non-descending Monotonic List\n");
  }else if(nondesc){
    printf("Non-ascending Monotonic List\n");
  }else if(!statics && !nondesc && !nonasc){
    printf("Non-monotonic List\n");
  }
  return 0;
}