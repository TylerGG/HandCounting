#include "Card.h"

/*
	Card.cpp
	@Author : Tyler Garrow, Craig Treulieb
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

