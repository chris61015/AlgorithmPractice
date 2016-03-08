#include<stdio.h>
#define LOCAL

int main(){
  FILE *fin, *fout;
  fin = fopen("decimal.in","rb");
  fout = fopen("decimal_fopen.out","wb");
  
  int a,b,c,count=0;
  while (fscanf(fin,"%d%d%d",&a,&b,&c)==3){
    if(a==0 && b==0 && c==0){
      break;
    }
    count++;
    fprintf(fout,"Case %d: ",count);

    fprintf(fout,"%d.",a/b);

    for (int i=1;i<c;i++){
      a = (a%b)*10;
      fprintf(fout,"%d",a/b);
    }

    a = (a%b)*10;
    int temp = a/b;
    a = (a%b)*10;
    temp = (a/b >=5)? temp+1:temp;
    fprintf(fout,"%d\n",temp);

  }
  return 0;
}
