// Uva 1368:DNA Consensus String
// Author: Yuan Jyun Lu
#include<stdio.h>
#define maxm 64
#define maxn 1024
int main(){

  int T;
  char s[maxm][maxn];
  scanf("%d",&T);
  while (T--){    
    int m,n, cnt = 0;
    scanf("%d %d",&m,&n);

    for (int i=0; i<m; i++)
      scanf("%s",s[i]);
    /*
    Make 'ch' to be ACGT instead of other arrangements, it will automatically solve "exicographically smallest consensus string." problem while choosing the word of highest frequency to solve problem.
    */
    char ch[4] = {'A','C','G','T'};
    char str[maxn] = {};
    //Record the frequency of ACGT respectively.
    for (int j=0; j<n; j++){
      int ar[4] = {0,0,0,0}; //{A,C,G,T}
      for (int i=0; i<m;i++){
	switch(s[i][j]){
	case 'A':
	  ar[0]++;
	  break;
	case 'C':
	  ar[1]++;
	  break;
	case 'G':
	  ar[2]++;
	  break;
	case 'T':
	  ar[3]++;
	  break;
	default:
	  break;
	}
      }

      //choose a word of the highest frequency.
      int max = 0;
      for (int ind=0; ind<4; ind++){
	if (ar[ind] >ar[max]){
	  max = ind;
	}
      }
      cnt = cnt + (m - ar[max]);
      str[j] = ch[max];
    }
    printf("%s\n%d\n",str,cnt);    
  }
  
  return 0;
}
