/** OOP3200. F2020. StandardDeck.h
 *
 *  In this lab you will create your own collection class called StandardDeck, which
 *	will 'contain' objects of the PlayingCard class.  The intent of the class is to
 *	represent a standard deck of 52 cards that might be useful in a card game type
 *	application.  
 *
 *	@author		Andre Agrippa
 *	@author		Najeebulla Husaini
 *	@version	2020.10
 *	@since		October 2020
 *	@see		Bronson, G. (2012). A First Book of C++ (4th ed.). Boston, MA: Course Technology.
*/

#pragma once
#ifndef __STANDARD_DECK__
#define __STANDARD_DECK__

#include <vector>

#include "PlayingCard.h"

class StandardDeck
{
public:
	
	// Initialization:

	//Default
	StandardDeck(); //supposed to equal 0

	// //Parameterized
	// StandardDeck(int myRankIndex, int mySuitIndex, int myValue, PlayingCard myStandardCardPtr);

	// Rule of three:
	~StandardDeck();
	StandardDeck(const StandardDeck& other_deck);
	StandardDeck& operator=(const StandardDeck& other_deck);
	
	// Accessors:
	std::vector<PlayingCard> GetDeck() const;
	PlayingCard GetCard() const;
	PlayingCard* GetPtr() const;
	PlayingCard DrawNextCard();
	PlayingCard DrawRandomCard();
	int CardsRemaining() const;
	
	//Mutators
	void SetCard(PlayingCard other_card);
	void SetDeck(std::vector<PlayingCard> myStandardDeck);
	void SetPointer(PlayingCard* standardPtr);
	void Shuffle();
	

private:
	
   
	PlayingCard myStandardCard;
	std::vector<PlayingCard> myStandardDeck;
	PlayingCard* myStandardPtr;
	
	// Private Methods - useful internally the suit for standard deck (0 - 3}

	//Sets or re-set the deck to 52 standard playing cards
	virtual void Initialize();
	
};

#endif /* defined (__STANDARD_DECK__) */

