#ifndef HAND_FREQUENCY_H
#define HAND_FREQUENCY_H

#include <iostream>
#include "Card.h"
#include <vector>
#include <algorithm>

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
	bool checkForFourOfAKind(std::vector<Card> hand);
	bool checkForFullHouse(std::vector<Card> hand);
	bool checkForFlush(std::vector<Card> hand);
	bool checkForStraight(std::vector<Card> hand);
	bool checkForThreeOfAKind(std::vector<Card> hand);
	bool checkForTwoPair(std::vector<Card> hand);
	bool checkForOnePair(std::vector<Card> hand);
	
public:
	void printFrequencies(std::ostream &);
	bool allHandTypesOccurred();
	void drawAndAnalyzeHand(std::vector<Card> &);
	HandFrequency();
};
#endif