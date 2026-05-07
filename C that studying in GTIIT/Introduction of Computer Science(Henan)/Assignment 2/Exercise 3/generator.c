#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	int length;
	int quantity;
	int bia_low,bia_up,bia_dig,bia_sym;
	printf("please enter the length,quantity,and bias for low up dig sym: ");
	scanf("%d %d %d %d %d %d",&length,&quantity,&bia_low,&bia_up,&bia_dig,&bia_sym);
	bia_up += bia_low;
	bia_dig += bia_up;
	bia_sym += bia_dig;	
	srand(time(NULL));
	for(int i = 0; i < quantity; i++){
		for(int j = 0; j < length; j++){
			int choose;
			choose = rand() %10 + 1;
			if ((choose >= 1) && (choose <= bia_low))
				printf("%c",'a' + rand()%('z' - 'a'));
			if((choose > bia_low) && (choose <= bia_up))
				printf("%c",'A' + rand()%('Z' - 'A'));
			if((choose > bia_up) && (choose <= bia_dig))
				printf("%d",rand()%10);
			if((choose > bia_dig) && (choose <= bia_sym))
				printf("%c", '#' + rand()%('/' - '#'));

		}
		printf("\n");
	}
	return 0;	
}
