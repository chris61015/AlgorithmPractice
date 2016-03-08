// UVa 1586:Molar mass
// Author: YuanJyun Lu

#include<stdio.h>
#include<string.h>
#define maxn 100

int main(){
  int T;
  char s[maxn];

  scanf("%d",&T);
  while(T--){
    scanf("%s",s);
    int n = strlen(s), multiple = 1;
    double sum = 0.0;
    for (int i = n-1; i>=0; i--){
      switch (s[i]){
      case 'C':
	sum += 12.01 * multiple;
	multiple = 1;
        break;
      case 'H':
	sum += 1.008 * multiple;
	multiple = 1;
	break;
      case 'O':
	sum += 16.00 * multiple;
	multiple = 1;
	break;
      case 'N':
	sum += 14.01 * multiple;
	multiple = 1;
	break;
      default:
	if ((i + 1) < n && (s[i+1] - '0') >= 0 &&(s[i+1] - '0')<= 9){
	  multiple = (s[i] - '0') * 10 + multiple;
	} else {
	  multiple = s[i] - '0';
	}
	break;
      }
    }
    printf("%.3f\n",sum);
  }
  return 0;
}


