#include "HandFrequency.h"

void HandFrequency::checkForRoyalFlush() {
	++royalFlush;
}
void HandFrequency::checkForStraightFlush() {
	++straightFlush;
}
void HandFrequency::checkForFourOfAKind() {
	++fourOfAKind;
}
void HandFrequency::checkForFullHouse() {
	++fullHouse;
}
void HandFrequency::checkForFlush() {
	++flush;
}
void HandFrequency::checkForStraight() {
	++straight;
}
void HandFrequency::checkForThreeOfAKind() {
	++threeOfAKind;
}
void HandFrequency::checkForTwoPair() {
	++twoPair;
}
void HandFrequency::checkForOnePair() {
	++onePair;
}
void HandFrequency::checkForNoPair() {
	++noPair;
}


bool HandFrequency::allHandTypesOccured() {
	
	if(royalFlush < 0)
		return false;
	if(straightFlush < 0)
		return false;
	if(fourOfAKind < 0)
		return false;
	if(fullHouse < 0)
		return false;
	if(flush < 0)
		return false;
	if(straight < 0)
		return false;
	if(threeOfAKind < 0)
		return false;
	if(twoPair < 0)
		return false;
	if(onePair < 0)
		return false;
	if(noPair < 0)
		return false;
		
	return true;
}


void HandFrequency::drawAndAnalyseHand(std::vector<Card> &deck) {


}