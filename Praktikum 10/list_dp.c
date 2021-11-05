#include "stdio.h"
#include "stdlib.h"
#include "list_dp.h"


boolean isEmpty(List l){
  return (FIRST(l) == NULL) && (LAST(l) == NULL);
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l){
  FIRST(*l) = NULL;
  LAST(*l) = NULL;
}
/* I.S. l sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
Address allocate(ElType val){
  Address p;
  p = (Address) malloc (sizeof(Node));
  if(p != NULL){
    INFO(p) = val;
    NEXT(p) = NULL;
    PREV(p) = NULL;
  }
  return p;
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NULL. */
/* Misalnya: menghasilkan P, maka INFO(P)=val, NEXT(P)=NULL, PREV(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL. */
void deallocate (Address p){
  free(p);
}
/* I.S. p terdefinisi */
/* F.S. p dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian Address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
Address search(List l, ElType val){
  Address a = FIRST(l);
  boolean found = false;
  while(a != NULL && !found){
    if(INFO(a) == val) found = true;
    else a = NEXT(a);
  }
  return a;
}
/* Mencari apakah ada elemen list dengan INFO(P)=val */
/* Jika ada, mengirimkan Address elemen tersebut. */
/* Jika tidak ada, mengirimkan NULL */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val){
  Address a = allocate(val);
  if(a != NULL){
    NEXT(a) = FIRST(*l);
    if(isEmpty(*l)){
      LAST(*l) = a;
    }else{
      PREV(FIRST(*l)) = a;
    }
    FIRST(*l) = a;
  }
}
/* I.S. List l terdefinisi */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void insertLast(List *l, ElType val){
  Address p;
  p = allocate(val);
  if(p != NULL){
    if(isEmpty(*l)){
      FIRST(*l) = p;
    }else{
      PREV(p) = LAST(*l);
      NEXT(LAST(*l)) = p;
    }
    LAST(*l) = p;
  }
}
/* I.S. List l terdefinisi */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
void insertAfter(List *L, Address p, Address pRec){
  if(LAST(*L) == pRec){
    NEXT(LAST(*L)) = p;
  }else{
    NEXT(p) = NEXT(pRec);
    PREV(p) = pRec;
    PREV(NEXT(pRec)) = p;
    NEXT(pRec) = p;
  }
}
/* I.S. pRec pasti elemen list; p sudah dialokasi */
/* F.S. Insert p sebagai elemen sesudah elemen beralamat pRec */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val){
  Address p = FIRST(*l);
  *val = INFO(p);
  if(FIRST(*l) == LAST(*l)){
    LAST(*l) = NULL;
  }else{
    PREV(NEXT(p)) = NULL;
  }
  FIRST(*l) = NEXT(p);
  free(p);
}
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada val */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLast(List *l, ElType *val){
  Address p = LAST(*l);
  *val = INFO(p);
  if(FIRST(*l) == LAST(*l)){
    FIRST(*l) = NULL;
  }else{
    NEXT(PREV(p)) = NULL;
  }
  LAST(*l) = PREV(p);
  free(p);
}
/* I.S. list l tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada val */
/*      dan alamat elemen terakhir di-dealokasi */
void deleteAfter(List *l, Address *pDel, Address pRec){
  *pDel = NEXT(pRec);
  if(*pDel == LAST(*l)){
    LAST(*l) = pRec;
    NEXT(pRec) = NULL;
  }else{
    PREV(NEXT(*pDel)) = pRec;
    NEXT(pRec) = NEXT(*pDel);
  }
}
/* I.S. List tidak kosong. pRec adalah anggota list. 
        NEXT(pRec)!=NULL */
/* F.S. Menghapus NEXT(pRec): */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l){
  Address p = FIRST(l);
  printf("[");
  if(!isEmpty(l)){
    while(p != NULL){
      printf("%d", INFO(p));
      p = NEXT(p);
      if(p != NULL){
        printf(",");
      }
    }
  }
  printf("]");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
void displayListBackwards(List l){
  Address p = LAST(l);
  printf("[");
  if(!isEmpty(l)){
    while(p != NULL){
      printf("%d", INFO(p));
      p = PREV(p);
      if(p != NULL){
        printf(",");
      }
    }
  }
  printf("]");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */