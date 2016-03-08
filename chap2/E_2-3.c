#include<stdio.h>

int main(){
  int n;
  scanf("%d",&n);

  for (int i=0; i<n; i++){
    for (int j=0; j<i;j++){
      printf(" ");
    }
    int k = 2*(n-i)-1;
    for (int l=0; l<k; l++){
      printf("#");
    }
    printf("\n");
  }
  

  return 0;
}
