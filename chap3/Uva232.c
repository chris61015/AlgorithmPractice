// UVa 232:Crossword Answers
// Author; YuanJyun Lu
#include<stdio.h>
#include<string.h>

int main(){
  int r, c, puzzleCnt=0;

  //Read a word and check if it is ZERO
  while (scanf("%d",&r) == 1 && r){
    scanf("%d",&c);
    char a[r][c];
    memset(a,0,sizeof(a));
    for (int i=0; i<r;i++) scanf("%s",a[i]);

    //Record the "Eligible Squares" and their numbers  
    int b[r][c], num=0;
    memset(b,0,sizeof(b));
    for (int i=0; i<r;i++){
      for (int j=0;j<c;j++){
	if (a[i][j] == '*')
	  b[i][j] = -1;
	else if (i-1<0 || j-1 <0)
	  b[i][j] = ++num;
	else if (a[i-1][j] =='*' || a[i][j-1] =='*')
	  b[i][j] = ++num;
      }
    }
    
    if(puzzleCnt) printf("\n"); //Beware of the format here: DO NOT print '\n' between the first set of input and output
    
    puzzleCnt++;
    printf("puzzle #%d:\n",puzzleCnt);

    printf("Across");
    int isNewEntry = 1;
    for (int i=0; i<r; i++){
      for (int j=0;j<c; j++){
	if (a[i][j] == '*'){
	  isNewEntry = 1;
	}else if(isNewEntry){
	  printf("\n%3d.%c",b[i][j],a[i][j]);
	  isNewEntry = 0;
	} else {
	  printf("%c", a[i][j]);
	}
      }
      isNewEntry = 1;
    }
    printf("\n");

    printf("Down");
    int isNewDownEn = 1;
    for (int i=0;i<r;i++){
      for (int j=0;j<c;j++){
	if (i==0 || (i>0 && a[i-1][j] == '*')){
	  isNewDownEn = 1;
	} else {
	  isNewDownEn = 0;
	}

        if (isNewDownEn && a[i][j]!='*'){
	  int temp = i;
	  printf("\n%3d.", b[i][j]);
	  while(a[temp][j]!='*' && temp<r){
	    printf("%c",a[temp][j]);
	    temp++;
	  }
	  isNewDownEn = 0;
	}
      }
    }
    printf("\n");
  }
  return 0;
}
