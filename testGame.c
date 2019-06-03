// testGame.c
// By Harry Wu, 22/May/2019
// As part of Team Rho's Knowledge Island
// Tests a game to ensure Game.c functions correctly

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "Game.h"

// this is just a random setup that we're going to use to test with
#define DEFAULT_DISCIPLINES {STUDENT_BQN, STUDENT_MMONEY, STUDENT_MJ, \
                STUDENT_MMONEY, STUDENT_MJ, STUDENT_BPS, STUDENT_MTV, \
                STUDENT_MTV, STUDENT_BPS,STUDENT_MTV, STUDENT_BQN, \
                STUDENT_MJ, STUDENT_BQN, STUDENT_THD, STUDENT_MJ, \
                STUDENT_MMONEY, STUDENT_MTV, STUDENT_BQN, STUDENT_BPS}
#define DEFAULT_DICE {9,10,8,12,6,5,3,11,3,11,4,6,4,7,9,2,8,10,5}



int main(int argc, char *argv[]) {

	//Game testGame = newGame(DEFAULT_DISCIPLINES, DEFAULT_DICE);
	int disciplines[] = DEFAULT_DISCIPLINES;
    int dice[] = DEFAULT_DICE;
    Game g = newGame (disciplines, dice);

    /*** START TESTING TO ENSURE GAME ISN'T RIGGED ***/
    printf("Begin testing\n");
    
    //assert everthing is Gucci at the start of the game

    //this assert asserts that "getKPIpoints(g, UNI_A)"
    // returns 20. This function is declared/prototyped
    //in Game.h. If KPIpoints DOES NOT return 20, then
    // there is a big problem because everyone should
    // start off with 20 points, which is why we're testing
    // it. Similar asserts are repeated.

    //Asserts that everyone start off with 20 KPI points because
    //Each player has 2 campuses that are worth 10 points each
    assert(getKPIpoints(g, UNI_A) == 20);
    assert(getKPIpoints(g, UNI_B) == 20);
    assert(getKPIpoints(g, UNI_C) == 20);

    //asserts that no-one has any arcs/paths at the start of the game
    assert(getARCs(g, UNI_A) == 0);
    assert(getARCs(g, UNI_B) == 0);
    assert(getARCs(g, UNI_C) == 0);

    // Everyone starts off with 2 campuses
    assert(getCampuses(g, UNI_A) == 2);
    assert(getCampuses(g, UNI_B) == 2);
    assert(getCampuses(g, UNI_C) == 2);

    // Everyone starts with no IPs
    assert(getIPs(g, UNI_A) == 0);
    assert(getIPs(g, UNI_B) == 0);
    assert(getIPs(g, UNI_C) == 0);

    // Everyone starts with no Publications
    assert(getPublications(g, UNI_A) == 0);
    assert(getPublications(g, UNI_B) == 0);
    assert(getPublications(g, UNI_C) == 0);

    // everyone starts off with 3 x BPS, 3 x B?, 1 x MTV, 1 x MJ,
    // 1 x M$, and no ThD students

    assert(getStudents(g, UNI_A, STUDENT_THD) == 0);
    assert(getStudents(g, UNI_A, STUDENT_BPS) == 3);
    assert(getStudents(g, UNI_A, STUDENT_BQN) == 3);
    assert(getStudents(g, UNI_A, STUDENT_MJ) == 1);
    assert(getStudents(g, UNI_A, STUDENT_MTV) == 1);
    assert(getStudents(g, UNI_A, STUDENT_MMONEY) == 1);

    assert(getStudents(g, UNI_B, STUDENT_THD) == 0);
    assert(getStudents(g, UNI_B, STUDENT_BPS) == 3);
    assert(getStudents(g, UNI_B, STUDENT_BQN) == 3);
    assert(getStudents(g, UNI_B, STUDENT_MJ) == 1);
    assert(getStudents(g, UNI_B, STUDENT_MTV) == 1);
    assert(getStudents(g, UNI_B, STUDENT_MMONEY) == 1);

    assert(getStudents(g, UNI_C, STUDENT_THD) == 0);
    assert(getStudents(g, UNI_C, STUDENT_BPS) == 3);
    assert(getStudents(g, UNI_C, STUDENT_BQN) == 3);
    assert(getStudents(g, UNI_C, STUDENT_MJ) == 1);
    assert(getStudents(g, UNI_C, STUDENT_MTV) == 1);
    assert(getStudents(g, UNI_C, STUDENT_MMONEY) == 1);

    // This checks that the exchange rates, for all players, for all
    // possible disciplines, always equals three at the start.
    int playerID = UNI_A;
    int disciplineFrom = STUDENT_THD;
    int disciplineTo = STUDENT_THD;
    while (playerID <= NUM_UNIS) {
    	while (disciplineFrom <= STUDENT_MMONEY) {
    		while (disciplineTo <= STUDENT_MMONEY) {
    			assert(getExchangeRate(g, playerID, disciplineFrom, disciplineTo) == 3);
    			disciplineTo += 1;
    		}
    		disciplineFrom += 1;
    	}
    	playerID += 1;
    }
    

    //asserts the different paths all lead to 
    //the same Campus A
    assert(getCampus(g, "") == CAMPUS_A);
    assert(getCampus(g, "RB") == CAMPUS_A);
    assert(getCampus(g, "LB") == CAMPUS_A);
    assert(getCampus(g, "RLLLLL") == CAMPUS_A);
    assert(getCampus(g, "RLLLLLBB") == CAMPUS_A);
    assert(getCampus(g, "RBRRRRRR") == CAMPUS_A);

    //asserts for each of the other 5 campuses
	assert(getCampus(g, "RRLRL") == CAMPUS_B);
    assert(getCampus(g, "LRLRL") == CAMPUS_C);

    //The 3 furthest campuses
    assert(getCampus(g, "RLRLRLRLRLL") == CAMPUS_A);
    assert(getCampus(g, "LRLRLLRLRL") == CAMPUS_B);
    assert(getCampus(g, "RRLRLRRLRL") == CAMPUS_C);

    assert(getARC(g, "RRLRL") == NO_ONE);



    //assert like 200 more getCampuses and getArcs
    // using while loops which I don't know how to do
    
    assert(getMostARCs(g) == NO_ONE);
    assert(getMostPublications(g) == NO_ONE);
    //Right right?
    assert(getTurnNumber(g) == -1);

    //Whose turn does it start at? UNI_A or random or what?
    //assert(getWhoseTurn(g) == "someone?");

    // this checks that all the disciplines line up with 
    // the dice values
    int i = 0;
    while (i < NUM_REGIONS) {
        assert(getDiscipline(g, i) == disciplines[i]);
        assert(getDiceValue(g, i) == dice[i]);
        i++;
    }
    printf("Setup is Gucci\n");

    /***** STARTS TO MAKE MOVES AND TEST THOSE MOVES *****/

    printf("Making moves for first player\n");
    //Who is the first player though?

    // Note: I'm made the design choice to create multiple action
    // structs for specific actions instead of making only one action
    // struct and reassigning its actionCode multiple times.

    // how does the action struct know which player is using it?
    // Anyways, this sets up an actions struct called 'pass'
    // It has actionCode 0 and just passes.
    action pass;
    pass.actionCode = PASS;
    assert(isLegalAction(g, pass) == TRUE);

    action retrain;
	retrain.actionCode = RETRAIN_STUDENTS;
	retrain.disciplineFrom = STUDENT_MJ;
	retrain.disciplineTo = STUDENT_MMONEY;
	assert(isLegalAction(g, retrain) == TRUE);
	makeAction(g,retrain);

	action arc;
	arc.actionCode = OBTAIN_ARC;
	strcpy(arc.destination, "R"); //be careful about overflows
	assert(isLegalAction(g, arc) == TRUE);
	makeAction(g,arc);

	action go8;
	go8.actionCode = BUILD_GO8;
	strcpy(go8.destination, ""); //be careful about overflows
	assert(isLegalAction(g, go8) == TRUE);
	makeAction(g,go8);

    //I DO NOT KNOW IF THIS TEST IS VALID YET DO NOT USE IT
    // THIS IS JUST AN EXAMPLE
    // below line throws an error because array path
    // is somehow not assignable
    action buildCampus;
    buildCampus.actionCode = BUILD_CAMPUS;
    //buildCampus.destination = "RRBR";
    assert(isLegalAction(g, buildCampus) == FALSE);
    //makeAction(g, pass);

    //NB: isLegalAction function is 
    //int isLegalAction (Game g, action a);


    /*#define PASS 0
#define BUILD_CAMPUS 1
#define BUILD_GO8 2
#define OBTAIN_ARC 3
#define START_SPINOFF 4
#define OBTAIN_PUBLICATION 5
#define OBTAIN_IP_PATENT 6
#define RETRAIN_STUDENTS 7*/
    // Now assert that actions produce the correct outcome

    //btw this is the action struct in Game.h (commented below)
/*    typedef struct _action {
  	int actionCode;  // see #defines above
  	path destination; // if the action operates on a vertex or ARC this
                     // specifies *which* vertex or path.  unused 
                     // otherwise
   	int disciplineFrom;  // used for the retrain students action
  	int disciplineTo;    // used for the retrain students action
	} action;*/

    throwDice(g, 9); // 9 is an arbitrary number
    assert(getTurnNumber(g) == 0);

	// clean up: keep your memory beautiful
	disposeGame(g);
	//hmmmm... do we need to test disposeGame? And how?

	printf("All tests passed! Woohoo!\n");
	printf("You are awesome!\n");

	return EXIT_SUCCESS;
}