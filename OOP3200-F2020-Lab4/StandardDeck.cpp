/*
 * Filename: StandardDeck.cpp
 * Name: Andre Agrippa, Najeebulla Hussaini
 * Date: 10/09/2020
 */
#include "StandardDeck.h"



#include <ctime>
#include <iostream>
#include <ostream>

// Default Constructor
StandardDeck::StandardDeck() :myStandardCard(PlayingCard())
{
	myStandardPtr = 0;
	StandardDeck::Initialize();
}

//Destructor
StandardDeck::~StandardDeck() = default;

//Copy constructor
StandardDeck::StandardDeck(const StandardDeck& other_deck)
{
	SetCard(other_deck.myStandardCard);
	SetDeck(other_deck.myStandardDeck);
	SetPointer(other_deck.myStandardPtr);
}

//Overload assignment operator
StandardDeck& StandardDeck::operator=(const StandardDeck & other_deck)
{
	SetCard(other_deck.myStandardCard);
	SetDeck(other_deck.myStandardDeck);
	SetPointer(other_deck.myStandardPtr);
	return (*this);
}

//Returns the standard deck of cards
std::vector<PlayingCard> StandardDeck::GetDeck() const
{
	return myStandardDeck;
}
// return the standard card 
PlayingCard StandardDeck::GetCard() const
{
	return myStandardCard;
}
//return pointer 
PlayingCard* StandardDeck::GetPtr() const
{
	return myStandardPtr;
}
//Returns PlayingCard object at [0], decreases total cards by 1 after called
PlayingCard StandardDeck::DrawNextCard()
{	
	//For each playing card in deck
	for (int i = 0; i < myStandardDeck.size() -1; i++)
	{
		myStandardDeck[i]=myStandardDeck[i+1];
	}

	PlayingCard card = myStandardDeck[0];
	
	//Reduces vector size by 1
	myStandardDeck.pop_back();
	
	return card;
}
//Draws a random card in the deck
PlayingCard StandardDeck::DrawRandomCard()
{
	int randNum = 1 + (rand() % CardsRemaining());
	PlayingCard randCard = myStandardDeck[randNum];

	//For each playing card in deck
	for (int i = randNum; i < myStandardDeck.size() -1; i++)
	{
		myStandardDeck[i] = myStandardDeck[i + 1];
	}
	//Reduces vector size by 1
	myStandardDeck.pop_back();
	
	return randCard;
}

//Returns the number of cards remaining
int StandardDeck::CardsRemaining() const
{
	int cards = myStandardDeck.size();
	return cards;
}

//Sets a card in the standard deck
void StandardDeck::SetCard(PlayingCard other_card)
{
	myStandardCard = other_card;
}

//Set deck
void StandardDeck::SetDeck(std::vector<PlayingCard> other_deck)
{
	myStandardDeck = other_deck;
}

//Set pointer 
void StandardDeck::SetPointer(PlayingCard* standardPtr)
{
	myStandardPtr = standardPtr;
}

void StandardDeck::Shuffle()
{
	// Initialize seed randomly 
	srand(time(0));
	for (int i = 0; i < CardsRemaining(); i++)
	{
		// Random for remaining positions. 
		int r = i + (rand() % (CardsRemaining() - i));
		std::swap(myStandardDeck[i], myStandardDeck[r]);
	}
}

//Initializes to default
void StandardDeck::Initialize()
{
	
	//check if private member pointer is not equal to 0
	if (myStandardPtr != 0)
	{
		//Delete memory
		delete myStandardPtr;
	}

	myStandardPtr = static_cast<PlayingCard*>(malloc(sizeof(PlayingCard) * 52));

	//Loop to set each of the cards in the deck in a sensible order
	for (int j = 1; j <= PlayingCard::RANKS; j++)
	{
		for(int i = 0; i < PlayingCard::SUITS; i ++)
		{
			PlayingCard card = PlayingCard(j, i, -999, true);
			myStandardDeck.push_back(card);
			myStandardPtr = &card;
		}	
	}
}


