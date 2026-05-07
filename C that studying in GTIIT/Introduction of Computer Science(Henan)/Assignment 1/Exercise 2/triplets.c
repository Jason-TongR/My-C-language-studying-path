#include <stdio.h>
int main(){
    int c;
    int q;
    int x=0;
    int y=1;
    int z;
    int i=1;
    do{
    printf("Enter the number of triplets to display: ");
    scanf("%d", &q);
}   while(q<=0);
    do{
    printf("Enter the constant c: ");
    scanf("%d", &c);
}   while(c<=0);
    while(i<=q){
          z=x+c*y;
          printf("(%d,%d,%d) \n",x,y,z);
          x=y;
          y=z;
          ++i;
}
   return 0;
}
