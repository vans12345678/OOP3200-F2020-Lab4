#include "StandardDeck.h"

// Default Constructor
StandardDeck::StandardDeck() :myStandardCard(PlayingCard())
{
	myStandardPtr = 0;
	StandardDeck::Initialize();
}

//Deconstructor
StandardDeck::~StandardDeck() = default;

//Returns 
std::vector<PlayingCard> StandardDeck::GetDeck() const
{
	return myStandardDeck;
}

void StandardDeck::Initialize()
{
	
	//check if private member pointer is not equal to 0
	if (myStandardPtr != 0)
	{
		//Delete memory
		delete myStandardPtr;
	}

	myStandardPtr = static_cast<int*>(malloc(sizeof(int) * 52));

	//Loop to set each of the cards in the deck in a sensible order

	for (int j = 1; j <= PlayingCard::RANKS; j++)
	{
		for(int i = 0; i < PlayingCard::SUITS; i ++)
		{
			PlayingCard card = PlayingCard(j, i, -999, true);
			myStandardDeck.push_back(card);		
		}
		
	}

}

