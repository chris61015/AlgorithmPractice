#include<stdio.h>

int main(){
  int abc, def, ghi,temp,isFound,cnt;
  for (int i=123;i<=329;i++){
    abc = i;
    def = 2*i;
    ghi = 3*i;
    int n = abc*1e6 + def*1e3 + ghi;

    isFound = 0;
    for (int j=1; j<=9; j++){
      isFound = 0;
      cnt = n;
      while(1){
	temp = cnt % 10;
	//	printf("%d %d %d\n",cnt,temp, j);
        if (temp == 0){
	  break;
	}
	if(temp == j){
	  isFound = 1;
	  break;
	} else{
      	  cnt /= 10;
	}
      }
    }
    if (!isFound){
      continue;
    }

    printf("%d\n",n);
  }

  return 0;
}
