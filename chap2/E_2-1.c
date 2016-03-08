#include<stdio.h>
#include<math.h>

int main(){

    for(int i=100;i<=999;i++){
      double a = i / 100;
      double b = i /10 % 10;
      double c = i % 10;
      int sum = floor(pow(a,3.0)+pow(b,3.0)+pow(c,3.0));
      if (i == sum){
	printf("%d\n", i);
      }
    }     
    return 0;
}
