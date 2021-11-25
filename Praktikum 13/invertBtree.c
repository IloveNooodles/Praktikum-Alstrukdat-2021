#include "bintree.h"
#include <stdlib.h>
#include <stdio.h>

void invertBtree(BinTree *p){
  if(!isTreeEmpty(*p)){
    BinTree temp = LEFT(*p);
    LEFT(*p) = RIGHT(*p);
    RIGHT(*p) = temp;
    invertBtree(&LEFT(*p));
    invertBtree(&RIGHT(*p));
  }
}