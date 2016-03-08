#include<stdio.h>
#define LOCAL
int main(){
#ifdef LOCAL
  freopen("decimal.in","r",stdin);
  freopen("decimal_freopen.out","w",stdout);
#endif
  int a,b,c,count=0;
  while (scanf("%d%d%d",&a,&b,&c)==3){
    if(a==0 && b==0 && c==0){
      break;
    }
    count++;
    printf("Case %d: ",count);
    
    printf("%d.",a/b);

    for (int i=1;i<c;i++){
      a = (a%b)*10;
      printf("%d",a/b);
    }

    a = (a%b)*10;
    int temp = a/b;
    a = (a%b)*10;
    temp = (a/b >=5)? temp+1:temp;
    printf("%d\n",temp);

  }

  return 0;
}
