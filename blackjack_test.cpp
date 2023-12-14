#include <iostream>
#include <gtest/gtest.h>
#include "Card.h"
#include "Dealer.h"
#include "Player.h"

TEST(Card, constructor) {
    Card defaultCard;
    EXPECT_EQ(defaultCard.getSuit(), Card::Suit::Hearts);
    EXPECT_EQ(defaultCard.getFace(), Card::Face::Ace);
    EXPECT_EQ(defaultCard.getValue(), 1);

    Card AceDiamonds(Card::Suit::Diamonds, Card::Face::Ace);
    EXPECT_EQ(AceDiamonds.getSuit(), Card::Suit::Diamonds);
    EXPECT_EQ(AceDiamonds.getFace(), Card::Face::Ace);
    EXPECT_EQ(AceDiamonds.getValue(), 1);

    Card QueenClubs(Card::Suit::Clubs, Card::Face::Queen);
    EXPECT_EQ(QueenClubs.getSuit(), Card::Suit::Clubs);
    EXPECT_EQ(QueenClubs.getFace(), Card::Face::Queen);
    EXPECT_EQ(QueenClubs.getValue(), 10);

    Card NineSpades(Card::Suit::Spades, Card::Face::Nine);
    EXPECT_EQ(NineSpades.getSuit(), Card::Suit::Spades);
    EXPECT_EQ(NineSpades.getFace(), Card::Face::Nine);
    EXPECT_EQ(NineSpades.getValue(), 9);
}


