/*
 *  Mr Pass.  Brain the size of a planet!
 *  By Harry Wu and Damien Lai
 *  3 June 2019
 *  Proundly Created by Richard Buckland
 *  Share Freely Creative Commons SA-BY-NC 3.0. 
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "Game.h"
#include "mechanicalTurk.h"

action decideAction (Game g) {


	action nextAction;
	nextAction.actionCode = START_SPINOFF;
	if (isLegalAction(g, nextAction) == TRUE) {
		//do nothing
	}
	else {
		nextAction.actionCode = PASS;
	}

	return nextAction;
}