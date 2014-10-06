#include "Card.h"
#include "HandFrequency.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <locale>
#include <mpi.h>

/*
	main.cpp
	@Auther : Tyler Garrow, Craig Treuleib
*/

using namespace std;

const int MAX_MSG_SIZE = 10;
const int TAG_DATA = 0, TAG_QUIT = 1;


//*****************************************************************
//Hand Evaluations
bool checkForFourOfAKind(std::vector<Card> hand) {

	return(hand[0].getRank() == hand[3].getRank() || hand[1].getRank() == hand[4].getRank());
}
bool checkForFullHouse(std::vector<Card> hand) {

	return(hand[0].getRank() == hand[1].getRank() && hand[3].getRank() == hand[4].getRank() && (hand[2].getRank() == hand[0].getRank() || hand[2].getRank() == hand[4].getRank()));
}
bool checkForFlush(std::vector<Card> hand) {
	
	return(hand[0].getSuit() == hand[1].getSuit() && hand[1].getSuit() == hand[2].getSuit() && hand[2].getSuit() == hand[3].getSuit() && hand[3].getSuit() == hand[4].getSuit());
}
bool checkForStraight(std::vector<Card> hand) {
	
	return((hand[0].getRank() + 1 == hand[1].getRank() && hand[1].getRank() + 1 == hand[2].getRank() && hand[2].getRank() + 1 == hand[3].getRank() && hand[3].getRank() + 1 == hand[4].getRank()) || (hand[0].getRank() == 0 && hand[1].getRank() == 1 && hand[2].getRank() == 2 && hand[3].getRank() == 3 && hand[4].getRank() == 12 ));
}
bool checkForThreeOfAKind(std::vector<Card> hand) {
	
	return((hand[0].getRank() == hand[1].getRank() && hand[0].getRank() == hand[2].getRank()) || (hand[1].getRank() == hand[2].getRank() && hand[1].getRank() == hand[3].getRank()) || (hand[2].getRank() == hand[3].getRank() && hand[2].getRank() == hand[4].getRank()));
}
bool checkForTwoPair(std::vector<Card> hand) {

	return((hand[0].getRank() == hand[1].getRank() && ((hand[2].getRank() == hand[3].getRank()) || (hand[3].getRank() == hand[4].getRank()))) || (hand[1].getRank()==hand[2].getRank() && hand[3].getRank()==hand[4].getRank()));
}
bool checkForOnePair(std::vector<Card> hand) {
	
	return (hand[0].getRank() == hand[1].getRank() || hand[1].getRank() == hand[2].getRank() || hand[2].getRank() == hand[3].getRank() || hand[3].getRank() == hand[4].getRank());
}
//*****************************************************************************

bool operator <(Card lhs, Card rhs){
	return lhs.getRank() < rhs.getRank();
}


int drawAndAnalyzeHand(std::vector<Card> &deck) {

	
	std::vector<Card> hand;
	hand.push_back(deck[0]);
	hand.push_back(deck[1]);
	hand.push_back(deck[2]);
	hand.push_back(deck[3]);
	hand.push_back(deck[4]);
	std::sort(hand.begin(), hand.end());
	bool isFlush = checkForFlush(hand);
	bool isStraight = checkForStraight(hand);
	if(isFlush && isStraight)
	{
		if(hand[0].getRank() == 8)
			return 0;
		else
			return 1;
	} else if(isFlush) {
		return 4;
	} else if(isStraight) {
		return 5;
	} else {
		if(checkForFourOfAKind(hand))
			return 2;
		else if(checkForFullHouse(hand))
			return 3;
		else if(checkForThreeOfAKind(hand))
			return 6;
		else if(checkForTwoPair(hand))
			return 7;
		else if(checkForOnePair(hand))
			return 8;
		else
			return 9;
	}
}

void populateDeck(vector<Card> &deck) {
	for(int s = SPADES; s <= HEARTS; s++) {
		for(int r = TWO; r <= ACE; r++ )
			deck.push_back(Card((Suit)s,(Rank)r));
	}
}

void terminateWorkers(int numProcs) {
	int msgBuff = 0;
	for (int p = 1; p < numProcs; ++p)
		MPI_Send(&msgBuff, 1, MPI_INT, p, TAG_QUIT, MPI_COMM_WORLD);
}

void recvFromWorkers(int numProcs, HandFrequency &hf) {
	int msgBuff[10];
	MPI_Status status;
	for (int p = 1; p < numProcs; ++p) {
		MPI_Recv(&msgBuff, 10, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
		hf.addResults(msgBuff);
	}
}

void checkForNewHands(HandFrequency &hf) {

	static int msgBuff, recvFlag;
	MPI_Status status;
	
	//check for message
	MPI_Iprobe(MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &recvFlag, &status);

	if (recvFlag)
	{
		MPI_Recv(&msgBuff, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
		if(status.MPI_TAG == TAG_DATA)
			hf.foundHand(msgBuff);
	}
}

void processMaster(int numProcs) {
	locale loc("");
	cout.imbue(loc);

	
	cout  << "HandFrequency : - This program will draw random hands of playing cards until one of each type is drawn then display the results" << endl;

	cout << "[[Parallel version]]" << endl;
	int activeCount = numProcs - 1;
	int handFound;
	int hands[10] = {0};

	vector<Card> deck;
	populateDeck(deck);
	HandFrequency hf;
	srand(time(0));
	hf.startTiming();
	while(!hf.allHandTypesOccurred()) {
		random_shuffle(deck.begin(), deck.end());
		handFound = drawAndAnalyzeHand(deck);
		hands[handFound]++;
		hf.foundHand(handFound);
		checkForNewHands(hf);
	}
	terminateWorkers(numProcs);
	recvFromWorkers(numProcs, hf);
	hf.addResults(hands);
	hf.stopTiming();
	hf.printFrequencies(cout);
}

void processWorker(int rank) {
	int handFound, msgBuff;
	static int recvFlag;
	MPI_Status status;
	MPI_Request request;
	int hands[10] = {0};
	vector<Card> deck;
	populateDeck(deck);
	do {
		random_shuffle(deck.begin(), deck.end());
		handFound = drawAndAnalyzeHand(deck);
		if(hands[handFound]++ == 0){
			//send message
			MPI_Send(&handFound, 1, MPI_INT, 0, TAG_DATA, MPI_COMM_WORLD);
		}
		MPI_Iprobe(MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &recvFlag, &status);

		if (recvFlag)
		{
			MPI_Recv(&msgBuff, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
		}
	} while (status.MPI_TAG != TAG_QUIT );
	MPI_Send(&hands, 10, MPI_INT, 0, TAG_DATA, MPI_COMM_WORLD);
}



int main(int argc, char* argv[])
{
	if( !MPI_Init(&argc, &argv) == MPI_SUCCESS )
		return EXIT_FAILURE;
	else{
		int rank, numProcs;
		MPI_Comm_size(MPI_COMM_WORLD, &numProcs);
		if(numProcs > 0)
		{
			MPI_Comm_rank(MPI_COMM_WORLD, &rank);
			if (rank == 0)
				processMaster(numProcs);
			else
				processWorker(rank);

		}
		else {
			cerr << "0 Procs? Really bub?" << endl;
		}
	}

	MPI_Finalize();
}