#include <stdio.h>
#define low_input 0
int find_function(int n, int low, int high){
	int middle = (high + low) / 2;
	if( (middle*middle <= n) && ( (middle + 1)*(middle + 1) > n ))
		return middle;
	else{
		if( (middle*middle) > n ){
			high = middle;
			return find_function( n, low, high);
		}
		else{
				low = middle + 1;
				return find_function( n, low, high);
		}				
	}					
}
int main(){
	int input;
	printf("please enter the number: \n");
	scanf("%d",&input);
	if(input >=0)
		printf("the x that you want to find is %d",find_function( input, low_input, input));
	else
		printf("you input must bigger than 0");
	return 0;
}

