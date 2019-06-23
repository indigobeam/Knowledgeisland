#include <stdio.h>
#include <stdlib.h>

int rollDice(void);
void printStats (void);
void decideAction(void);

int main () {
	int gameNotOver = 0;
	
    Game g = newGame (disciplines, dice);
	while (gameNotOver == 0) {
    int diceValue = 0;
	int move = 0;
	diceValue = rollDice() + rollDice();
  
    //human or mechanicalTurk(AI) decide what they want to do
    //loop until player action is PASS or player wins
		printf("current player is %d, please enter an action code\n", whoseTurn);
	
	
	//prints stats for the game
		printStats();
		decideAction(move);
        assert(isLegalAction(g, move)); //assert that action is legal


        if (move.actionCode == START_SPINOFF) { //DONE
		//determines if the spinoff will be ip patient or a publication
				if (rollDice()/2 <= 2) {
					move.actionCode = OBTAIN_PUBLICATION;
				} else {
					move.actionCode = OBTAIN_IP_PATENT; 
}

        makeAction(g, move);
     } 
	 if (getKPIpoints(g, player) >= 120){ //DONE
		 //checks if the game has been won yet
		 printf("game over. Player %1 one", currentPlayer);
		 //makes the game end
		 gameNotOver++;
	 } else if (whoseTurn != 3){
		 //if it has not been one it cycles the turn
		 whoseTurn++;
	 } else {
		 whoseTurn = 1;
	 } 
} 
    return EXIT_SUCCESS;
}


int rollDice(void){ //DONE
    int value;
    srand ( time(NULL) );
    value = 1+ rand() % 6 ;
	delay();

    return value;
}
void decideAction(void){ //DONE
	scanf("%d",&move);
}
void printStats(void){ //DONE
printf("| UNI | ThD | BPS | B?  | MJ  | MTV | M$  | KPI |\n");
		int counter = 0;
		printf ("|UNI_A|")
		while (counter <=5){
		printf(" %3d |", g->playerOne.resources[counter]);
		counter++;
		}
		printf(" %3d |",g->playerOne.numKPI);
		printf ("|UNI_B|")
		counter = 0;
		while (counter <=5){
		printf(" %3d |", g->playerOne.resources[counter]);
		counter++;
		}
		printf(" %3d |",g->playerTwo.numKPI);
		printf ("|UNI_B|")
		counter = 0;
		while (counter <=5){
		printf(" %3d |", g->playerOne.resources[counter]);
		counter++;
		}
		printf(" %3d |",g->playerThree.numKPI);
        
}
	
