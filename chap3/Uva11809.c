//Uva 11809: Floating-Point Numbers
// Author: YuanJyun Lu
#include<stdio.h>
#include<math.h>
#include<string.h>
#define maxM 20
#define maxE 40

const double gap = 1e-4;

 
 int main(){
   double  ME[maxM][maxE];
   /*
     Make a chart here to record all possible values!
     m = 1 - 2^(-1-M)(by the formula of geometric progression), e = 2^E - 1(by the formula of geometric progression)
     m * 2^e = A * B^10, but it may overflow if we directly put the value of 2^e into chart
     So we could apply log10 on both sides, the reason to use log10 is because we could directly use B from scanf
   */
   for (int i=0; i<=9;i++){
     for (int j=1; j<=30;j++){
       double m = 1 - pow(2,-1-i);
       double e = pow(2,j)-1;
       double t = log10(m) + e * log10(2);
       ME[i][j] = t;
     }
   }

   //Get the input string 
   char s[25];
   double A, lg;
   int B;
   while((scanf("%s",s)!=EOF) && strcmp(s,"0e0")){
     for (int i=0; i<strlen(s);i++){
       if (s[i]=='e'){
	 s[i] = ' ';
	 break;
       }
     }

     sscanf(s,"%lf %d",&A,&B);
     lg = log10(A)+B;
     int flag = 0;
     for (int i=0; i<=9;i++){
       for (int j=1; j<=30; j++){
	 //Because the double format is not precise, so we should tolerate some possible errors.
	 if (fabs(ME[i][j]-lg) < gap){
	   printf("%d %d\n",i,j);
	   flag = 1;
	   break;
	 }
       }
       if(flag) break;
     }
   }

   return 0;
}
