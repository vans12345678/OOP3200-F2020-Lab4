#include "StandardDeck.h"

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
}

//Overload assignment operator
StandardDeck& StandardDeck::operator=(const StandardDeck & other_deck)
{
	SetCard(other_deck.myStandardCard);
	return (*this);	
}

//Returns the standard deck of cards
std::vector<PlayingCard> StandardDeck::GetDeck() const
{
	return myStandardDeck;
}
//Returns PlayingCard object at [0], decreases total cards by 1 after called
PlayingCard StandardDeck::DrawNextCard()
{
	PlayingCard card = myStandardDeck[0];
	
	//For each playing card in deck
	for (int i = 0; i < myStandardDeck.size() -1; i++)
	{
		myStandardDeck[i]=myStandardDeck[i+1];
	}
	//Reduces vector size by 1
	myStandardDeck.pop_back();
	
	return card;
}

//Sets a card in the standard deck
void StandardDeck::SetCard(PlayingCard other_card)
{
	myStandardCard = other_card;
}

//Resets the deck to default
void StandardDeck::ResetDeck(StandardDeck& deck)
{
	Initialize();
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

