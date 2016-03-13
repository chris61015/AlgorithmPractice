//Uva 1588:Kickdown
// Author: YuanJyun Lu

#include<stdio.h>
#include<string.h>

#define maxn 330 

int main(){
  char l[maxn], s[maxn], ws[maxn], temp[maxn];
  while (scanf("%s%s",l,s) != EOF){
    //Make sure the longer one is on the bottom.
    if (strlen(l) < strlen(s)){
      strcpy(temp,l);
      strcpy(l,s);
      strcpy(s, temp);
    }
    int ls = strlen(s);
    int ll = strlen(l);

    memset(ws,'0',sizeof(ws));

    for(int i=ls; i<ls+ll;i++){
      ws[i] = l[i-ls];
    }

    int min = ls + ll;
    int i,j;
    for (i = 0; i< ls+ll;i++){
      int flag = 1;
      for (j = 0; j<ls; j++){
	if (s[j]=='2' && ws[i+j] =='2'){
	  flag = 0;
	  break;
	}
      }
      if (flag){
	int tempMin = ll+ls;
	if ((i+j-1) > (ll+ls-1)){
	  tempMin = (i+j-1) - ls + 1;
	} else if ((i+j-1)>(ls-1) && (i>ls-1)){
	  tempMin = ll;
	} else {
	  tempMin = (ls+ll-1) - i + 1;
	}
	min = (tempMin < min)? tempMin: min;
      }
    }
    printf("%d\n",min);
  }
  return 0;
}
