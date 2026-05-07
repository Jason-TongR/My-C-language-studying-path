#include <stdio.h>
int main(){
   int n;
   int x=0;
   printf("Number : ");
   scanf("%d", &n);
   while(n>0){
       x=n%10+x*10;
       n=n/10;
}
   printf("Reverse : %d",x);
   return 0;
}
