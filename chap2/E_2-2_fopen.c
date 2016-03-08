#include<stdio.h>
#define LOCAL

int main(){
  FILE *fin, *fout;
  fin = fopen("hanxin.in", "rb");
  fout = fopen("hanxin_fopen.out", "wb");
  
  int a,b,c,i,count=0;
  while(fscanf(fin,"%d%d%d",&a, &b, &c)==3){
    count++;
    for(i=10;i<=100;i++){
      if((i%3==a)&&(i%5==b)&&(i%7==c)){
	fprintf(fout, "Case %d: %d\n",count,i);
	break;
      }
    }
    if(i==101){
      fprintf(fout,"Case %d: No Answer\n", count);
    }
  }
  fclose(fin);
  fclose(fout);
  return 0;
}
