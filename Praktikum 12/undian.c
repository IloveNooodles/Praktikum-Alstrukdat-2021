// MUHAMMAD GAREBALDHIE ER RAHMAN
// 13520029
// List Rekursif
// Praktikum 12
// 18 November 2021

#include <stdio.h>
#include "listrec.h"

List splitOddIndex(List l){
  if(isEmpty(l)){
    return NULL;
  }else if(isOneElmt(l)){
    return l;
  } else{
    return konso(splitOddIndex(tail(tail(l))), head(l));
  }
}
/* Mengembalikan sebuah list baru yang elemennya adalah elemen-elemen pada indeks
ganjil pada list L, sesuai dengan urutannya. Elemen HEAD merupakan indeks 1.
Jika tidak ada elemen yang bisa diambil, kembalikan NULL */
List splitEvenIndex(List l){
  if(isEmpty(l) || isOneElmt(l)){
    return NULL;
  }else{
    return konso(splitEvenIndex(tail(tail(l))), head(tail(l)));
  }
}
/* Mengembalikan sebuah list baru yang elemennya adalah elemen-elemen pada indeks
genap pada list L, sesuai dengan urutannya. Elemen HEAD merupakan indeks 1.
Jika tidak ada elemen yang bisa diambil, kembalikan NULL */
List splitBeforeX(List l, ElType x){
  if(isEmpty(l) || head(l) == x){
    return NULL;
  }else{
    konso(splitBeforeX(tail(l), x), head(l));
  }
}
/* Mengembalikan sebuah list baru yang elemennya adalah elemen-elemen di depan elemen
dengan nilai x pada list l, sesuai dengan urutannya. Jika x tidak ada pada list, maka
kembalikan list l.
Jika tidak ada elemen yang bisa diambil, kembalikan NULL */
List reverseList(List l){
  if(isEmpty(l)){
    return NULL;
  }else{
    return konsb(reverseList(tail(l)), head(l));
  }
}
/* Mengembalikan sebuah list baru yang urutannya merupakan kebalikan dari list l.
Jika l kosong, kembalikan list kosong. */

int main(){
  List l = NULL;
  char kind;
  int value;
  scanf(" %c", &kind);
  while (kind != 'X'){
    switch(kind){
      case 'F':
        scanf("%d", &value);
        l = konso(l, value);
        break;
      case 'B':
        scanf("%d", &value);
        l = konsb(l, value);
        break;
      case 'O':
        l = splitOddIndex(l);
        break;
      case 'E':
        l = splitEvenIndex(l);
        break;
      case 'R':
        l = reverseList(l);
        break;
      case 'P':
        scanf("%d", &value);
        l = splitBeforeX(l, value);
        break;
    }
    scanf(" %c", &kind);
  }
  if(isEmpty(l)){
    printf("Semua gugur\n");
  }else{
    displayList(l);
  }
}