//
// Created by w on 2/25/18.
//

#ifndef SFML_GAME_GAME_H
#define SFML_GAME_GAME_H

#include <string>
#include "Dictionary.h"
#include "Round.h"
#include <SFML/Graphics.hpp>

using namespace std;

class Game {
public:
private:
    Round round1;
    Round round2;
    Round round3;
    std::vector<Round> rounds;
    Dictionary dict;
    int currentRoundNr = 0; //current round number
    //const double time;
    int seconds_per_round;

    int points;
    std::string currentPrefix;
    std::string currentText;

    bool check_word();

public:
    Game();

    std::string randomPrefix(int length) const;
    int pushWord(std::string word);
    void start_round(int number);
    bool isRoundOver() const;
    int roundScore() const ;
    std::string getPrefix() const {
        return currentPrefix;
    }
    int score() {
        return points;
    }

};


#endif //SFML_GAME_GAME_H
