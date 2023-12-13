#ifndef BLACKJACK_GAMELOGIC_H
#define BLACKJACK_GAMELOGIC_H

#include "Dealer.h"
#include "Player.h"
#include "IBlackjackStrategy.h"

class Game {
public:
    enum Mode {
        detailed, fast, tournament
    };

    Game(Dealer dealer, std::list <IBlackjackStrategy> strategies, Mode mode);

    void run();

private:
    void runFast();
    void runDetailed();
    void runTournament();
    Dealer dealer;
    std::list <IBlackjackStrategy> strategies;
    Mode mode;
};

#endif //BLACKJACK_GAMELOGIC_H
