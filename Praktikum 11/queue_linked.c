#include "queue_linked.h"

/* Prototype manajemen memori */
Address newNode(ElType x){
  Address p;
  p = (Address)malloc(sizeof(Node));
  if(p != NULL){
    INFO(p) = x;
    NEXT(p) = NULL;
  }
  return p;
}
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x, 
   atau NULL jika alokasi gagal */
boolean isEmpty(Queue q){
  return ADDR_HEAD(q) == NULL && ADDR_TAIL(q) == NULL;
}
/* Mengirim true jika q kosong: ADDR_HEAD(q)=NULL and ADDR_TAIL(q)=NULL */
int length(Queue q){
  if(isEmpty(q)) return 0;
  else{
    int len = 1;
    Address p = ADDR_HEAD(q);
    while(p != ADDR_TAIL(q)){
      len += 1;
      p = NEXT(p);
    }
    return len;
  }
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong */

/*** Kreator ***/
void CreateQueue(Queue *q){
  ADDR_HEAD(*q) = NULL;
  ADDR_TAIL(*q) = NULL;
}
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk */

/*** Primitif Enqueue/Dequeue ***/
void enqueue(Queue *q, ElType x){
  Address p;
  p = newNode(x);
  if(p != NULL){
    if(isEmpty(*q)){
      ADDR_HEAD(*q) = p;
    }else{
      NEXT(ADDR_TAIL(*q)) = p;
    }
    ADDR_TAIL(*q) = p;
  }
}
/* Proses: Mengalokasi x dan menambahkan x pada bagian Tail dari q
           jika alokasi berhasil; jika alokasi gagal q tetap */
/* Pada dasarnya adalah proses insertLast */
/* I.S. q mungkin kosong */
/* F.S. x menjadi Tail, Tail "maju" */
void dequeue(Queue *q, ElType *x){
  Address p;
  *x = HEAD(*q);
  p = ADDR_HEAD(*q);
  ADDR_HEAD(*q) = NEXT(ADDR_HEAD(*q));
  if(ADDR_HEAD(*q) == NULL){
    ADDR_TAIL(*q) = NULL;
  }
  NEXT(p) = NULL;
  free(p);
}
/* Proses: Menghapus x pada bagian HEAD dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteFirst */
/* I.S. q tidak mungkin kosong */
/* F.S. x = nilai elemen HEAD pd I.S., HEAD "mundur" */
