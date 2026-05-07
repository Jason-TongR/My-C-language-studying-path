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
					p1_turn = 0;
					printf("player1's score is %d",p1_score);
					choose_player = 2;
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
			if(p2_score > 70){
				dice = rand()%6 + 1;
				if(dice == 1){
					p2_turn = 0;
					printf("computer rolled '1',compurer's score is %d",p2_score);
					choose_player = 1;
				}
				else{
					p2_turn += dice;
				printf("Computer rolled %d | Turn total %d",dice,p2_turn);
				}
			}
			else{
				int hold_score;
				hold_score = 21 + (p1_score - p2_score)/8;
				if(p2_turn >= hold_score){
					p2_score += p2_turn;
					printf("computer holds,score is %d",p2_score);
					choose_player = 1;
					p2_turn = 0;
				}
				else{
					dice = rand()%6 + 1;
					if(dice == 1){
						p2_turn = 0;
						printf("computer rolled 1\n");
						printf("computer's score is %d",p2_score);
						choose_player = 1;
					}
					else
						p2_turn += dice;
					printf("computer rolled %d | Turn total %d",dice,p2_turn);
				}

			}
		}
	}
	printf("\n");
	if(p1_score >= 100)
		printf("player1 win %d points!",p1_score + p1_turn);
	if(p2_score + p2_turn >= 100)
		printf("Computer win %d points!",p2_score + p2_turn);
	return 0;
}
