#ifndef HAND_FREQUENCY_H
#define HAND_FREQUENCY_H

#include <iostream>
#include "Card.h"
#include <vector>
#include <algorithm>

class HandFrequency {
private:
	int royalFlush, straightFlush, fourOfAKind, fullHouse, flush, straight, threeOfAKind, twoPair, onePair, noPair;
	bool royalFlushOccurred, straightFlushOccurred, fourOfAKindOccurred, fullHouseOccurred, flushOccurred, straightOccurred, threeOfAKindOccurred, twoPairOccurred, onePairOccurred, noPairOccurred;
	double start;
	double end;
	
public:
	void printFrequencies(std::ostream &);
	bool allHandTypesOccurred();
	void startTiming();
	void stopTiming();
	void foundHand(int h);
	HandFrequency();
};
#endif