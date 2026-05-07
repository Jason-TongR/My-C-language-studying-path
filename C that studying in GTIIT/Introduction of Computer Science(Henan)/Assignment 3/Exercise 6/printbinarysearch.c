#include <stdio.h>
#include <stdlib.h>
#define normal_low 0
#define reset "\033[0m"
#define green_bg "\033[42m"
#define magenta_text "\033[35m"
#define magenta_green  "\033[35;42m"
void printf_function(int a[] , int low , int high , int original_low , int original_high, int middle){
	for( int i = original_low ; i <= original_high ; i++){
		if( (i >= low) && (i <= high)){
			if( i == middle)
				printf(magenta_green"%d "reset,a[i]);
			else
				printf(green_bg"%d "reset,a[i]);
		}
		else
			printf("%d ",a[i]);
	}
	printf("\n");
	for( int i = original_low; i <= original_high ; i++){
		if ( (i == low) || (i == high) )
			printf("| ");
		else
			printf("  ");
	}
	printf("\n");
	for( int i = original_low; i <= original_high ; i++){
		if ( i == low)
			printf("l ");
		else{
			if ( i == high)
				printf("h ");
			else
				printf("  ");
		}
	}
	printf("\n");
}
int search_function(int a[] , int low, int high, int original_low , int original_high ,  int aim){
	int middle = (low + high) / 2;
	if( (high - low) > 1){
		if(a[middle] == aim){                                                   //base case
			if( a[middle - 1] < a[middle]){	
				printf_function( a , low , high , normal_low, original_high  ,middle);
				return middle;
			}
			else{
				printf_function( a , low , high , normal_low , original_high, middle);
				high = middle - 1;
				return search_function(a , low , high, original_low , original_high , aim);
			}
		}
		else{
			if( (a[low] <= aim) && (aim < a[middle]) ){
				printf_function( a , low , high , normal_low , original_high, middle);
				high = middle;
				return search_function(a , low ,high , original_low , original_high , aim);
				}
			else{
				printf_function( a , low , high , normal_low , original_high, middle);
				low = middle;
				return search_function(a , low ,high , original_low , original_high , aim);
			}
					
		}
	}
	else{
		if( a[low] == aim){
			printf_function( a , low , high , normal_low , original_high , middle);	
			return low;
		}
		else{
			printf_function( a , low , high , normal_low , original_high , middle);
			return high;
		}
	}
}
int main(int argc, char*argv[]){
	if( argc != 3)
		printf("the method to use is: ./name 'size' 'num that you want to search'");
	else{
		int size = atoi(argv[1]);
		int aim = atoi(argv[2]);
		int arr[size];
		int flat = 0;
		for( int i = 0 ; i < size ; i++)
			arr[i] = 2*i;
		for( int j = 0 ; j < size ; j++)
			if( arr[j] == aim)
				flat = 1;
		if(flat)	
			printf("the number that you want to find is in the positsion %d (the position is start from 0)",search_function( arr , normal_low, size - 1 , normal_low , size - 1 , aim));
		else
			printf("error,because the element you want to find is not in the sequence.");
	}
	return 0;
}

