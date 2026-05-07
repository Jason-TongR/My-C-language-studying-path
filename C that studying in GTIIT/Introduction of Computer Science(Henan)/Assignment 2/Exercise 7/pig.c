#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	int choose_player;
	int p1_score = 0;
	int p2_score = 0;
	int p1_turn = 0;
	int p2_turn = 0;
	int dice;
	char choice;
	srand(time(NULL));
	choose_player = rand()%2 + 1;
	while((p1_score + p1_turn < 100) && (p2_score + p2_turn < 100)){
		if(choose_player == 1){
			printf("\n");
			printf("player1 ,Roll(r) or hold(h)?\n");
			scanf(" %c",&choice);
			if(choice == 'r'){
				dice = rand()%6 + 1;
				if(dice == 1){
					choose_player = 2;
					p1_turn = 0;
					printf("player1's score is %d",p1_score);
				}	
				else
					p1_turn += dice;
				printf("you rolled: %d | Turn total: %d",dice,p1_turn);
			}
			else{
			p1_score += p1_turn;
			printf("player1's score: %d",p1_score);
			choose_player = 2;
			p1_turn = 0;
			}
		}
		else{
			printf("\n");
			printf("player2,Roll(r) or Hold(h)?\n");
			scanf(" %c",&choice);
			if(choice == 'r'){
				dice = rand()%6 + 1;
				if(dice == 1){
					choose_player = 1;
					p2_turn = 0;
					printf("player2's score is %d",p2_score);
				}
				else
					p2_turn += dice;
				printf("You rolled: %d | Turn total: %d",dice,p2_turn);
			}
			else{
			p2_score += p2_turn;
			printf("player2's score: %d",p2_score);
			choose_player = 1;
			p2_turn = 0;
			}
		}
	}
	if(p1_score + p1_turn >= 100)
		printf("player1 win %d points!",p1_score + p1_turn);
	if(p2_score + p2_turn >= 100)
		printf("player2 win %d points!",p2_score + p2_turn);
	return 0;
}
