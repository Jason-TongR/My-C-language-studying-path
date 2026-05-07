#include <stdio.h>
#include <stdlib.h>
#define max_array 10000
#define normal_min_coordinate 0
int check_sorted(int a[] , int coordinate ){
	if( coordinate == 0 )                   //base case ,the lengh of the array is 1
		return 1;
	else{
		if( a[0] <= a[1] )
			return check_sorted( &a[1] , coordinate - 1);
		else
			return 0;
	}	
}
int search_function(int a[] , int max_coordinate , int min_coordinate , int aim){
	int one_third = (2*min_coordinate) / 3   +   max_coordinate / 3;
	int two_third = (2*max_coordinate) / 3   +   min_coordinate / 3;
	if( max_coordinate - min_coordinate > 1){
		if( (a[one_third] == aim) || (a[two_third] == aim) ){              //base case
			if( a[one_third] == aim ){
				if(  a[one_third - 1] < a[one_third] )
					return one_third;
				else{
					max_coordinate = one_third - 1;
					return search_function( a , max_coordinate , min_coordinate , aim);
				}
			}
			else{
				if( a[two_third - 1] < a[two_third] )
					return two_third;
				else{
					max_coordinate = two_third - 1;
					return search_function( a , max_coordinate , min_coordinate , aim);	
				}
			}	
		}
		else{
			if( (a[min_coordinate] <= aim) && (aim < a[one_third])){
				max_coordinate = one_third;
				return search_function( a , max_coordinate , min_coordinate , aim);
			}
			else{
				if ( (a[one_third] < aim) && ( aim < a[two_third] ) ){
					max_coordinate = two_third;
					min_coordinate = one_third;
					return search_function( a , max_coordinate , min_coordinate , aim);
				}
				else{
					min_coordinate = two_third;
					return search_function( a , max_coordinate , min_coordinate , aim);				
				}
			}
		}
	}
	else{
		if( a[min_coordinate] == aim )
			return min_coordinate;
		else
			return max_coordinate;
	}
}
int main(int argc, char*argv[]){
	if(argc == 2){
		int input;
		int arr[max_array];
		printf("please enter the value of you sequence,type'num1 num2 num3 ...'(press Ctrl+D to end): \n");
		int i = 0;
		while((scanf("%d",&input) == 1) && (i < max_array)){
			arr[i] = input;
			i++;
		}
		if( check_sorted(arr , i - 1) ){
			int aim = atoi(argv[1]);
			int flat = 0;
			printf("\n");
			for(int check = 0; check < i; check++){            //check whether the aim value is in the array.
				if ( aim == arr[check] )
					flat = 1;
			}
			if( flat == 1 )
				printf("the value is in the position %d (the position is start from 0)",search_function(arr , i - 1 , normal_min_coordinate , aim));
			else
				printf("this is an error,because your value should in the sequence");
		}
		else{
			printf("\n");
			printf("please enter a sorted sequence");
		}
		}
	else
		printf("method to use is:  ' ./name num '      note:the num is the number that you want to find in the sequence.you will enter sequence in the standard input.");
	return 0;
}

