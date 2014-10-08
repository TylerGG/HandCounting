#include "HandFrequency.h"
#include <omp.h>
#include <mpi.h>

/*
	HandFrequency.cpp
	@Author : Tyler Garrow, Craig Treulieb
	implements HandFrequency.hpp

	@note where int repersents a hand  type
	0 = straight
	1 = flush
	2 = four of a kind
	3 = full house
	4 = flush
	5 = straight
	6 = three of a kind
	7 = two pair
	8 = one pair
	9 = no pair
*/


using namespace std;

HandFrequency::HandFrequency() {
	royalFlush = 0;
	straightFlush = 0;
	fourOfAKind = 0;
	fullHouse = 0;
	flush = 0;
	straight = 0;
	threeOfAKind = 0;
	twoPair = 0;
	onePair = 0;
	noPair = 0;
	royalFlushOccurred = false;
	straightFlushOccurred = false;
	fourOfAKindOccurred = false;
	fullHouseOccurred = false;
	flushOccurred = false;
	straightOccurred = false;
	threeOfAKindOccurred = false;
	twoPairOccurred = false;
	onePairOccurred = false;
	noPairOccurred = false;
}


bool HandFrequency::allHandTypesOccurred() {
	return (royalFlushOccurred && straightFlushOccurred && fourOfAKindOccurred && fullHouseOccurred && flushOccurred && straightOccurred && threeOfAKindOccurred && twoPairOccurred && onePairOccurred && noPairOccurred);
}


/*
	@HandFrequency member function foundHand
	@int represents hand type;
	@purpose to be able to track what hands have been found
*/
void HandFrequency::foundHand(int h) {
	switch (h)
	{
		case 0:
			royalFlushOccurred = true;
			break;
		case 1:
			straightFlushOccurred = true;
			break;
		case 2:
			fourOfAKindOccurred = true;
			break;
		case 3:
			fullHouseOccurred = true;
			break;
		case 4:
			flushOccurred = true;
			break;
		case 5:
			straightOccurred = true;
			break;
		case 6:
			threeOfAKindOccurred = true;
			break;
		case 7:
			twoPairOccurred = true;
			break;
		case 8:
			onePairOccurred = true;
			break;
		case 9:
			noPairOccurred = true;
			break;
	}
}


/*
	@HandFrequency member function foundHand
	@param int representing the Hand type
	@param int the frequency to be added to a hand type
	@purpose to be able to total frequencies for each hand type
*/
void HandFrequency::foundHand(int h, int c) {
	switch (h)
	{
		case 0:
			royalFlush += c;
			break;
		case 1:
			straightFlush += c;
			break;
		case 2:
			fourOfAKind += c;
			break;
		case 3:
			fullHouse += c;
			break;
		case 4:
			flush += c;
			break;
		case 5:
			straight += c;
			break;
		case 6:
			threeOfAKind += c;
			break;
		case 7:
			twoPair += c;
			break;
		case 8:
			onePair += c;
			break;
		case 9:
			noPair += c;
			break;
	}
}


/*
	@function printFrequencies
	@param ostream [reference]
	@puropose	will take the frequencies of of all card types and print it into a table.

	@Note if start and end time are not used with HandFrequency displayed time is not reliable

*/
void HandFrequency::printFrequencies(std::ostream &out) {
	int N = royalFlush + straightFlush + flush + straight + fourOfAKind + fullHouse + threeOfAKind + twoPair + onePair + noPair;

	
	cout.width(25); cout << right << "============";
	cout.width(25); cout << right << "============";
	cout.width(25); cout << right << "============";
	cout << endl;

	cout.width(25); cout << right << "Hand Type";
	cout.width(25); cout << right << "Frequency";
	cout.width(25); cout << right << "Relative Frequency (%)";
	cout << endl;

	cout.width(25); cout << right << "------------";
	cout.width(25); cout << right << "------------";
	cout.width(25); cout << right << "------------";
	cout << endl;

	cout.width(25); cout << right << "No Pair";
	cout.width(25); cout << right << noPair;
	cout.width(25); cout << right << ((double)noPair/(double)N) * 100;
	cout << endl;

	cout.width(25); cout << right << "One Pair";
	cout.width(25); cout << right << onePair;
	cout.width(25); cout << right << ((double)onePair/(double)N) * 100;
	cout << endl;

	cout.width(25); cout << right << "Two Pair";
	cout.width(25); cout << right << twoPair;
	cout.width(25); cout << right << ((double)twoPair/(double)N) * 100;
	cout << endl;

	cout.width(25); cout << right << "Three of a kind";
	cout.width(25); cout << right << threeOfAKind;
	cout.width(25); cout << right << ((double)threeOfAKind/(double)N) * 100;
	cout << endl;

	cout.width(25); cout << right << "Straight";
	cout.width(25); cout << right << straight;
	cout.width(25); cout << right << ((double)straight/(double)N) * 100;
	cout << endl;

	cout.width(25); cout << right << "Flush";
	cout.width(25); cout << right << flush;
	cout.width(25); cout << right << ((double)flush/(double)N) * 100;
	cout << endl;

	cout.width(25); cout << right << "Full House";
	cout.width(25); cout << right << fullHouse;
	cout.width(25); cout << right << ((double)fullHouse/(double)N) * 100;
	cout << endl;

	cout.width(25); cout << right << "Four of a Kind";
	cout.width(25); cout << right << fourOfAKind;
	cout.width(25); cout << right << ((double)fourOfAKind/(double)N) * 100;
	cout << endl;

	cout.width(25); cout << right << "Straight Flush";
	cout.width(25); cout << right << straightFlush;
	cout.width(25); cout << right << ((double)straightFlush/(double)N) * 100;
	cout << endl;

	cout.width(25); cout << right << "Royal Flush";
	cout.width(25); cout << right << royalFlush;
	cout.width(25); cout << right << ((double)royalFlush/(double)N) * 100;
	cout << endl;

	cout.width(25); cout << right << "------------";
	cout.width(25); cout << right << "------------";
	cout.width(25); cout << right << "------------";
	cout << endl;

	cout.width(25); cout << right << "Hands Generated";
	cout.width(25); cout << right << N;
	cout << endl;

	cout.width(25); cout << right << "Time Elapsed (s)";
	cout.width(25); cout << right << end - start;
	cout << endl;

	
	int numProcs;
	MPI_Comm_size(MPI_COMM_WORLD, &numProcs);
	cout.width(25); cout << right << "Number Of Proceses";
	cout.width(25); cout << right << numProcs;
	cout << endl;

	cout.width(25); cout << right << "------------";
	cout.width(25); cout << right << "------------";
	cout << endl;

}

void HandFrequency::addResults(int results[]) {
	for(int i = 0; i < 10; ++i)
		foundHand(i, results[i]);
}

void HandFrequency::startTiming() {
	start = MPI_Wtime();
}

void HandFrequency::stopTiming() {
	end = MPI_Wtime();
}
