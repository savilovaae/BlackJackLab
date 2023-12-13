#ifndef BLACKJACK_IBLACKJACKSTRATEGY_H
#define BLACKJACK_IBLACKJACKSTRATEGY_H
#include "blackjack.h"
#include "Card.h"
#include "Player.h"

class IBlackjackStrategy {
public:
    virtual bool shouldTakeCard(const Player& player, const Card& dealerCard) const = 0;
    virtual ~IBlackjackStrategy() {}
};


class AlwaysHitStrategy : public IBlackjackStrategy {
public:
    bool shouldTakeCard(const Player& player, const Card& dealerCard) const override;
};

class NeverBustStrategy : public IBlackjackStrategy {
public:
    bool shouldTakeCard(const Player& player, const Card& dealerCard) const override;
};

class DealerBasedStrategy : public IBlackjackStrategy {
public:
    bool shouldTakeCard(const Player& player, const Card& dealerCard) const override;
};

#endif //BLACKJACK_IBLACKJACKSTRATEGY_H
