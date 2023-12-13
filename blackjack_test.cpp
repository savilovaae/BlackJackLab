#include <gtest/gtest.h>
#include "Card.h"
#include "Dealer.h"
#include "Player.h"

TEST(Card, constructor) {
    Card AceDiamonds(Card::Diamonds, Card::Ace);
    EXPECT_EQ(AceDiamonds.getSuit(), Card::Suit::Diamonds);
    EXPECT_EQ(AceDiamonds.getFace(), Card::Face::Ace);
}

TEST(SimpleDealer, constructor) {
    SimpleDealer testDealer();
    EXPECT_TRUE(testDealer);
    Card test = testDealer.giveCard();
    EXPECT_EQ(test.getSuit(), Card::Suit::Hearts);
    EXPECT_TRUE(0 < test.getFace() <= 10);
}

TEST(Player, constructor) {


}