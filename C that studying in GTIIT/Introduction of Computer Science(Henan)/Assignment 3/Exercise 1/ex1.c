#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char printf_function(char a[],int n){
	return a[n];
}
int main(int argc, char *argv[]){
	int size = strlen(argv [1]);
	int require = atoi(argv[2]);
	if(require <= size){
		printf("Output: ");
		for(int i = 0; i < require; i++){
			printf("%c",printf_function(argv[1],i));
		}
	}
	else
		printf("Invalid value for n");
	return 0;
}

