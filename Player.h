#ifndef BLACKJACK_PLAYER_H
#define BLACKJACK_PLAYER_H

#include "IBlackjackStrategy.h"
#include <vector>

class Player {
public:
    Player() = default;

    [[maybe_unused]] Player(class IBlackjackStrategy *strategy) : score(0), strategy(strategy), flag(true) {}

    void takeCard(const Card &card);

    int getScore() const;

    bool decideTakeCard(const Card &dealerCard);

    int calculateScore(); //

    void reset(); // -

    bool getFlag();

private:
    std::vector <Card> hand;
    int score = 0;
    class IBlackjackStrategy *strategy;
    bool flag = true;
};

#endif //BLACKJACK_PLAYER_H
