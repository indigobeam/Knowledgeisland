#include <stdio.h>
#include <stdlib.h>

int rollDice(void);

int main () {
    Game g = newGame (disciplines, dice);
	while (gameNotOver){
    int diceValue = 0;
	diceValue = rollDice() + rollDice();
  
    //human or mechanicalTurk(AI) decide what they want to do     
    //loop until player action is PASS or player wins     
    while (turn is not over and game not over) { 
		scanf("%d",&move);
        move = decideAction(g); 
        assert(isLegalAction(g, move)); //assert that action is legal 

        if (move.actionCode == START_SPINOFF) { 
				if (rollDice()/2 <= 2) {
					move.actionCode = OBTAIN_PUBLICATION;
				} else {
					move.actionCode = OBTAIN_IP_PATENT;
}

        makeAction(g, move);
     } 
} 


    return EXIT_SUCCESS;
	
}


int rollDice(){
    int value;
    srand ( time(NULL) );
    value = 1+ rand() % 6 ;
	delay();

    return value;
}

 
