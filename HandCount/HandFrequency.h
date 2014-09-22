#ifndef HAND_FREQUENCY_H
#define HAND_FREQUENCY_H

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
	void checkForRoyalFlush();
	void checkForStraightFlush();
	void checkForFourOfAKind();
	void checkForFullHouse();
	void checkForFlush();
	void checkForStraight();
	void checkForThreeOfAKind();
	void checkForTwoPair();
	void checkForOnePair();
	void checkForNoPair();
	
public:
	bool allHandTypesOccured();
	void drawAndAnalyseHand(std::vector<Card> &);
};
#endif