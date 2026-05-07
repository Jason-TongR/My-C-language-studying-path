#include <stdio.h>
int main (){
	int x_treasure;
	int y_treasure;
	int x_user=0;
	int y_user=0;
	int a=0;
	char position;
	while(a <= 4){
		printf("| . | . | . | . | . |\n");
		a++;
	}
	printf("Enter the x coordinate of treasure: ");
	scanf(" %d",&x_treasure);
	printf("Enter the y coordinate of treasure: ");
	scanf(" %d",&y_treasure);
	do{
	printf("Enter a positon: ");
	scanf(" %c",&position);
	if((position == 'u')&&(y_user < 4))
		y_user = y_user + 1;
	if((position == 'd')&&(y_user > 0))
		y_user = y_user - 1;
	if((position == 'l')&&(x_user > 0))
		x_user = x_user - 1;
	if((position == 'r')&&(x_user < 4))
		x_user = x_user + 1;
	}
	while((x_user!=x_treasure)||(y_user!=y_treasure));
	return 0;
}
