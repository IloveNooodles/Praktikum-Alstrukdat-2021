#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>

void merkleTree(BinTree *p, int level){
  if(level == 0){
    int x;
    scanf("%d", &x);
    *p = newTreeNode(x);
  } else{
    BinTree p1, p2;
    merkleTree(&p1, level-1);
    merkleTree(&p2, level-1);
    *p = NewTree(ROOT(p1) + ROOT(p2), p1, p2);
  }
}

int main(){
  BinTree p = NULL;
  int n;
  int level = 0;
  scanf("%d", &n);
  int temp = n;
  while(temp % 2 == 0 && temp > 0){
    temp = temp/2;
    level++;
  }
  if(temp != 1){
    printf("Jumlah masukan tidak sesuai\n");
  }else{
    merkleTree(&p, level);
    printTree(p, 2);
  }
}