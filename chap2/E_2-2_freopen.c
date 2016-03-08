#include<stdio.h>
#define LOCAL

int main(){
 #ifdef LOCAL
  freopen("hanxin.in","r",stdin);
  freopen("hanxin_freopen.out","w",stdout);
#endif
  int a,b,c,i,count=0;
  while(scanf("%d%d%d", &a, &b, &c)==3){
    count++;
    for(i=10;i<=100;i++){
      if((i%3==a)&&(i%5==b)&&(i%7==c)){
	printf("Case %d: %d\n",count,i);
	break;
      }
    }
    if(i==101){
      printf("Case %d: No Answer\n", count);
    }
  }
  return 0;
}
