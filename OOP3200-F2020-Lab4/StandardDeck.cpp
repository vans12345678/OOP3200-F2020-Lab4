#include "StandardDeck.h"

// Default Constructor

StandardDeck::StandardDeck() : myRankIndex(1), mySuitIndex(1), myValue(1), myStandardCardPtr(0)
{
	//Initialize
	
}

StandardDeck::~StandardDeck() = default;

StandardDeck::StandardDeck(const StandardDeck& other_deck)
{
}

StandardDeck& StandardDeck::operator=(const StandardDeck& other_deck)
{
}
