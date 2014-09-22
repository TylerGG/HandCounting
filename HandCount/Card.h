#ifndef CARD_H
#define CARD_H

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
};

#endif