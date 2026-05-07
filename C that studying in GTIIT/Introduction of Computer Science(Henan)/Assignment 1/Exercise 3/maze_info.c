#include <stdio.h>
int main (){
	int x_treasure;
	int y_treasure;
	int x_user=0;
	int y_user=0;
	int a=0;
	char position;
	int step=0;
	int beyond=0;
	while(a <= 4){
		printf("| . | . | . | . | . |\n");
		a++;
	}
	do{
		printf("Enter the x coordinate of treasure: ");
		scanf(" %d",&x_treasure);
	}
	while((x_treasure < 0)||(x_treasure > 4));
	do{
		printf("Enter the y coordinate of treasure: ");
		scanf(" %d",&y_treasure);
	}
	while((y_treasure < 0)||(y_treasure > 4));
	do{
		printf("Enter a positon: ");
		scanf(" %c",&position);
	if((position != 'u'&&(position) != 'd'&&(position) != 'l'&&(position) != 'r')  ||  (((position == 'u')&&(y_user == 4))||((position == 'd')&&(y_user == 0))||((position =='l')&&(x_user == 0)) || ((position == 'r')&&(x_user ==4))))
	{	if( (((position == 'u')&&(y_user == 4))||((position == 'd')&&(y_user == 0))||((position == 'l')&&(x_user == 0))||((position == 'r')&&(x_user == 4))))
		{
			printf("Please enter a correct position\n");
			beyond++;
		}	
		else
			printf("Please enter a correct position\n");
	}
	else{
		if((position == 'u')&&(y_user < 4)){
			y_user = y_user + 1;
			step++;
		}
		if((position == 'd')&&(y_user > 0)){
			y_user = y_user - 1;
			step++;
		}
		if((position == 'l')&&(x_user > 0)){
			x_user = x_user - 1;
			step++;
		}
		if((position == 'r')&&(x_user < 4)){
			x_user = x_user + 1;
			step++;
		}
		}
	}
	while((x_user!=x_treasure)||(y_user!=y_treasure));
	printf("You have tried %d times and beyond the grid %d times",step,beyond);
	return 0;
}
