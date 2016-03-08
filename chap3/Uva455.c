#include<stdio.h>
#include<string.h>

#define maxn 90
 
 int main(){
   char s[maxn];
   int T;
   scanf("%d",&T);
   while(T--){
     scanf("%s",s);
     int n = strlen(s);
     for (int i=1; i<=n;i++){
       if ((n % i)) continue;;
       int isRepeat = 1;
       for (int j=i;j<n;j++){
	 if (s[j]!=s[j%i]){
	   isRepeat = 0;
	   break;
	 }
       }
       if(isRepeat){
	 printf("%d\n",i);
	 break;
       }
     }
     if (T) printf("\n");
   }
   return 0;
 }
