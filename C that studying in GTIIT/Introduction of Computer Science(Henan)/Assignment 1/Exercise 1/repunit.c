#include <stdio.h>
int main() {
	int num;
	int i=1;
	printf("Number : ");
	scanf("%d",&num);
	while((num!=num%10)&&(i >0)){
		if(num%10!=1)
			i=-1*i;
		num=(num-(num%10))/10;
	}
	if((i ==1)&&(num!=0))
		printf("Yes");
	else
		printf("No");
	return 0;
	}
