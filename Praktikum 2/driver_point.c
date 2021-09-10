#include <stdio.h>
#include "point.h"

int main(){
  POINT p1, p2;
  printf("Masukan x1 dan y1: ");
  BacaPOINT(&p1);
  printf("Masukan x2 dan y2: ");
  BacaPOINT(&p2);
  printf("\nDalam Koordinat bentuknya: Titik 1: ");
  TulisPOINT(p1);
  printf(" Titik 2: ");
  TulisPOINT(p2);
  printf("\n\n");

  if(EQ(p1, p2)){
    printf("P1 = P2\n");
  }else{
    printf("P1 != P2\n");
  }

  if(IsOrigin(p1)){
    printf("Titik pertama ada di (0,0)\n");
  }else if(IsOnSbX(p1)){
    printf("Titik pertama ada di sumbu x\n");
  }else if(IsOnSbY(p1)){
    printf("Titik pertama ada di sumbu y\n");    
  }

  printf("Titik pertama ada di kuadran: %d", Kuadran(p1));
  POINT p3;
  p3 = NextX(p1);
  printf("\nTitik pertama jika absisnya ditambah 1 menjadi: ");
  TulisPOINT(p3);
  p3 = NextY(p1);
  printf("\nTitik pertama jika ordinatnya ditambah 1 menjadi: ");
  TulisPOINT(p3);
  float dx, dy;
  printf("\nMasukan delta x dan delta y: ");
  scanf("%f %f", &dx, &dy);
  p3 = PlusDelta(p1, dx, dy);
  printf("\nTitik pertama setelah digeser sejauh x dan y ialah: ");
  TulisPOINT(p3);

  int sbx;
  printf("\nInput 0 jika ingin dirotate terhadap sumbu y dan 1 jika rotate terhadap sb x: ");
  scanf("%d", &sbx);
  printf("\nTitik pertama dirotate terhadap sumbu menjadi: ");
  p3 = MirrorOf(p1, sbx);
  TulisPOINT(p3);
  printf("\nJarak titik pertama dengan (0,0) ialah: %.2f", Jarak0(p1));
  printf("\nJarak titik pertama dengan titik kedua ialah %.2f", Panjang(p1, p2));
  
  printf("\nInput 0 jika ingin dirotate terhadap sumbu y dan 1 jika rotate terhadap sb x: ");
  scanf("%d", &sbx);
  printf("Titik ke 2 ketika di mirror menjadi: ");
  Mirror(&p2, sbx);
  TulisPOINT(p2);
  printf("\n");

  float sudut;
  printf("Masukan sudut pemutaran: ");
  scanf("%f", &sudut);
  printf("Titik ke 2 ketika di rotate sebesar %f derajat searah jarum jam menjadi: ", sudut);
  Putar(&p2, sudut);
  TulisPOINT(p2);
  Geser(&p2, dx, dy);
  printf("\nTitik kedua setelah digeser sejauh dx dan dy menjadi: ");
  TulisPOINT(p2);
  printf("\n");
  GeserKeSbX(&p2);
  printf("\nTitik kedua setelah digeser ke sbx menjadi: ");
  TulisPOINT(p2);
  GeserKeSbY(&p2);
  printf("\nTitik kedua setelah digeser ke sbx menjadi: ");
  TulisPOINT(p2);
}