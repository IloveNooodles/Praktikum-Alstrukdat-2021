#include <string.h>
#include <stdio.h>
#include "stack.h"
#include <math.h>
#include "tokenmachine.h"

int main(){
  int op1, op2;
  Stack s;
  CreateStack(&s);
  startToken();
  if(endToken){
    printf("Ekspresi kosong\n");
  }
  else{
    while(!endToken){
      if(currentToken.tkn == 'b'){
        push(&s, currentToken.val);
        printf("%d\n", currentToken.val);
      }else{
        pop(&s, &op2);
        pop(&s, &op1);
        int value = 0;
        if(currentToken.tkn == '+'){
          push(&s, op1+op2);
          value = op1+op2;
        }else if(currentToken.tkn == '-'){
          push(&s, op1-op2);
          value = op1-op2;
        }else if(currentToken.tkn == '*'){
          push(&s, op1*op2);
          value = op1*op2;
        }else if(currentToken.tkn == '/'){
          push(&s, op1/op2);
          value = op1/op2;
        }else if(currentToken.tkn == '^'){
          push(&s, pow(op1, op2));
          value = pow(op1, op2);
        }
        printf("%d %c %d\n", op1, currentToken.tkn, op2);
        printf("%d\n", value);
      }
      advToken();
    }
    pop(&s, &op1);
    printf("Hasil=%d\n", op1);
  }
}
