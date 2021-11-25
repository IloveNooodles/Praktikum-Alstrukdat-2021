// MUHAMMAD GAREBALDHIE ER RAHMAN
// 13520029
// List Rekursif
// Praktikum 12
// 18 November 2021

#include "listrec.h"

Address newNode(ElType x){
  Address p = (Address) malloc(sizeof(List));
  if(p != NULL){
    INFO(p) = x;
    NEXT(p) = NULL;
  }
  return p;
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NULL, dan misalnya
   menghasilkan p, maka INFO(p)=x, NEXT(p)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */

/* Pemeriksaan Kondisi List */
boolean isEmpty(List l){
  return l == NULL;
}
/* Mengirimkan true jika l kosong dan false jika l tidak kosong */
int isOneElmt(List l){
  return (!isEmpty(l) && NEXT(l) == NULL);
}
/* Mengirimkan true jika l berisi 1 elemen dan false jika > 1 elemen atau kosong */

/* Primitif-Primitif Pemrosesan List */
ElType head(List l){
  return INFO(l);
}
/* Mengirimkan elemen pertama sebuah list l yang tidak kosong */
List tail(List l){
  if(isEmpty(l)) return NULL;
  return NEXT(l);
}
/* Mengirimkan list l tanpa elemen pertamanya, mungkin mengirimkan list kosong */
List konso(List l, ElType e){
  Address now = newNode(e);
  NEXT(now) = l;
  return now;
}
/* Mengirimkan list l dengan tambahan e sebagai elemen pertamanya. e dialokasi terlebih dahulu. 
   Jika alokasi gagal, mengirimkan l */
List konsb(List l, ElType e){
  Address now = newNode(e);
  Address p = l;
  if(isEmpty(l)){
    return now;
  }else{
    while(NEXT(p) != NULL){
      p = NEXT(p);
    }
    NEXT(p) = now;
    return l;
  }
  
}
/* Mengirimkan list l dengan tambahan e sebagai elemen terakhirnya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan L */ 

/* Fungsi dan Prosedur Lain */
int length(List l){
  if(isEmpty(l)){
    return 0;
  }else{
    return 1 + length(NEXT(l));
  }
}
/* Mengirimkan banyaknya elemen list l, mengembalikan 0 jika l kosong */
void displayList(List l){
  if(!isEmpty(l)){
    printf("%d\n", INFO(l));
    displayList(NEXT(l));
  }
}
/* I.S. List l mungkin kosong */
/* F.S. Jika list tidak kosong, nilai list dicetak ke bawah */
/*      Dipisahkan dengan newline (\n) dan diakhiri dengan newline */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak:
  1
  20
  30
 */
/* Jika list kosong, tidak menuliskan apa-apa  */

ElType maxList (List l){
  if(isOneElmt(l)){
    return head(l);
  }else{
    if(head(l) < maxList(tail(l))){
      return maxList(tail(l));
    }else{
      return head(l);
    }
  }
}
/* Mengirimkan nilai INFO(p) yang maksimum */
ElType minList (List l){
  if(isOneElmt(l)){
    return head(l);
  }else{
    if(head(l) > minList(tail(l))){
      return minList(tail(l));
    }else{
      return head(l);
    }
  }
}
/* Mengirimkan nilai INFO(p) yang minimum */
ElType sumList (List l){
  if(isEmpty(l)){
    return 0;
  }else{
    return head(l) + sumList(tail(l));
  }
}
/* Mengirimkan total jumlah elemen List l */
float averageList (List l){
  return  (float) sumList(l) / (float) length(l);
}
/* Mengirimkan nilai rata-rata elemen list l */
/*** Operasi-Operasi Lain ***/
List inverseList (List l){
  if(isEmpty(l)){
    return NULL;
  }else{
    return konsb(inverseList(tail(l)), head(l));
  }
}
/* Mengirimkan list baru, hasil invers dari l dengan menyalin semua elemen list.
Semua elemen list baru harus dialokasi */
/* Jika alokasi gagal, hasilnya list kosong */
void splitPosNeg (List l, List *l1, List *l2){
  if(isEmpty(l)){
    *l1 = NULL;
    *l2 = NULL;
  }else{
    splitPosNeg(tail(l), l1, l2);
    if(head(l) >= 0){
      *l1 = konso(*l1, head(l));
    }else{
      *l2 = konso(*l2, head(l));
    }
  }
}
/* I.S. l mungkin kosong */
/* F.S. Berdasarkan l, dibentuk dua buah list l1 dan l2 */
/* l1 berisi semua elemen l yang positif atau 0, sedangkan l2 berisi
semua elemen l yang negatif; semua dengan urutan yang sama seperti di l */
/* l tidak berubah: Semua elemen l1 dan l2 harus dialokasi */
/* Jika l kosong, maka l1 dan l2 kosong */
void splitOnX (List l, ElType x, List *l1, List *l2){
  if(isEmpty(l)){
    *l1 = NULL;
    *l2 = NULL;
  }else{
    splitPosNeg(tail(l), l1, l2);
    if(head(l) < x){
      *l1 = konso(*l1, head(l));
    }else{
      *l2 = konso(*l2, head(l));
    }
  }
}
/* I.S. l dan x terdefinisi, l1 dan l2 sembarang. */
/* F.S. l1 berisi semua elemen l yang lebih kecil dari x, dengan urutan
kemunculan yang sama, l2 berisi semua elemen l yang tidak masuk ke
l1, dengan urutan kemunculan yang sama. */
int compareList (List l1, List l2){
  if(isEmpty(l1) && isEmpty(l2)){
    return 0;
  }else if(isEmpty(l1) && !isEmpty(l2)){
    return -1;
  } else if(!isEmpty(l1) && isEmpty(l2)){
    return 1;
  } else{
    if(head(l1) < head(l2)){
      return -1;
    }else if(head(l2) < head(l1)){
      return 1;
    }else{
      return compareList(tail(l1), tail(l2));
    }
  }
}
/* Menghasilkan: -1 jika l1 < l2, 0 jika l1 = l2, dan 1 jika l1 > l2 */
/* Jika l[i] adalah elemen l pada urutan ke-i dan |l| adalah panjang l: */
/* l1 = l2: |l1| = |l2| dan untuk semua i, l1[i] = l2[i] */
/* l1 < l2: Jika i adalah urutan elemen yang berbeda yang terkecil
dari l1 dan l2, l1[i]<l2[i] atau: Jika pada semua elemen pada
urutan i yang sama, l1[i]=l2[i], namun |l1|<|l2| */
/* Contoh: [3,5,6,7] < [4,4,5,6]; [1,2,3]<[1,2,3,4] */
/* l1>l2: kebalikan dari l1<l2 */

boolean exist(ElType x, List l){
  if(isEmpty(l)){
    return false;
  }
  else if(head(l) == x){
    return true;
  }else{
    return exist(x, tail(l));
  }
}

boolean isAllExist (List l1, List l2){
  if(isEmpty(l1)){
    return true;
  }else if(exist(head(l1), l2)){
    return isAllExist(tail(l1), l2);
  }else{
    return false;
  }
}
/* Menghasilkan true jika semua elemen dalam l1 terdapat dalam l2 (tanpa
memperhatikan urutan ataupun banyaknya elemen).
Kedua list mungkin kosong. Jika l1 kosong, maka hasilnya false. */