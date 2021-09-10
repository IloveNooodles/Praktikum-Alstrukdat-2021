#include <stdio.h>
#include "time.h"

int main(){
  //Input time b
  TIME t1;
  printf("Masukan waktu yang valid\n");
  BacaTIME(&t1);
  TulisTIME(t1);
  printf(" Adalah waktu yang valid\n");

  //Merubah TIME menjadi detik
  long c = TIMEToDetik(t1);
  printf("Jika dierubah dalam detik menjadi : %li\n", c);
  printf("\n");
  //Inisialisasi time baru
  long second;
  printf("Masukan detik: ");
  scanf("%d", &second);
  TIME d = DetikToTIME(second);
  printf("Jika dalam time bentuknya menjadi: ");
  TulisTIME(d);
  printf("\n");
  printf("\n");
  //Mengecek fungsi detik
  TIME e;
  e = NextDetik(d);
  printf("1 detik selanjutnya ialah: ");
  TulisTIME(e);
  printf("\n");

  e = PrevDetik(d);
  printf("1 detik sebelumnya ialah: ");
  TulisTIME(e);
  printf("\n");
  printf("\n");
  int X;
  printf("Masukan X: ");
  scanf("%d", &X);

  e = NextNDetik(d, X);
  printf("X detik selanjutnya ialah: ");
  TulisTIME(e);
  printf("\n");

  e = PrevNDetik(d, X);
  printf("X detik sebelumnya ialah: ");
  TulisTIME(e);
  printf("\n");

  //Mengecek fungsi durasi
  long g = Durasi(t1, d);
  printf("\nJarak nya dalam detik ialah %li detik", g);

  

}