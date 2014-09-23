#include "HandFrequency.h"

bool HandFrequency::checkForRoyalFlush() {
	++royalFlush;
	return false;
}
bool HandFrequency::checkForStraightFlush() {
	++straightFlush;
	return false;
}
bool HandFrequency::checkForFourOfAKind() {
	++fourOfAKind;
	return false;
}
bool HandFrequency::checkForFullHouse() {
	++fullHouse;
	return false;
}
bool HandFrequency::checkForFlush() {
	++flush;
	return false;
}
bool HandFrequency::checkForStraight() {
	++straight;
	return false;
}
bool HandFrequency::checkForThreeOfAKind() {
	++threeOfAKind;
	return false;
}
bool HandFrequency::checkForTwoPair() {
	++twoPair;
	return false;
}
bool HandFrequency::checkForOnePair() {
	++onePair;
	return false;
}
bool HandFrequency::checkForNoPair() {
	++noPair;
	return false;
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


void HandFrequency::printFrequencies(std::ostream &) {

}

void HandFrequency::drawAndAnalyzeHand(std::vector<Card> &deck) {


}