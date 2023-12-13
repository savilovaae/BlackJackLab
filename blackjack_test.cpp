#include <iostream>
#include <gtest/gtest.h>
#include "Card.h"
#include "Dealer.h"
#include "Player.h"

TEST(Card, constructor) {
    Card AceDiamonds(Card::Suit::Diamonds, Card::Face::Ace);
    EXPECT_EQ(AceDiamonds.getSuit(), Card::Suit::Diamonds);
    EXPECT_EQ(AceDiamonds.getFace(), Card::Face::Ace);
}


