//Uva 202:Repeating Decimals
// Author: YuanJyun Lu

#include<stdio.h>
#include<string.h>

#define maxn 3010

int main(){
  int nom, den;
  int quotient[maxn]; //record digits of quotient
  int showup[maxn]; //check whether a remainder shows up, if yes, the showup[remainder]=1, otherwise 0
  
  while (scanf("%d%d",&nom, &den) ==2){
    memset(quotient, 0, sizeof(quotient));
    memset(showup, 0 , sizeof(showup));
    printf("%d/%d = %d.", nom, den, nom/den);

    // Record digit of quotient, and whether it shows up.
    int index, cnt,remainder = nom % den;
    showup[remainder] = 1; //Record the remainder of integer part.
    for (cnt = 1; cnt < maxn; cnt++){
      quotient[cnt] = (10 * remainder) / den;
      remainder = (10 * remainder) % den;

      //If a remainder has shown up twice, break the loop.
      if (!showup[remainder]){
	index = cnt + 1; //Tricky part! showup record the digit where the remainder shows up. 
	showup[remainder] = index;
      } else {
	break;
      }      
    }

    //find out the digit where the repeating starts.
    int st = showup[remainder];

    //beware of the i<=cnt part here as well.
    for (int i = 1; i<=cnt; i++){ 
      if (i == st){
	printf("(");
      }
      printf("%d", quotient[i]);
      if(i == 50){
	printf("...");
	break;
      }
    }   
    printf(")\n");
    printf("   %d = number of digits in repeating cycle\n\n",cnt-st+1);
  }

  return 0;
}
