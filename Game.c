// Game.c
// By Harry Wu
// Implements the function necessary for the game to run
// 30/5/19

// Note: the code orchestrating the running of the game, be it 
// runGame.c or testGame.c, is responsible for deciding whether
// START_SPINOFF, given by decideAction() or otherwise, will give 
// an IP license or a publication. These have OBTAIN_IP_PATENT and
// OBTAIN_PUBLICATION action codes, respectively. Hence the 
// orchestrating code would first check whether START_SPINOFF is a 
// legal move with isLegalAction() (ie. if there are sufficient
// resources) before deciding on an outcome, modifying the action
// to suit and then calling makeAction() with it.


// Do we need to #include these? The file worked fine without them.
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "Game.h"

#define NUM_DISCIPLINES 6

// Game newGame (int discipline[], int dice[]) {
// 	//actually modify shit in Game.c, yeah!!!
// }

struct player {
	//The number of students of each discipline the player has.
	//The numTHD value is completely irrelevant though.
	int resources[NUM_DISCIPLINES];


	//How many of each student the player can be expected to produce each turn
	//based on our probability estimates (e.g chance rolling a 7 is 16% = 0.16, etc.).
	//I'm not sure we need this but it would be useful for the AI.
	double produceResources[NUM_DISCIPLINES];
	//The number of other resources the player has.
	int numKPI;
	int numCampus;
	int numG08;
	int numIP;
	int numARC;
	int numPatent;
	int numPublication;
	int exchangeRate;
	//Note: integer is not enough info
};

//g->PlayerOne.resources[THD] += 1;

typedef struct _game {

	//Note: currentTurn starts off as -1
	int currentTurn;
	int currentScore;
	char whoseTurn;
	struct player playerOne;
	struct player playerTwo;
	struct player playerThree;


	// Edge edges[PATH_LIMIT];
	// Vertex vertices[100];
	// Hexagon hexagons[NUM_REGIONS];
	// int **lol; //Points to a pointer, I think
} game;
// Why does this throw an error? 
// redefinition of typedef game is a C11 feature


/* **** Functions which change the game aka SETTERS **** */
// make a new game, given the disciplines produced by each
// region, and the value on the dice discs in each region.
// note: each array must be NUM_REGIONS long
// eg if you are using my sample game struct above this function
// would need to set the field currentTurn to -1.  (because the turn
// number is -1 at the start of the game)
// the ordering of the regions is column by column left to right,
// going from the top of each column to the bottom before moving 
// to the next column to the right.

Game newGame (int discipline[], int dice[]);

// free all the memory malloced for the game
void disposeGame (Game g) {
	// Is double-check that this is how you do this?
	//free(g);
	//however the above line causes an error
	// which is implicit declaration of funtion free
}

// make the specified action for the current player and update the 
// game state accordingly.  
// The function may assume that the action requested is legal.
// START_SPINOFF is not a legal action here
void makeAction (Game g, action a) {
	//Will be second hardest function to write after isLegalAction
	//Does something for each action

	if (a.actionCode == PASS) {
		//do something
	} else if (a.actionCode == BUILD_CAMPUS) {
		//do something else
	} else if (a.actionCode == BUILD_GO8) {
		//do something else
	} //et cetera
}

// advance the game to the next turn, 
// assuming that the dice has just been rolled and produced diceScore
// the game starts in turn -1 (we call this state "Terra Nullis") and 
// moves to turn 0 as soon as the first dice is thrown. 
void throwDice (Game g, int diceScore);

/* **** Functions which GET data about the game aka GETTERS **** */

// what type of students are produced by the specified region?
// regionID is the index of the region in the newGame arrays (above) 
// see discipline codes above
int getDiscipline (Game g, int regionID);

// what dice value produces students in the specified region?
// 2..12
int getDiceValue (Game g, int regionID);

// which university currently has the prestige award for the most ARCs?
// this is NO_ONE until the first arc is purchased after the game 
// has started.  
int getMostARCs (Game g);

// which university currently has the prestige award for the most pubs?
// this is NO_ONE until the first publication is made.
int getMostPublications (Game g);

// return the current turn number of the game -1,0,1, ..
int getTurnNumber (Game g);

// return the player id of the player whose turn it is 
// the result of this function is NO_ONE during Terra Nullis
int getWhoseTurn (Game g);

// return the contents of the given vertex (ie campus code or 
// VACANT_VERTEX)
int getCampus(Game g, path pathToVertex);

// the contents of the given edge (ie ARC code or vacent ARC)
int getARC(Game g, path pathToEdge);

// returns TRUE if it is legal for the current
// player to make the specified action, FALSE otherwise.
//
// "legal" means everything is legal: 
//   * that the action code is a valid action code which is legal to 
//     be made at this time
//   * that any path is well formed and legal ie consisting only of 
//     the legal direction characters and of a legal length, 
//     and which does not leave the island into the sea at any stage.
//   * that disciplines mentioned in any retraining actions are valid 
//     discipline numbers, and that the university has sufficient
//     students of the correct type to perform the retraining
//
// eg when placing a campus consider such things as: 
//   * is the path a well formed legal path 
//   * does it lead to a vacent vertex?
//   * under the rules of the game are they allowed to place a 
//     campus at that vertex?  (eg is it adjacent to one of their ARCs?)
//   * does the player have the 4 specific students required to pay for 
//     that campus?
// It is not legal to make any action during Terra Nullis ie 
// before the game has started.
// It is not legal for a player to make the moves OBTAIN_PUBLICATION 
// or OBTAIN_IP_PATENT (they can make the move START_SPINOFF)
// you can assume that any pths passed in are NULL terminated strings.
int isLegalAction (Game g, action a) {
	//is going to be hardest function to write
	//checks if any given action is legal or not
	int isLegal = TRUE;
	if (a.actionCode == PASS) {
		//do nothing - of course you can pass
	} else if (a.actionCode == BUILD_CAMPUS) {
		//do something - checks path, resources etc.
	} else if (a.actionCode == BUILD_GO8) {
		//do something else
	} //et cetera


	//This is to ensure that we don't have many return statements, 
	//which is banned under the style guide.
	if (isLegal == TRUE) {
		return TRUE;
	} else {
		return FALSE;
	}
}

// --- get data about a specified player ---

// return the number of KPI points the specified player currently has
int getKPIpoints (Game g, int player) {
	int KPIpoints = 0;
	if (player == UNI_A) {
		KPIpoints = g->playerOne.numKPI;
	} else if (player == UNI_B) {
		KPIpoints = g->playerTwo.numKPI;
	} else if (player == UNI_C) {
		KPIpoints = g->playerThree.numKPI;
	}
	return KPIpoints;
}

// return the number of ARC grants the specified player currently has
int getARCs (Game g, int player) {
	int ARCs = 0;
	if (player == UNI_A) {
		ARCs = g->playerOne.numARC;
	} else if (player == UNI_B) {
		ARCs = g->playerTwo.numARC;
	} else if (player == UNI_C) {
		ARCs = g->playerThree.numARC;
	}
	return ARCs;
}
// return t"??"GO8s (Game g, int player);

// return the number of normal Campuses the specified player currently has
int getCampuses (Game g, int player) {
	int campuses = 0;
	if (player == UNI_A) {
		campuses = g->playerOne.numCampus;
	} else if (player == UNI_B) {
		campuses = g->playerTwo.numCampus;
	} else if (player == UNI_C) {
		campuses = g->playerThree.numCampus;
	}
	return campuses;
}

// return the number of IP Patents the specified player currently has
int getIPs (Game g, int player) {
	int IPs = 0;
	if (player == UNI_A) {
		IPs = g->playerOne.numIP;
	} else if (player == UNI_B) {
		IPs = g->playerTwo.numIP;
	} else if (player == UNI_C) {
		IPs = g->playerThree.numIP;
	}
	return IPs;
}

// return the number of Publications the specified player currently has
int getPublications (Game g, int player) {
	int publications = 0;
	if (player == UNI_A) {
		publications = g->playerOne.numPublication;
	} else if (player == UNI_B) {
		publications = g->playerTwo.numPublication;
	} else if (player == UNI_C) {
		publications = g->playerThree.numPublication;
	}
}

// return the number of students of the specified discipline type 
// the specified player currently has
int getStudents (Game g, int player, int discipline) {
	int students = 0;
	if (player == UNI_A) {
		students = g->playerOne.resources[discipline];
	} else if (player == UNI_B) {
		students = g->playerTwo.resources[discipline];
	} else if (player == UNI_C) {
		students = g->playerThree.resources[discipline];
	}
	return students;
}

// return how many students of discipline type disciplineFrom
// the specified player would need to retrain in order to get one 
// student of discipline type disciplineTo.  This will depend 
// on what retraining centers, if any, they have a campus at.
int getExchangeRate (Game g, int player, 
                     int disciplineFrom, int disciplineTo) {

}

