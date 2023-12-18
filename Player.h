#ifndef BLACKJACK_PLAYER_H
#define BLACKJACK_PLAYER_H

#include "IBlackjackStrategy.h"
#include <vector>

class Player {
public:
    Player() = default;

    Player(class IBlackjackStrategy *strategy) : score_(0), strategy_(strategy), flag_(true) {}

    bool getFlag() const;

    int getScore() const;

    void takeCard(const Card &card);

    int calculateScore();

    void reset();

private:
    std::vector<Card> hand_;
    int score_ = 0;
    bool flag_ = true;
    class IBlackjackStrategy *strategy_ = nullptr;
};

#endif //BLACKJACK_PLAYER_H
