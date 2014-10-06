#ifndef HAND_FREQUENCY_H
#define HAND_FREQUENCY_H

#include <iostream>
#include "Card.h"
#include <vector>
#include <algorithm>

/*
	HandFrequency.h
	@Auther : Tyler Garrow, Craig Treuleib
*/



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
	void addResults(int results[]);
	void foundHand(int h);
	void foundHand(int h, int c);
	HandFrequency();
};
#endif