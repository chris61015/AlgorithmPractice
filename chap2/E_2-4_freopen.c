#include<stdio.h>
#include<time.h>
#define LOCAL

int main(){
#ifdef LOCAL
  freopen("subseq.in","r",stdin);
  freopen("subseq_freopen.out","w",stdout);
#endif
  
  int n, m, casecnt=0;
  while(scanf("%d%d",&n,&m)==2){
    if (n==0 && m==0){
      break;
    }
    casecnt++;
    double sum = 0.0;
    for (int i=n; i<=m;i++){
      sum+=(1.0/i)/i;
    }
    printf("Case %d: %.5f\n",casecnt,sum);    
  }
   printf("Time used= %.2f\n", (double)clock()/CLOCKS_PER_SEC);
  return 0;
}
