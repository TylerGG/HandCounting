#include "Card.h"
#include "HandFrequency.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <locale>
#include <mpi.h>
using namespace std;

/*
	main.cpp
	@Author : Tyler Garrow, Craig Treulieb
*/



void populateDeck(vector<Card> &deck) {
	for(int s = SPADES; s <= HEARTS; s++) {
		for(int r = TWO; r <= ACE; r++ )
			deck.push_back(Card((Suit)s,(Rank)r));
	}
}

int main(int argc, char* argv[])
{
	if( !MPI_Init(&argc, &argv) == MPI_SUCCESS )
		return EXIT_FAILURE;

	locale loc("");
	cout.imbue(loc);


	cout  << "HandFrequency : - This program will draw random hands of playing cards until one of each type is drawn then display the results" << endl;

	cout << "[[serial version]]" << endl;
	vector<Card> deck;
	populateDeck(deck);
	HandFrequency hf;
	srand(time(0));
	hf.startTiming();
	while(!hf.allHandTypesOccurred()) {
		random_shuffle(deck.begin(), deck.end());
		hf.drawAndAnalyzeHand(deck);
	}
	hf.stopTiming();
	hf.printFrequencies(cout);

	MPI_Finalize();
}