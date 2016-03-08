#include<stdio.h>
#include<math.h>

int main(){
  printf("%s %d\n","ExpA1",11111*11111);
  printf("%s %d\n","ExpA1",111111*111111);
  printf("%s %d\n","ExpA1",111111111*111111111);
  printf("%s %f\n","ExpA2",11111.0*11111.0);
  printf("%s %f\n","ExpA2",111111.0*111111.0);
  printf("%s %f\n","ExpA2",111111111.0*111111111.0);
  printf("%s %d\n","ExpA3:sqrt(-10) integer value-",sqrt(-10));
  printf("%s %f\n","ExpA3:sqrt(-10) float value-",sqrt(-10));
  printf("%s %f %f\n","ExpA4:1.0/0.0 and  0.0/0.0-",1.0/0.0,0.0/0.0);
  printf("%s %d\n","ExpA5:1/0",1/0);
  printf("%f\n",sqrt(2));
  return 0;
}
