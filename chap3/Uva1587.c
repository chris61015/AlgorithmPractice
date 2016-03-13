//UVa 1587:Box
//Author: YuanJyun Lu

#include<stdio.h>

int main(){
  int edge[6][2];

  while (scanf("%d%d", &edge[0][0], &edge[0][1])==2){
    int temp;

    //sort pair of edges asc
    if (edge[0][0] > edge[0][1]){
      temp = edge[0][0];
      edge[0][0] = edge[0][1];
      edge[0][1] = temp;
    }

    for (int i=1; i<6;i++){
      for (int j=0; j<2; j++){
	scanf("%d", &edge[i][j]);
      }
      if (edge[i][0] > edge[i][1]){
	temp = edge[i][0];
	edge[i][0] = edge[i][1];
	edge[i][1] = temp;
      }
    }

    //sort rectangulars asc
    int temp0,temp1;
    for (int i=1; i<6;i++){
      for (int j=i; j>0; j--){
	if (edge[j][0] == edge[j-1][0]){
	  if (edge[j][1] < edge[j-1][1]){
	    temp0 = edge[j][0];
	    edge[j][0] = edge[j-1][0];
	    edge[j-1][0] = temp0;

	    temp1 = edge[j][1];
	    edge[j][1] = edge[j-1][1];
	    edge[j-1][1] = temp1;
	  }
	} else if (edge[j][0] < edge[j-1][0]){
	  temp0 = edge[j][0];
	  edge[j][0] = edge[j-1][0];
	  edge[j-1][0] = temp0;

	  temp1 = edge[j][1];
	  edge[j][1] = edge[j-1][1];
	  edge[j-1][1] = temp1;
	}
      } 
    }

    //check if six rectangulars could be coupled, if not, they are not possible to form a box.
    int flag = 1; 
    for (int i=0;i<6;i+=2){
      for (int j=0; j<2;j++){
	if (edge[i][j]!=edge[i+1][j]){
	  flag = 0;
	  break;
	}
      }
      if (!flag) break;
    }
    
    // The tricky part! Becasue we've already sorted edges, so we could know the index of shortest edge and longest edge. 
    if (flag && edge[0][0] == edge[2][0] && edge[0][1] == edge[4][0] && edge[2][1] == edge[4][1])
      printf("POSSIBLE\n");
    else
      printf("IMPOSSIBLE\n");

  }
  return 0;
}
