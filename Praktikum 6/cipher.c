#include <stdio.h>
#include "wordmachine.h"

int main(){
  startWord();
  int cipher = currentWord.length;
  for(int i = 0; i < currentWord.length; i++){
    currentWord.contents[i] = (char)(((int)currentWord.contents[i] - 65 + cipher) % 26 + 65);
    printf("%c", currentWord.contents[i]);
  }
  while(currentChar != MARK){
    printf(" ");
    advWord();
    for(int i = 0; i < currentWord.length; i++){
      currentWord.contents[i] = (char)(((int)currentWord.contents[i] - 65 + cipher) % 26 + 65);
      printf("%c", currentWord.contents[i]);
    }
  }
  printf(".\n");
}