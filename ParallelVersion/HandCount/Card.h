#ifndef CARD_H
#define CARD_H

/*
	Card.h
	@Author : Tyler Garrow, Craig Treulieb
*/

enum Suit {
	SPADES,
	DIAMONDS,
	CLUBS,
	HEARTS
};

enum Rank {
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING,
	ACE
};

class Card {
private:
	Suit suit; 
	Rank rank;
public:
	Card(Suit s, Rank r);
	Suit getSuit();
	Rank getRank();
	
};

#endif