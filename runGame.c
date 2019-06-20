#include <stdio.h>
#include <stdlib.h>

int rollDice(void);

int main () {
    Game g = newGame (disciplines, dice);
	while (gameNotOver){
    srand ( time(NULL) );
    int diceValue = 0;
	diceValue = rollDice() + rollDice();
    //printf("%d this is in main\n", diceValue);
	//test for if function was being called correctly   
    
    action move; //human or mechanicalTurk(AI) decide what they want to do     
    //loop until player action is PASS or player wins     
    while (turn is not over and game not over) { 
		scanf("%d",&move);
        move = decideAction(g); 
        //assert that action is legal 
        if (move.actionCode == START_SPINOFF) { 
             if ( rand() % 3 + 1 = 3){
					action
        }
        makeAction(g, move);
     } 
} 


    return EXIT_SUCCESS;
	
}


int rollDice(){
    int value;
    
    value = 1+ rand() % 6 ;
    //printf ("%d this is in rollDice\n", val);
    //test for if function was being called correctly

    return value;
}

 
