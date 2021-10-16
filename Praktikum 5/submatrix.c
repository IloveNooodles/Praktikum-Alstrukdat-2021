// MUHAMMAD GAREBALDHIE ER RAHMAN
// 13520029
// PRAKTIKUM 5 
// NO 2

#include <stdio.h>
#include "matrix.h"

int countSubMatrix(int startRow, int StartCol, int size, Matrix m){
  int total = 0;
  for(int i = startRow; i < (startRow + size); i++){
    for(int j = StartCol; j < (StartCol + size); j++){
      total += ELMT(m, i, j);
    }
  }
  return total;
}

int main(){
  int tc;
  scanf("%d", &tc);
  while(tc--){
    int n;
    scanf("%d", &n);
    Matrix m;
    readMatrix(&m, n, n);
    int size;
    scanf("%d", &size);
    int max = 0;
    int tempMax = 0;
    for(int i = 0; i < ROWS(m) - size + 1; i++){
      for(int j = 0; j < COLS(m) - size + 1; j++){
        tempMax = countSubMatrix(i, j, size, m);
        max = max < tempMax ? tempMax : max;
      }
    }
    printf("%d\n", max);
  }
}