#ifndef BLACKJACK_IBLACKJACKSTRATEGY_H
#define BLACKJACK_IBLACKJACKSTRATEGY_H

#include "Card.h"
#include "Player.h"

class IBlackjackStrategy {
public:
    virtual bool shouldTakeCard(class Player &player, Card &dealerCard);

    virtual ~IBlackjackStrategy() {}
};


class AlwaysHitStrategy : public IBlackjackStrategy {
public:
    bool shouldTakeCard(class Player &player, Card &dealerCard) override;
};

class NeverBustStrategy : public IBlackjackStrategy {
public:
    bool shouldTakeCard(Player &player, Card &dealerCard) override;
};

class DealerBasedStrategy : public IBlackjackStrategy {
public:
    bool shouldTakeCard(Player &player, Card &dealerCard) override;
};

#endif //BLACKJACK_IBLACKJACKSTRATEGY_H
