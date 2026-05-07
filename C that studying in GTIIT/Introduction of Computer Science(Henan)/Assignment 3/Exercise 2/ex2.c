#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
	if(argc < 2){
		printf("Enter numbers (press Ctrl+D to end): \n");
		int input;
		int quantity = 0;
		float sum1 = 0;
		while((scanf("%d",&input)) == 1){
			sum1 += input;
			quantity++;
		}
		if( sum1 != 0){
			printf("\n");
			printf("Average: %.2f",sum1 / quantity);
		}
		else
			printf("no number");
	}
	else{
		float sum2 = 0;
		for(int i = 1; i <= (argc - 1); i++){
			sum2 += atoi(argv[i]);
		}
		printf("Average: ");
		printf("%.2f",sum2 / (argc - 1));
	}
	return 0;
}

