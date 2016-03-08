#include<stdio.h>
#include<time.h>
#define LOCAL

int main(){
  FILE *fin, *fout;
  fin = fopen("subseq.in","rb");
  fout = fopen("subseq_foepn.out","wb");
  
  int n, m, casecnt=0;
  while(fscanf(fin, "%d%d",&n,&m)==2){
    if (n==0 && m==0){
      break;
    }
    casecnt++;
    double sum = 0.0;
    for (int i=n; i<=m;i++){
      sum+=(1.0/i)/i;
    }
    fprintf(fout,"Case %d: %.5f\n",casecnt,sum);
  }
  fprintf(fout,"Time used= %.2f\n", (double)clock()/CLOCKS_PER_SEC);
  fclose(fin);
  fclose(fout);
  return 0;
}
