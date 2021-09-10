#include <stdio.h>
#include "time.h"

boolean IsTIMEValid(int H, int M, int S){
  return (H >= 0 && H <= 23) && (M >= 0 && M <= 59) && (S >= 0 && S <= 59);
}

TIME MakeTIME(int HH, int MM, int SS){
  TIME a;
  Hour(a) = HH;
  Minute(a) = MM;
  Second(a) = SS;
  return a;
}

void BacaTIME(TIME *T){
  int HH, MM, SS;
  scanf("%d %d %d", &HH, &MM, &SS);
  if(IsTIMEValid(HH, MM, SS)){
    *T = MakeTIME(HH, MM, SS);
  }
  else {
    while(!IsTIMEValid(HH, MM, SS)){
      printf("Jam tidak valid\n");
      scanf("%d %d %d", &HH, &MM, &SS);
    }
    *T = MakeTIME(HH, MM, SS);
  }
}

void TulisTIME(TIME T){
  int HH, MM, SS;
  HH = Hour(T);
  MM = Minute(T);
  SS = Second(T);
  printf("%d:%d:%d", HH, MM, SS);
}

long TIMEToDetik(TIME T){
  int HH, MM, SS;
  HH = Hour(T);
  MM = Minute(T);
  SS = Second(T);
  long second = 3600*HH + 60*MM + SS;
  return second;
}

TIME DetikToTIME(long N){
  N = N % 86400;
  int HH, MM, SS;
  HH = N / 3600;
  N = N % 3600;
  MM = N / 60;
  N = N % 60;
  SS = N;
  TIME T = MakeTIME(HH, MM, SS);
  return T;
}

boolean TEQ(TIME T1, TIME T2){
  return (TIMEToDetik(T1) == TIMEToDetik(T2));
}

boolean TNEQ(TIME T1, TIME T2){
  return (TIMEToDetik(T1) != TIMEToDetik(T2));
}

boolean TLT(TIME T1, TIME T2){
  return (TIMEToDetik(T1) < TIMEToDetik(T2));
}

boolean TGT(TIME T1, TIME T2){
  return (TIMEToDetik(T1) > TIMEToDetik(T2));
}

TIME NextDetik(TIME T){
  long second = TIMEToDetik(T);
  second++;
  return DetikToTIME(second);
}
TIME NextNDetik(TIME T, int N){
  long second = TIMEToDetik(T);
  second += N;
  return DetikToTIME(second);
}
TIME PrevDetik(TIME T){
  return DetikToTIME(TIMEToDetik(T)-1+86400);
}
TIME PrevNDetik(TIME T, int N){
  return DetikToTIME(TIMEToDetik(T)-N+86400);
}

long Durasi(TIME TAw, TIME TAkh){
  if(TEQ(TAw, TAkh)){
    return 0;
  }else if(TLT(TAw, TAkh)){
    return (TIMEToDetik(TAkh) - TIMEToDetik(TAw));
  }else{
    return(TIMEToDetik(TAkh) + 86400 - TIMEToDetik(TAw));
  }
}
