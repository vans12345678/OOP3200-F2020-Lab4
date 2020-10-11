#include <ctime>
#include <iostream>
#include "StandardDeck.h"
#include "PlayingCard.h"

void Pause() {
	std::cout << "\nPress \'ENTER\' to continue..." << std::endl;
	std::cin.ignore();	fflush(stdin);
}
void OutputDeck(StandardDeck& deck);

int main()
{
	/*	Your main() function should demonstrate each of the features of the StandardDeck class*/
	srand(time(nullptr)); // seed the random number generator

	// create a deck
	StandardDeck deck = StandardDeck();
	
	// Show the deck object as initialized
	OutputDeck(deck);
	Pause();
	
	// Draw the next card and show it
	deck.DrawNextCard();
	OutputDeck(deck);
	// Draw a random card and show it    
	
	// Show the deck with the remaining cards

	// Shuffle the deck and show the result

	// Reset the deck and show the result
}


void OutputDeck(StandardDeck& deck)
{
	for (int i = 0; i < deck.GetDeck().size(); i++)
	{
		std::cout << std::string(deck.GetDeck()[i]) << std::endl;
	}
}
