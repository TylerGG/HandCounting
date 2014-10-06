#include "Card.h"

Card::Card(Suit s, Rank r) : rank(r), suit(s) {

}

Rank Card::getRank() {
	return rank;
}

Suit Card::getSuit() {
	return suit;
}

