//Uva 1225 Digital Counting
// Author YuanJyun Lu
#include<stdio.h>
#include<string.h>
#define maxn 10005
int main(){

  int T, a[maxn][10];
  memset(a,0,sizeof(a));
  for (int i=2; i<=10000;i++){
    for (int j=1;j<=i;j++){
      int temp = j;
      a[i][temp%10]++;
      while(temp/10 >0){
        a[i][(temp/10)%10]++;
        temp /= 10;
      }
    }
  }
  
  scanf("%d",&T);
  while (T--){
    int n,i;
    scanf("%d",&n);
    for (i=0;i<9;i++){
      printf("%d ",a[n][i]);
    }
    printf("%d\n",a[n][i]); 
  }
  //printf("\n");
  /*  
  for (int i =1;i<=10000;i++){
    for(int j=0; j<10;j++){
      printf("%d ",a[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  */
  return 0;
}
