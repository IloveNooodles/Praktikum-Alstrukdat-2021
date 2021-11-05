#include <stdio.h>
#include "list_linked.c"
#include "node.c"

int main(){
  List l;
  CreateList(&l);
  Address p = newNode(5);
  insertFirst(&l, 5);
  insertFirst(&l, 6);
  insertFirst(&l, 7);
  insertFirst(&l, 8);
  insertFirst(&l, 9);
  displayList(l);
  List l2, l3;
  splitList(&l2, &l3, l);
  displayList(l2);
  displayList(l3);
}
