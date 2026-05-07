#include <stdio.h>
int main(){
    int c;
    int x=0;
    int y=1;
    int z;
    int p;
    int sum=0;
    int i=1;
    do{
    printf("Enter the perimeter: ");
    scanf("%d", &p);
}   while(p<=0);
    do{
    printf("Enter the constant c: ");
    scanf("%d", &c);
}   while(c<=0);
    while(i==1){
          z=x+c*y;
          sum=x+y+z;
          if (sum>p){
              printf("the tuple (%d, %d, %d) in the series for c = %d has pertimeter %d (>%d)",x,y,z,c,sum,p);
              i=0;
}         else{
              x=y;
              y=z;
}
}
return 0;
}
