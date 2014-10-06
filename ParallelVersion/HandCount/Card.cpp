#include "Card.h"

/*
	Card.cpp
	@Auther : Tyler Garrow, Craig Treuleib
	implements Card.hpp
*/



Card::Card(Suit s, Rank r) : rank(r), suit(s) {

}

Rank Card::getRank() {
	return rank;
}

Suit Card::getSuit() {
	return suit;
}

