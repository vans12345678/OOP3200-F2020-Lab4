#include <ctime>
#include <iostream>
#include "StandardDeck.h"
#include "PlayingCard.h"

void Pause() {
	std::cout << "\nPress \'ENTER\' to continue..." << std::endl;
	std::cin.ignore();	fflush(stdin);
}

int main()
{
	/*	Your main() function should demonstrate each of the features of the StandardDeck class*/
	srand(time(nullptr)); // seed the random number generator
	const int totalCards = 52;
	// create a deck
	StandardDeck deck = StandardDeck();

	for(int i = 0; i < totalCards; i++)
	{
		std::cout << std::string(deck.GetDeck()[i]) << std:: endl;
	}
	
	// Show the deck object as initialized
	Pause();
	
	// Draw the next card and show it

	// Draw a random card and show it
	
	// Show the deck with the remaining cards

	// Shuffle the deck and show the result

	// Reset the deck and show the result
}


