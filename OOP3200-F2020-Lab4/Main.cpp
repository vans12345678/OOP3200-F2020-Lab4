#include <ctime>
#include <iostream>
#include "StandardDeck.h"
#include "PlayingCard.h"

void Pause() {
	std::cout << "\nPress \'ENTER\' to continue..." << std::endl;
	std::cin.ignore();	fflush(stdin);
}
void OutputDeck(StandardDeck& deck);
void ResetDeck(StandardDeck& deck);

int main()
{
    /*    Your main() function should demonstrate each of the features of the StandardDeck class*/
    srand(time(nullptr)); // seed the random number generator

    // create a deck
    StandardDeck deck = StandardDeck();
    // Show the deck object as initialized
    std::cout << "\nThe Standard Deck is: \n";
    OutputDeck(deck);
    Pause();
    // Draw the next card and show it
    std::cout << "\nThe next card drawn was: \n";
    std::cout << std::string(deck.DrawNextCard()) << std::endl;
    // Draw a random card and show it
    std::cout << "\nThe random card drawn was: \n";
    std::cout << std::string(deck.DrawRandomCard()) << std::endl;
    Pause();
    // Show the deck with the remaining cards
    std::cout << "\nThe remaining cards in the Deck are: \n";
    OutputDeck(deck);
    Pause();
    // Shuffle the deck and show the result
    std::cout << "The remaining cards in the Deck were shuffled: \n\n";
    deck.Shuffle();
    OutputDeck(deck);
    Pause();
    // Reset the deck and show the result
    std::cout << "The Deck has been reset: \n\n";
    ResetDeck(deck);
    OutputDeck(deck);
}


void OutputDeck(StandardDeck& deck)
{
	for (int i = 0; i < deck.GetDeck().size(); i++)
	{
		std::cout << std::string(deck.GetDeck()[i]) << std::endl;
	}
}
void ResetDeck(StandardDeck& deck)
{
    StandardDeck original = StandardDeck();

    deck = original;
}

