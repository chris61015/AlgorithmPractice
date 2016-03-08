// Uva 227
// Author: YuanJyun Lu

/*

	Output Format:
	(SHOULD NOT have a \n)
	Puzzle #1:
	T R G S J(SHOULD NOT HAVE A ' ' after the last element of a row)
	X O K L I
	M D V B N
	W P   A E
	U Q H C F

	Puzzle #2:
	  A B C D
	F G H I E
	K L M N J
	P Q R S O
	T U V W X

	Puzzle #3:
	This puzzle has no final configuration.
	(SHOULD NOT have a \n)	

*/
#include<stdio.h>
int main(){
  char c;
  char m[5][7];//7 for \n and \0  
  int isOver = 0, cnt = 0, init = 1;
  // Scanf is not suitable here, because scanf("%c") will stop reading once it reads any space.
  
  while(1){
    int sm = 0, sn = 0;    
    for (int i=0;i<5;i++){
      fgets(m[i], 7, stdin);
      printf("m[i]:%s\n",m[i]);
      if (m[i][0]=='Z'){
	isOver = 1;
	break;
      }
    }
    if (isOver) break;
    (init == 1)? init=0: printf("\n");// The output format should not include '\n' at the beginning and the end.

    for (int i=0; i<5;i++){
      for (int j=0; j<7;j++){
	if (m[i][j] == ' '){
	  sm = i;
	  sn = j;
	}
      }
    }
    
    int isOK = 1;
    while ((c=getchar()) != '0'){
      if (c == '\n' || c == ' ' || !isOK) continue;
      char temp;
      if (isOK){
	switch(c){
	case 'A':
	  if (sm - 1 >= 0){
	    temp = m[sm - 1][sn];
	    m[sm - 1][sn] = m[sm][sn];
	    m[sm][sn]=temp;
	    sm--;
	  } else{
	    isOK = 0;
	  }
	  break;
	case 'B':
	  if (sm + 1 <= 4){
	    temp = m[sm + 1][sn];
	    m[sm + 1][sn] = m[sm][sn];
	    m[sm][sn]=temp;
	    sm++;
	  } else{
	    isOK = 0;
	  }
	  break;
	case 'R':
	  if (sn + 1 <= 4){
	    temp = m[sm][sn + 1];
	    m[sm][sn + 1] = m[sm][sn];
	    m[sm][sn] = temp;
	    sn++;
	  } else{
	    isOK = 0;
	  }
	  break;
	case 'L':
	  if (sn - 1 >= 0){
	    temp = m[sm][sn - 1];
	    m[sm][sn - 1] = m[sm][sn];
	    m[sm][sn]=temp;
	    sn--;
	  } else{
	    isOK = 0;
	  }
	  break;
	default:
	  break;
	}
      }
    }
    c = getchar(); //read '\n'
    
    cnt++;
    printf("Puzzle #%d:\n",cnt);
    if (!isOK){
      printf("This puzzle has no final configuration.\n");
    }else {
      for (int i=0; i<5;i++){
	for (int j=0;j<5;j++){
	  printf(j == 4 ? "%c" : "%c ", m[i][j]); // It is not allowed to make " " show up after the last column.
	}
	printf("\n");
      }
    }
  }
  return 0;
}

 
