#include "Card.h"
#include "HandFrequency.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void populateDeck(vector<Card> &deck) {
	for(int s = SPADES; s <= HEARTS; s++) {
		for(int r = TWO; r <= ACE; r++ )
			deck.push_back(Card((Suit)s,(Rank)r));
	}
}

int main()
{
	vector<Card> deck;

	cout << "Generating Deck" << endl;
	populateDeck(deck);
	HandFrequency hf;

	while(!hf.allHandTypesOccurred()) {
		cout << "Shuffling Deck" << endl;
		random_shuffle(deck.begin(), deck.end());
		hf.drawAndAnalyzeHand(deck);
	}

	hf.printFrequencies(cout);

}