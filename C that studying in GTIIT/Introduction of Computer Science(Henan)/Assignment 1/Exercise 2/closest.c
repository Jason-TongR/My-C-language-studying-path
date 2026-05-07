#include <stdio.h>
int main(){
	int c;
	int p;
	int x=0;
	int y=1;
	int z;
	int k;
	do{
	printf("Enter perimeter: ");
	scanf("%d",&p);
	}
	while(p <=0);
	do{
	printf("Enter the constant c : ");
	scanf("%d",&c);
	}
	while(c <=0);
	while(x+c*y+x+y<p){
	 	if(x <= c*y)
			z=x;
		else
			z=c*y;
		k=(x+c*y-z)/c;
		y=x+c*y;
		x=k;
	}
	if (x+y+x+c*y==p)
		printf("The closest (%d ,%d ,%d) for the constant c=%d has perimeter %d (equal to %d)\n",x,y,x+c*y,c,x+c*y+x+y,p);
	else{
		if(x+y+c*y-p<p-(x+y+z))
			printf("The tuple (%d ,%d ,%d) for the constant c=%d has perimeter %d (greater than %d)\n",x,y,x+c*y,c,x+c*y+x+y,p);
		else
		printf("The tuple (%d ,%d ,%d) for the constant c=%d has perimeter %d (smaller than %d)\n",z,x,y,c,z+x+y,p);
	}
	return 0;
}
