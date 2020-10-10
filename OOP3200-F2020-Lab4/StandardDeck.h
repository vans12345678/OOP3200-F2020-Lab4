/** OOP3200. F2020. StandardDeck.h
 *
 *  In this lab you will create your own collection class called StandardDeck, which
 *	will 'contain' objects of the PlayingCard class.  The intent of the class is to
 *	represent a standard deck of 52 cards that might be useful in a card game type
 *	application.  
 *
 *	@author		Thom MacDonald
 *	@author		Tom Tsiliopoulos
 *	@version	2020.10
 *	@since		Jul 2018
 *	@see		Bronson, G. (2012). A First Book of C++ (4th ed.). Boston, MA: Course Technology.
*/

#pragma once
#ifndef __STANDARD_DECK__
#define __STANDARD_DECK__

#include "PlayingCard.h"

class StandardDeck
{
public:
	
	// Initialization:
	// 
	//Default
	StandardDeck(); //supposed to equal 0

	//Parameterized 
	                             
	// Rule of three:
	~StandardDeck();
	StandardDeck(const StandardDeck& other_deck);
	StandardDeck& operator=(const StandardDeck& other_deck);

	// Accessors:

	// Mutators:

private:
	
	int myRankIndex{}; // an int to represent the rank for standard deck {1 - 13}
	int mySuitIndex{}; // an int to represen
	int myValue;   // an int to represent the 'value' of the card for standard deck
	PlayingCard* myStandardCardPtr;

	static const int DEFAULT_VALU_WANTED = -999;

	// Private Methods - useful internallyt the suit for standard deck (0 - 3}
	int GetDefaultValue() const; // gets the default value for the rank

	//Sets or re-set the deck to 52 standard playing cards
	int Initialize()
	{
		//check if private member pointer is not equal to 0
		if(myStandardCardPtr != 0)
		{
			//Delete memory
		}

		StandardDeck vector = StandardDeck();
		
	}
};

#endif /* defined (__STANDARD_DECK__) */

