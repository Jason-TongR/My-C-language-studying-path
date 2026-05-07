#include <stdio.h>
int main(){
	int c=1;
	int p;
	int x; 
	int y;
	int x1=1;
	int y1=1;
	int z1;
	int z2;
	do{
	printf("Enter the perimeter: ");
	scanf("%d",&p);
	}
	while(p <= 0);
	while(c<p){
		x=0;
		y=1;
		while(x+c*y+x+y<p){
			y=x+c*y;
			x=(y-x)/c;
		}
		if (x+c*y+x+y==p){
			x1=x;
			y1=y;
			z1=c;
		}	
		else{
			if(x+y+y-c*x>x1+y1+x1+c*y1){
				x1=y-c*x;
				y1=x;
				z2=c;
			}
		}
		c++;
	}
	if (z1<z2)
		printf("The best constant c = %d has a tuple with perimeter %d",z1,x1+y1+x1+c*y1);
	else
		printf("The best constant c = %d has a tuple with perimeter %d",z2,x1+y1+x1+c*y1);
	return 0;
}
