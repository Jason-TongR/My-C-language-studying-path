#include <stdio.h>
#include <stdlib.h>
#define normal_low 0
#define normal_count 0
#define max_size 50000
int li_search_function(int a[] , int low, int high, int aim , int count){
	int i;
	for( i = low ; i <= high ; i++){
		if( a[i] != aim )
			count++;
		else{
			count++;	
			return count;
		}
	}
	return count;
}
int bi_search_function(int a[] , int low, int high, int aim , int count){
	int middle = (low + high) / 2;
	if( (high - low) > 1){
		if(a[middle] == aim){                                                   //base case
			if( a[middle - 1] < a[middle]){
				count++;
				return count;
			}
			else{
				high = middle - 1;
				count++;
				return bi_search_function(a , low , high, aim , count);
			}
		}
		else{
			if( (a[low] <= aim) && (aim < a[middle]) ){
				high = middle;
				count++;
				return bi_search_function(a , low ,high , aim , count);
				}
			else{
				low = middle;
				count++;
				return bi_search_function(a , low ,high , aim , count);
			}
					
		}
	}
	else{
		if( a[low] == aim){
			count++;
			return count;
		}
		else{
			count++;
			return count;
		}
	}
}
int main(int argc, char*argv[]){
	if( argc != 3) 
		printf("the method to use is: ./name 'size' 'step'   (step < size < 50000)");
	else{
		int size = atoi(argv[1]);
                int step = atoi(argv[2]);
		if( (size >=50000) || (step >= size))
			 printf("the method to use is: ./name 'size' 'step'   (step < size < 50000)");
		else{
			printf("************************************************************************************************************************\n");
			printf("             *************         Linear           ***               Binary                      *****************     \n");
			printf("  Step  ****************************************************************************************************************\n");
			printf(" **       Min      Max     Avg       Absent         ***         Min        Max         Avg         Absent         **    \n");
			printf("************************************************************************************************************************\n");
			for( int j = step ; j <= size ; j = j*step){
				int arr[size];
				for( int i = 0 ; i < j ; i++)
					arr[i] = i + 1;
				int count_in_bi;
				int count_in_li;
				int li_count_absent = li_search_function( arr , normal_low , j - 1 , size , normal_count);
                                int bi_count_absent = bi_search_function( arr , normal_low , j - 1 , size , normal_count);
				int min_bi_count = bi_search_function( arr , normal_low , j - 1 , arr[0] , normal_count );
				int min_li_count = li_search_function( arr , normal_low , j - 1 , arr[0] , normal_count );
				int max_bi_count = bi_search_function( arr , normal_low , j - 1 , arr[0] , normal_count );
				int max_li_count = li_search_function( arr , normal_low , j - 1 , arr[0] , normal_count );
				int sum_bi = 0;
				int sum_li = 0;
				for( int k = 0 ; k < j ; k++){
					int aim = arr[k];
					count_in_bi = bi_search_function( arr , normal_low , j - 1 , aim , normal_count );
					count_in_li = li_search_function( arr , normal_low , j - 1 , aim , normal_count );
					sum_bi += count_in_bi;
					sum_li += count_in_li;
					if( count_in_bi < min_bi_count)
						min_bi_count = count_in_bi;
					if( count_in_bi > max_bi_count)
						max_bi_count = count_in_bi;
					if( count_in_li < min_li_count)
                        		        min_li_count = count_in_li;
                     			if( count_in_li > max_li_count)
                        	        	max_li_count = count_in_li;
				}
				printf("   %3d    %3d     %3d    %3d       %3d                        %3d         %3d         %3d        %3d\n", j , min_li_count , max_li_count , sum_li / j , li_count_absent , min_bi_count , max_bi_count,sum_bi / j , bi_count_absent );
			}
		}
	}
	return 0;
}

