//
// Created by w on 2/25/18.
//

#include <iostream>
#include "Game.h"
#include "GameGUI.h"

Game::Game() : dict(), round1(1, 10), round2(2, 10), round3(3, 10)
{
    rounds.push_back(round1);
    rounds.push_back(round2);
    rounds.push_back(round3);
    points = 0;
    currentPrefix = "";
    currentText = "";
}

std::string Game::randomPrefix(int length) const {
    return dict.random_prefix(length);
}

void Game::start_round(int number) {
    currentRoundNr = number + 1;
    rounds.at(currentRoundNr - 1) = Round{number, seconds_per_round};
    rounds.at(currentRoundNr - 1).setPrefix(randomPrefix(currentRoundNr));
    currentPrefix = rounds[currentRoundNr - 1].getPrefix();
    rounds.at(currentRoundNr - 1).start();
    std::cout<<"\ncurrentPrefix "<<currentPrefix;
}

bool Game::isRoundOver() const {
    return rounds.at(currentRoundNr).duration() > 1.;
}

int Game::pushWord(std::string word) {
    if(!dict.contains(word))
        return -1;
    int p = rounds.at(currentRoundNr - 1).push(word);
    p = p > 3 ? p > 10 ? 11 : p : 4;
    p *= rounds.at(currentRoundNr - 1).K;
    return p;
}

int Game::roundScore() const {
    if(currentRoundNr == 0) return 0;
    return rounds.at(currentRoundNr - 1).score();
}