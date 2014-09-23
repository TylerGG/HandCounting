#ifndef HAND_FREQUENCY_H
#define HAND_FREQUENCY_H

#include <iostream>
#include "Card.h"
#include <vector>

class HandFrequency {
private:
	int royalFlush;
	int straightFlush;
	int fourOfAKind;
	int fullHouse;
	int flush;
	int straight;
	int threeOfAKind;
	int twoPair;
	int onePair;
	int noPair;
	bool checkForRoyalFlush();
	bool checkForStraightFlush();
	bool checkForFourOfAKind();
	bool checkForFullHouse();
	bool checkForFlush();
	bool checkForStraight();
	bool checkForThreeOfAKind();
	bool checkForTwoPair();
	bool checkForOnePair();
	bool checkForNoPair();
	
public:
	void printFrequencies(std::ostream &);
	bool allHandTypesOccured();
	void drawAndAnalyzeHand(std::vector<Card> &);
};
#endif