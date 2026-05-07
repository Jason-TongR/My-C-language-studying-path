#include <stdio.h>
#define difference1 5
#define difference2 21
int main(){
	int input;
	while((input = getchar()) != EOF){
		if((('f' <= input)&&(input <= 'z')) || (('F' <= input)&&(input <= 'Z')))
			printf("%c",input - difference1);
		else{
			if((('a' <= input)&&(input <='e')) || (('A' <= input)&&(input <='E')))				
				printf("%c",input + difference2);	
			else
				printf("%c",input);
			}
	}
	return 0;
}
