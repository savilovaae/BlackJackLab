#ifndef BLACKJACK_IBLACKJACKSTRATEGY_H
#define BLACKJACK_IBLACKJACKSTRATEGY_H

#include "Card.h"
#include "Player.h"

class IBlackjackStrategy {
public:
    virtual bool shouldTakeCard(class Player &player);

    virtual ~IBlackjackStrategy() {}
};


class AlwaysHitStrategy : public IBlackjackStrategy {
public:
    bool shouldTakeCard(class Player &player) override;
};

class NeverBustStrategy : public IBlackjackStrategy {
public:
    bool shouldTakeCard(Player &player) override;
};

class DealerBasedStrategy : public IBlackjackStrategy {
public:
    bool shouldTakeCard(Player &player) override;
};

#endif //BLACKJACK_IBLACKJACKSTRATEGY_H
