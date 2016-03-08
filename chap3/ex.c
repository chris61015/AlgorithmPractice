#include"stdio.h"
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

char inp[100];

int main()
{
  int N;
  scanf("%d", &N);
  while(N--)
    {
      scanf("%s", inp);
      int len = strlen(inp);
      int zq,i;
      for ( zq = 1; zq <= len; zq++)
	if (len % zq == 0)
	  {
	    int pd = 1;
	    for ( i = zq; i < len; i++)
	      if (inp[i] != inp[i % zq])
		{
		  pd = 0;
		  break;
		}
	    if (pd)
	      {
		printf("%d\n", zq);
		break;
	      }
	  }
      if(N>0)
	printf("\n");
    }
  return 0;
}
