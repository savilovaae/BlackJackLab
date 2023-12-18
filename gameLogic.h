#ifndef BLACKJACK_GAMELOGIC_H
#define BLACKJACK_GAMELOGIC_H

#include <list>
#include "Dealer.h"
#include "Player.h"
#include "IBlackjackStrategy.h"

class Game {
public:
    enum Mode {
        detailed, fast, tournament
    };
    Game(const Dealer& dealer_, std::list <IBlackjackStrategy>& strategies_, Mode mode_);

    void run();

private:
    void runFast();
    void runDetailed(Player first, Player second);
    void runTournament();
    Dealer dealer_;
    std::list <IBlackjackStrategy> strategies_;
    Mode mode_;
};

#endif //BLACKJACK_GAMELOGIC_H
