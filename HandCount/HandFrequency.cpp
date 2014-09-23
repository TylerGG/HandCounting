#include "HandFrequency.h"

bool HandFrequency::checkForFourOfAKind(std::vector<Card> hand) {
	//XXXXO, OXXXX
	return false;
}
bool HandFrequency::checkForFullHouse(std::vector<Card> hand) {
	//XXXYY, XXYYY
	return false;
}
bool HandFrequency::checkForFlush(std::vector<Card> hand) {
	
	return( hand[0].getSuit() == hand[1].getSuit() && hand[1].getSuit() == hand[2].getSuit() && hand[2].getSuit() == hand[3].getSuit() && hand[3].getSuit() == hand[4].getSuit());
}
bool HandFrequency::checkForStraight(std::vector<Card> hand) {
	
	return ( (hand[0].getRank() + 1 == hand[1].getRank() && hand[1].getRank() + 1 == hand[2].getRank() && hand[2].getRank() + 1 == hand[3].getRank() && hand[3].getRank() + 1 == hand[4].getRank()) || (hand[0].getRank() == 0 && hand[1].getRank() == 1 && hand[2].getRank() == 2 && hand[3].getRank() == 3 && hand[4].getRank() == 12 ));
}
bool HandFrequency::checkForThreeOfAKind(std::vector<Card> hand) {
	//XXXOO, OXXXO, OOXXX
	return false;
}
bool HandFrequency::checkForTwoPair(std::vector<Card> hand) {
	//XXOYY, XXYYO, OXXYY
	return false;
}
bool HandFrequency::checkForOnePair(std::vector<Card> hand) {
	//XXOOO, OXXOO, OOXXO, OOOXX
	return false;
}
bool HandFrequency::checkForNoPair(std::vector<Card> hand) {
	
	return false;
}

bool operator <(Card lhs, Card rhs){
	return lhs.getRank() < rhs.getRank();
}

bool HandFrequency::allHandTypesOccured() {
	
	if(royalFlush > 0 && straightFlush > 0 && fourOfAKind > 0 && fullHouse > 0 && flush > 0 && straight > 0 && threeOfAKind > 0 && twoPair > 0 && onePair > 0 && noPair > 0)
		return true;
	else		
		return false;
}


void HandFrequency::printFrequencies(std::ostream &) {

}

void HandFrequency::drawAndAnalyzeHand(std::vector<Card> &deck) {

	
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
			++royalFlush;
		else
			++straightFlush;
	} else if(isFlush) {
		++flush;
	} else if(isStraight) {
		++straight;
	} else {
		//determine if 4OAK, FH, 3OAK, 2PR, 1PR, NPR
	}
	
}