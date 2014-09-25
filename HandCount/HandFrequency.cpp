#include "HandFrequency.h"
#include <omp.h>

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
}
bool HandFrequency::checkForFourOfAKind(std::vector<Card> hand) {

	return(hand[0].getRank() == hand[3].getRank() || hand[1].getRank() == hand[4].getRank());
}
bool HandFrequency::checkForFullHouse(std::vector<Card> hand) {

	return(hand[0].getRank() == hand[1].getRank() && hand[3].getRank() == hand[4].getRank() && (hand[2].getRank() == hand[0].getRank() || hand[2].getRank() == hand[4].getRank()));
}
bool HandFrequency::checkForFlush(std::vector<Card> hand) {
	
	return(hand[0].getSuit() == hand[1].getSuit() && hand[1].getSuit() == hand[2].getSuit() && hand[2].getSuit() == hand[3].getSuit() && hand[3].getSuit() == hand[4].getSuit());
}
bool HandFrequency::checkForStraight(std::vector<Card> hand) {
	
	return((hand[0].getRank() + 1 == hand[1].getRank() && hand[1].getRank() + 1 == hand[2].getRank() && hand[2].getRank() + 1 == hand[3].getRank() && hand[3].getRank() + 1 == hand[4].getRank()) || (hand[0].getRank() == 0 && hand[1].getRank() == 1 && hand[2].getRank() == 2 && hand[3].getRank() == 3 && hand[4].getRank() == 12 ));
}
bool HandFrequency::checkForThreeOfAKind(std::vector<Card> hand) {
	
	return((hand[0].getRank() == hand[1].getRank() && hand[0].getRank() == hand[2].getRank()) || (hand[1].getRank() == hand[2].getRank() && hand[1].getRank() == hand[3].getRank()) || (hand[2].getRank() == hand[3].getRank() && hand[2].getRank() == hand[4].getRank()));
}
bool HandFrequency::checkForTwoPair(std::vector<Card> hand) {

	return((hand[0].getRank() == hand[1].getRank() && ((hand[2].getRank() == hand[3].getRank()) || (hand[3].getRank() == hand[4].getRank()))) || (hand[1].getRank()==hand[2].getRank() && hand[3].getRank()==hand[4].getRank()));
}
bool HandFrequency::checkForOnePair(std::vector<Card> hand) {
	
	return (hand[0].getRank() == hand[1].getRank() || hand[1].getRank() == hand[2].getRank() || hand[2].getRank() == hand[3].getRank() || hand[3].getRank() == hand[4].getRank());
}

bool operator <(Card lhs, Card rhs){
	return lhs.getRank() < rhs.getRank();
}

bool HandFrequency::allHandTypesOccurred() {
	
	return (royalFlush > 0 && straightFlush > 0 && fourOfAKind > 0 && fullHouse > 0 && flush > 0 && straight > 0 && threeOfAKind > 0 && twoPair > 0 && onePair > 0 && noPair > 0);
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

	cout.width(25); cout << right << "------------";
	cout.width(25); cout << right << "------------";
	cout << endl;

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
		if(checkForFourOfAKind(hand))
			++fourOfAKind;
		else if(checkForFullHouse(hand))
			++fullHouse;
		else if(checkForThreeOfAKind(hand))
			++threeOfAKind;
		else if(checkForTwoPair(hand))
			++twoPair;
		else if(checkForOnePair(hand))
			++onePair;
		else
			++noPair;
	}
}

void HandFrequency::startTiming() {
	start = omp_get_wtime();
}

void HandFrequency::stopTiming() {
	end = omp_get_wtime();
}
