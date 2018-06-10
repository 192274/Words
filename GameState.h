//
// Created by w on 6/8/18.
//

#ifndef SFML_GAME_GAMESTATE_H
#define SFML_GAME_GAMESTATE_H


#include "Round.h"
#include "Game.h"

enum GameState {
    TITLE = -1,
    RULES = 0,
    ROUND_1 = 1,
    ROUND_2 = 2,
    ROUND_3 = 3,
    SCORES = 4
};


#endif //SFML_GAME_GAMESTATE_H
