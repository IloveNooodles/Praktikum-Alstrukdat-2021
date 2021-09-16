#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"

void CreateListDin(ListDin *l, int capacity){
  CAPACITY(*l) = capacity;
  NEFF(*l) = 0;
  BUFFER(*l) = malloc(capacity*sizeof(int));
}
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void dealocate(ListDin *l){
  CAPACITY(*l) = 0;
  NEFF(*l) = 0;
  free(BUFFER(*l));
}
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListDin l){
  return NEFF(l);
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
IdxType getLastIdx(ListDin l){
  return NEFF(l) - 1;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, int i){
  return (i >= 0 && i < CAPACITY(l));
}
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEff(ListDin l, IdxType i){
  return (i >= 0 &&  i < NEFF(l));
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l){
  return (length(l) == 0);
}
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFull(ListDin l){
  return (length(l) == CAPACITY(l));
}
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l){
  int n;
  scanf("%d", &n);
  while(n < 0 || n > CAPACITY(*l)){
    scanf("%d", &n);
  }
  int i;
  int x;
  for(i = 0; i < n; i++){
    scanf("%d", &x);
    ELMT(*l, i) = x;
  }
  NEFF(*l) = n;
}
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
void displayList(ListDin l){
  printf("[");
  int i;
  for(i = 0; i < NEFF(l); i++){
    printf("%d", ELMT(l, i));
    if( i != NEFF(l) - 1){
      printf(",");
    }
  }
  printf("]");
}
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus){
  ListDin l;
  CreateListDin(&l, CAPACITY(l1));
  NEFF(l) = NEFF(l1);
  if(plus){
    for(int i = 0; i < length(l1); i++){
      ELMT(l, i) = ELMT(l1, i) + ELMT(l2, i);
    }
  }else{
    for(int i = 0; i < length(l1); i++){
      ELMT(l, i) = ELMT(l1, i) - ELMT(l2, i);
    }    
  }
  return l;
}
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2){
  boolean eq = true;
  if(length(l1) == length(l2)){
    for(int i = 0; i < length(l1); i++){
      if(ELMT(l1, i) != ELMT(l2, i)){
        eq = false;
        break;
      }
    }
  }else eq = false;
  return eq;
}
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val){
  int idx = IDX_UNDEF;
  for(int i = 0; i < length(l); i++){
    if(ELMT(l, i) == val){
      idx = i;
      break;
    }
  }
  return idx;
}
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void extremes(ListDin l, ElType *max, ElType *min){
  for(int i = 0; i < length(l); i++){
    if(i == 0){
      *max = ELMT(l, i);
      *min = ELMT(l, i);
    }
    if(*max < ELMT(l,i)){
      *max = ELMT(l,i);
    }
    if(*min > ELMT(l, i)){
      *min = ELMT(l, i);
    }  
  }
}
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */

/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut){
  dealocate(lOut);
  CreateListDin(lOut, CAPACITY(lIn));
  NEFF(*lOut) = NEFF(lIn);
  for(int i = 0; i < length(lIn); i++){
    ELMT(*lOut, i) = ELMT(lIn, i);
  }
}
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */
ElType sumList(ListDin l){
  int sum = 0;
  for(int i = 0; i < length(l); i++){
    sum += ELMT(l, i);
  }
  return sum;
}
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
int countVal(ListDin l, ElType val){
  int count = 0;
  for(int i = 0; i < length(l); i++){
    if(val == ELMT(l, i)) count++;
  }
  return count;
}
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
boolean isAllEven(ListDin l){
  boolean genap = true;
  for(int i = 0; i < length(l); i++){
    if(ELMT(l, i) %2 != 0){
      genap = false;
      break;
    }
  }
  return genap;
}
/* Menghailkan true jika semua elemen l genap. l boleh kosong */

/* ********** SORTING ********** */
void sort(ListDin *l, boolean asc){
  int idx = 0;
  if(asc){
    for(int i = 0; i < length(*l); i++){
      int idxmin = i;
      for(int j = i+1; j < length(*l); j++){
        if(ELMT(*l, idxmin) > ELMT(*l, j)){
          idxmin = j;
        }
      }
      int temp = ELMT(*l, idx);
      ELMT(*l, idx) = ELMT(*l, idxmin);
      ELMT(*l, idxmin) = temp;
      idx++;
    }
  }else{
    for(int i = 0; i < length(*l); i++){
      int idxmax = i;
      for(int j = i+1; j < length(*l); j++){
        if(ELMT(*l, idxmax) < ELMT(*l, j)){
          idxmax = j;
        }
      }
      int temp = ELMT(*l, idx);
      ELMT(*l, idx) = ELMT(*l, idxmax);
      ELMT(*l, idxmax) = temp;
      idx++;
      }
  }
}
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDin *l, ElType val){
  NEFF(*l) = NEFF(*l)+1;
  ELMT(*l, NEFF(*l)-1) = val;
}
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val){
  *val = ELMT(*l, NEFF(*l) - 1);
  NEFF(*l) = NEFF(*l) - 1;
}
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void growList(ListDin *l, int num){
  ListDin l2;
  CreateListDin(&l2, CAPACITY(*l) + num);
  NEFF(l2) = NEFF(*l);
  for(int i = 0; i < length(*l); i++){
    ELMT(l2, i) = ELMT(*l, i);
  }
  free(BUFFER(*l));
  *l = l2;
}
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void shrinkList(ListDin *l, int num){
  ListDin l2;
  CreateListDin(&l2, CAPACITY(*l) - num);
  NEFF(l2) = NEFF(*l);
  if(NEFF(l2) > CAPACITY(l2)){
    NEFF(l2) = CAPACITY(l2);
  }
  for(int i = 0; i < length(*l); i++){
    ELMT(l2, i) = ELMT(*l, i);
  }
  // free(BUFFER(*l));
  *l = l2;
}
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

void compactList(ListDin *l){
  ListDin l2;
  CreateListDin(&l2, NEFF(*l));
  NEFF(l2) = NEFF(*l);
  for(int i = 0; i < length(*l); i++){
    ELMT(l2, i) = ELMT(*l, i);
  }
  free(BUFFER(*l));
  *l = l2;
}
/* Proses : Mengurangi capacity sehingga nEff = capacity */
/* I.S. List lidak kosong */
/* F.S. Ukuran nEff = capacity */