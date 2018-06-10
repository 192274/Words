//
// Created by w on 6/8/18.
//

#ifndef SFML_GAME_GAMEDRAWABLE_H
#define SFML_GAME_GAMEDRAWABLE_H


#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class GameDrawable {

public:

    sf::Text welcomeText;
    sf::Text text;
    sf::Text extraText;
    wchar_t fontAddress;
    sf::Font font;
    wchar_t windowTitle;
    sf::Vector2u windowSize;
    sf::Vector2f inputTextPosition;
    unsigned int inputTextSize;
    sf::Color backgroundColor;
    sf::Color inputTextColor;

    wchar_t current_text;
    wchar_t last_text;

    wchar_t repeated_word_communicate = "\nRepetition!";
    wchar_t typo = "\nTypo!";

    GameDrawable();

    void draw(sf::RenderWindow & window) ;
};


#endif //SFML_GAME_GAMEDRAWABLE_H
