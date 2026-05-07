#include <stdio.h>
int main(){
   int n;
   int digits=0;
   int greatest=0;
   printf("Number : ");
   scanf("%d", &n);
   if (n==0){
      greatest=0;
      digits=1;
}  else{
   while(n>0){
      if (greatest<=n%10){
      greatest=n%10;
}
     n=n/10;
     ++digits;
}
}
   printf("Digits : %d",digits);
   printf("Greatest : %d",greatest);
   return 0;
}
