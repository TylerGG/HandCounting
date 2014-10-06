#include "HandFrequency.h"
#include <omp.h>
#include <mpi.h>

using namespace std;

HandFrequency::HandFrequency() {
	royalFlush, straightFlush, fourOfAKind, fullHouse, flush, straight, threeOfAKind, twoPair, onePair, noPair = 0;
	royalFlushOccurred, straightFlushOccurred, fourOfAKindOccurred, fullHouseOccurred, flushOccurred, straightOccurred, threeOfAKindOccurred, twoPairOccurred, onePairOccurred, noPairOccurred = false;
}


bool HandFrequency::allHandTypesOccurred() {
	return (royalFlushOccurred && straightFlushOccurred && fourOfAKindOccurred && fullHouseOccurred && flushOccurred && straightOccurred && threeOfAKindOccurred && twoPairOccurred && onePairOccurred && noPairOccurred);
}

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


void HandFrequency::startTiming() {
	start = MPI_Wtime();
}

void HandFrequency::stopTiming() {
	end = MPI_Wtime();
}
