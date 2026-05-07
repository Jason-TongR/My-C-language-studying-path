#include <stdio.h>
#include <stdlib.h>
#define max_size 30
int check_diagonal(int a[][max_size], int n){
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++){
			if( j != i)
				if( a[i][j] != 0 )
					return 0;
		}
	return 1;
}
int main(int argc, char *argv[]){
	if(argc != 2)
		printf("use method: ./name 'the size of the matrix'");
	else{
		int our_matrix[max_size][max_size];
		int size;
		printf("please enter the value of the matrix(press Ctrl+D to end): \n");
		int line[max_size];
		int input;
		int position = 0;
		size = atoi(argv[1]);
		while ( (scanf("%d",&input)) == 1 ){
			line[position] = input;
			position++;
		}
		position = 0;
		printf("\n");
		printf("Original Matrix: \n");
		for(int i = 0; i < size; i++){
			printf("\n");
			for(int j = 0; j < size; j++){
				our_matrix[i][j] = line[position];
				printf("%d  ",our_matrix[i][j]);
				position++;	
			}
		}
		printf("\n");
		if( check_diagonal( our_matrix, size ) )
			printf("The matrix is diagonal");
		else
			printf("The matrix is not diagonal");
	}
	return 0;
}

