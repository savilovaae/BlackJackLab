#include <iostream>
#include <gtest/gtest.h>
#include "Card.h"
#include "Dealer.h"
#include "Player.h"
#include "IBlackjackStrategy.h"
#include "gameLogic.h"

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

TEST(SimpleDealer, constructor) {
    SimpleDealer testDealer;
    Card testCard = testDealer.giveCard();
    EXPECT_EQ(testCard.getFace(), Card::Face::Two);
    EXPECT_EQ(testCard.getSuit(), Card::Suit::Hearts);
}

TEST(Player, constructor) {
    Player first;
    EXPECT_EQ(first.getScore(), 0) << "Player was created with error";
    EXPECT_EQ(first.getFlag(), true);

    Card NineSpades(Card::Suit::Spades, Card::Face::Nine);
    first.takeCard(NineSpades);
    EXPECT_EQ(first.getFlag(), true);
    EXPECT_EQ(first.getScore(), 9);
    Card QueenClubs(Card::Suit::Clubs, Card::Face::Queen);
    first.takeCard(QueenClubs);
    EXPECT_EQ(first.getScore(), 19);
    EXPECT_EQ(first.getFlag(), true);

    AlwaysHitStrategy strategyAHS;
    Player second(&strategyAHS);
    Card TenSpades(Card::Suit::Spades, Card::Face::Ten);
    second.takeCard(TenSpades);
    EXPECT_EQ(second.getScore(), 10);
    EXPECT_EQ(second.getFlag(), true);
    Card SixHearts(Card::Suit::Hearts, Card::Face::Six);
    second.takeCard(SixHearts);
    EXPECT_EQ(second.getScore(), 16);
    EXPECT_EQ(second.getFlag(), true);
    Card AceClubs(Card::Suit::Clubs, Card::Face::Ace);
    second.takeCard(AceClubs);
    EXPECT_EQ(second.getScore(), 17);
    EXPECT_EQ(second.getFlag(), false);

    NeverBustStrategy strategyNBS;
    Player third(&strategyNBS);
    Card QueenHearts(Card::Suit::Hearts, Card::Face::Queen);
    third.takeCard(QueenHearts);
    EXPECT_EQ(third.getScore(), 10);
    EXPECT_EQ(third.getFlag(), true);
    Card TwoDiamonds(Card::Suit::Diamonds, Card::Face::Two);
    third.takeCard(TwoDiamonds);
    EXPECT_EQ(third.getScore(), 12);
    EXPECT_EQ(third.getFlag(), false);
}

TEST(MODE, runDetailed) {
    Dealer *testDealer = new SimpleDealer;
    IBlackjackStrategy *strategyAHS = new AlwaysHitStrategy;
    IBlackjackStrategy *strategyNBS = new NeverBustStrategy;
    std::list<IBlackjackStrategy> strategies = {strategyNBS, strategyAHS};
    Game testGame(testDealer, &strategies, Game::Mode::detailed);


}