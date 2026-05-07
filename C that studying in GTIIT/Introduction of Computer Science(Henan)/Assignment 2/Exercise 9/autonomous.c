#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define range 10000
int main(){
	int choose_player;
	int p1_score = 0;
	int p2_score = 0;
	int p1_turn = 0;
	int p2_turn = 0;
	int dice;
	int exper_times;
	int p1_win = 0;
	int p2_win = 0;
	srand(time(NULL));
	printf("please enter the experience times your wanto to test: \n");
	scanf("%d",&exper_times);
	for(int i = 0; i < exper_times; i++){
	p1_score = 0;
       	p1_turn = 0;
	p2_score = 0;
       	p2_turn = 0;
	choose_player = rand()%2 + 1;
	while((p1_score + p1_turn < 100) && (p2_score + p2_turn < 100)){
		if(choose_player == 1){
			printf("\n");
			if(p1_turn < 25){
				dice = rand()%6 + 1;
				if(dice == 1){
					p1_turn = 0;
					printf("computer1 rolled '1', score is %d",p1_score);
					choose_player = 2;
				}
				else
					p1_turn += dice;
				printf("computer1 rolled: %d | Turn total: %d",dice,p1_turn);
			}
			else{
			p1_score += p1_turn;
			printf("computer1's score: %d",p1_score);
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
					printf("computer2 rolled '1',computer2's score is %d",p2_score);
					choose_player = 1;
				}
				else{
					p2_turn += dice;
				printf("Computer2 rolled %d | Turn total %d",dice,p2_turn);
				}
			}
			else{
				int hold_score;
				hold_score = 21 + (p1_score - p2_score)/8;
				if(p2_turn >= hold_score){
					p2_score += p2_turn; 
					printf("computer2 holds,score is %d",p2_score);
				choose_player = 1;
				p2_turn = 0;
				}
				else{
					dice = rand()%6 + 1;
					if(dice == 1){
						p2_turn = 0;
						printf("computer2 rolled 1\n");
						printf("computer2's score is %d",p2_score);
						choose_player = 1;
					}
					else
						p2_turn += dice;
					printf("computer2 rolled %d | Turn total %d",dice,p2_turn);
				}

			}
		}
	}
	printf("\n");
	if(p1_score + p1_turn >= 100){
		printf("computer1 win %d points!",p1_score + p1_turn);
		p1_win++;
	}
	if(p2_score + p2_turn >= 100){
		printf("Computer2 win %d points!",p2_score + p2_turn);
		p2_win++;
	}
	}
	printf("\n");
	printf("computer1 win %d,computer2 win %d",100*p1_win/(p1_win + p2_win),100*p2_win/(p1_win + p2_win));
	return 0;
}
