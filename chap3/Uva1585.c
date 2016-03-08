#include<stdio.h>
#include<string.h>
#define maxn 100


int main(){
  int T;
  char s[maxn];
  scanf("%d",&T);
  while(T--){
    scanf("%s",s);
    int n = strlen(s),sum = 0, cnt = 0;
    for (int i=0; i<n;i++){
      if (s[i]=='O'){
	cnt++;
      }else{
	cnt=0;
      }
      sum+=cnt;
    }
    printf("%d\n",sum);
  }
  return 0;
}
