// Muhammad Garebaldhie ER Rahman
// 13520029
// 26-10-2021
// linked list
// Pra praktikum 9


#include <stdio.h>
#include <stdlib.h>
#include "list_linked.h"

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l){
  FIRST(*l) = NULL;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l){
  return FIRST(l) == NULL;
}
/* Mengirim true jika list kosong */

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx){
  Address p = l;
  int i = 0;
  while(i < idx){
    i += 1;
    p = NEXT(p);
  }
  return INFO(p);
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

void setElmt(List *l, int idx, ElType val){
  Address p = *l;
  int i = 0;
  while(i < idx){
    i += 1;
    p = NEXT(p);
  }
  INFO(p) = val;
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

int indexOf(List l, ElType val){
  int idx = 0;
  Address p = l;
  boolean found = false;
  while(p != NULL && !found){
    if(INFO(p) == val){
      found = true;
    }else{
      idx += 1;
      p = NEXT(p);
    }
  }
  if(found){
    return idx;
  }else{
    return IDX_UNDEF;
  }
}
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val){
  Address p = newNode(val);
  if (p != NULL){
    NEXT(p) = *l;
    *l = p;
  }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLast(List *l, ElType val){
  if(isEmpty(*l)){
    insertFirst(l, val);
  }else{
    Address p = newNode(val);
    if(p != NULL){
      Address last = *l;
      while(NEXT(last) != NULL){
        last = NEXT(last);
      }
      NEXT(last) = p;
    }
  }
}

/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAt(List *l, ElType val, int idx){
  if(idx == 0){
    insertFirst(l, val);
  }else{
    Address p = newNode(val);
    if(p != NULL){
      int i = 0;
      Address last = *l;
      while(i < idx - 1){
        i++;
        last = NEXT(last);
      }
      NEXT(p) = NEXT(last);
      NEXT(last) = p;
    }
  }

}
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val){
  Address p = *l;
  *val = INFO(*l);
  *l = NEXT(p);
  free(p);
}
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLast(List *l, ElType *val){
  Address loc = NULL;
  Address p = *l;
  while(NEXT(p) != NULL){
    loc = p;
    p = NEXT(p);
  }
  if(loc == NULL){
    *l = NULL;
  }else{
    NEXT(loc) = NULL;
  }
  *val = INFO(p);
  free(p);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAt(List *l, int idx, ElType *val){
  if(idx == 0){
    deleteFirst(l, val);
  }else{
    Address loc = *l;
    Address p;
    int i = 0;
    while(i < idx - 1){
      i++;
      loc = NEXT(loc);
    }
    p = NEXT(loc);
    *val = INFO(p);
    NEXT(loc) = NEXT(p);
    free(p);
  }
}
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */


/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l){
  printf("[");
  Address p = l;
  while(p != NULL){
    printf("%d", INFO(p));
    p = NEXT(p);
    if(p != NULL){
      printf(",");
    }
  }
  printf("]");
}
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int length(List l){
  int len = 0;
  Address p = l;
  while(p != NULL){
    len += 1;
    p = NEXT(p);
  }
  return len;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2){
  List l3;
  CreateList(&l3);
  Address p = l1;
  while(p != NULL){
    insertLast(&l3, INFO(p));
    p = NEXT(p);
  }
  p = l2;
  while(p != NULL){
    insertLast(&l3, INFO(p));
    p = NEXT(p);
  }
  return l3;
}
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */

boolean fSearch(List l, Address p){
  Address loc = l;
  while(loc != NULL){
    if(INFO(loc) == p->info){
      return true;
    }else{
      loc = NEXT(loc);
    }
  }
  return false;
}
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */

Address searchPrec(List l, ElType X){
  Address pointer1 = NULL;
  Address pointer2 = l;
  while(INFO(pointer2) != X && pointer2 != NULL){
    pointer1 = pointer2;
    pointer2 = NEXT(pointer2);
  }
  return pointer1;
}
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
ElType max(List l){
    Address p = l;
    int tempMax = INFO(p);
    while(p != NULL){
      if(tempMax < INFO(p)){
        tempMax = INFO(p);
      }
      p = NEXT(p);
    }
    return tempMax;
}
/* Mengirimkan nilai info(P) yang maksimum */
Address adrMax(List l){
  Address p = l;
  Address q = l;
  while (q != NULL){
    if(INFO(p) < INFO(q)){
      p = q;
    }
    q = NEXT(q);
  }
  return p;
}
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
ElType min(List l){
    Address p = l;
    int tempMin = INFO(p);
    while(p != NULL){
      if(tempMin > INFO(p)){
        tempMin = INFO(p);
      }
      p = NEXT(p);
    }
    return tempMin;
}
/* Mengirimkan nilai info(P) yang minimum */
Address adrMin(List l){
  Address p = l;
  Address q = l;
  while (q != NULL){
    if(INFO(p) > INFO(q)){
      p = q;
    }
    q = NEXT(q);
  }
  return p;
}
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
float average(List l){
  float sum = 0;
  int count = 0;
  Address p = l;
  while(p != NULL){
    sum += INFO(p);
    p = NEXT(p);
    count++;
  }
  return sum/count;
}
/* Mengirimkan nilai rata-rata info(P) */

/****************** PROSES TERHADAP LIST ******************/
void delAll(List *l){
  int tmpVal;
  while(!isEmpty(*l)){
    deleteLast(l, &tmpVal);
  }
  free(*l);
}
/* Delete semua elemen list dan alamat elemen di-dealokasi */

void inverseList(List *l){
  int len = length(*l) - 1;
  int temp;
  while(len != 0){
    len--;
    deleteAt(l, len, &temp);
    insertLast(l, temp);
  }
}
// /* I.S. sembarang. */
// /* F.S. elemen list dibalik : */
// /* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
// /* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */

List fInverseList(List l){
  List l2;
  CreateList(&l2);
  int len = length(l);
  while(len != 0){
    len--;
    insertLast(&l2, getElmt(l, len));
  }
  return l2;
}
// /* Mengirimkan list baru, hasil invers dari L */
// /* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
// /* Jika alokasi gagal, hasilnya list kosong */
// /* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */

void copyList(List *l1, List *l2){
  *l2 = *l1;
}
// /* I.S. L1 sembarang. F.S. L2=L1 */
// /* L1 dan L2 "menunjuk" kepada list yang sama.*/
// /* Tidak ada alokasi/dealokasi elemen */

List fCopyList(List l){
  List l2;
  CreateList(&l2);
  copyList(&l, &l2);
  return l2;
}
// /* Mengirimkan list yang merupakan salinan L */
// /* dengan melakukan alokasi. */
// /* Jika ada alokasi gagal, hasilnya list kosong dan */
// /* semua elemen yang terlanjur di-alokasi, harus didealokasi */

void cpAllocList(List lIn, List *lOut){
    Address p;
    boolean success = true;
    while(lIn != NULL){
      p = newNode(INFO(lIn));
      if(p != NULL){
        insertLast(lOut, INFO(lIn));
        lIn = NEXT(lIn);
        continue;
      }
      success = false;
    }

    if(!success){
      *lOut = NULL;
    }
}
// /* I.S. lIn sembarang. */
// /* F.S. Jika semua alokasi berhasil,maka lOut berisi hasil copy lIn */
// /* Jika ada alokasi yang gagal, maka lOut=Nil dan semua elemen yang terlanjur dialokasi, didealokasi */
// /* dengan melakukan alokasi elemen. */
// /* lOut adalah list kosong jika ada alokasi elemen yang gagal */

void splitList(List *l1, List *l2, List l){
    int i, counter;
    List ltemp;
    ElType val;
    CreateList(l1);
    CreateList(l2); 
    CreateList(&ltemp);
    ltemp = fCopyList(l);
    counter = length(l) / 2;
    while (counter > 0) {
        deleteFirst(&ltemp, &val);
        insertLast(l1, val);
        counter--;
    }
    while (!isEmpty(ltemp)) {
        deleteFirst(&ltemp, &val);
        insertLast(l2, val);
    }
}
// /* I.S. l mungkin kosong */
// /* F.S. Berdasarkan L, dibentuk dua buah list l1 dan l2 */
// /* L tidak berubah: untuk membentuk l1 dan l2 harus alokasi */
// /* l1 berisi separuh elemen L dan l2 berisi sisa elemen L */
// /* Jika elemen L ganjil, maka separuh adalah length(L) div 2 */