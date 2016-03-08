//Uva 10340:All in All
//Author: YuanJyun Lu

#define maxn 1000000
char s[maxn],t[maxn];

#include<stdio.h>
#include<string.h>

int main(){
  while(scanf("%s%s", s,t) == 2){
    
    int lens = strlen(s),lent = strlen(t);
    int i,j;
    for(i = 0, j = 0 ; i < lent  && j < lens ; i++ )
      if( t[i] == s[j] )
	j++;

    printf((j == lens)? "Yes\n":"No\n");
  }
  return 0;
}
