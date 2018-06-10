//
// Created by w on 3/2/18.
//

#ifndef SFML_GAME_GAMEGUI_H
#define SFML_GAME_GAMEGUI_H

#include <SFML/Graphics.hpp>
#include <string.h>
#include "Game.h"
#include "GameState.h"

class GameGUI {

    typedef std::chrono::high_resolution_clock Time;
    typedef std::chrono::milliseconds msec;
    typedef std::chrono::seconds sec;
    typedef std::chrono::duration<double> dsec;

private:
    std::string fontAddress;
    sf::Font font;
    std::string windowTitle;
    sf::Vector2f inputTextPosition;
    unsigned int inputTextSize;
    sf::Color backgroundColor;
    sf::Color inputTextColor;
    sf::Text text;
    sf::VertexArray timer(sf::VertexArray quad);
    std::string points() const;
    sf::Vector2u windowSize {1400, 700};


    sf::Text rulesText;
    sf::VertexArray disappearingFrame(double percent, sf::VertexArray frame, float a, float b);

    std::vector<sf::Drawable> toDraw{};

    int duration;
    int nextState;

    time_t start;
    time_t kn;

    std::chrono::time_point<Time, dsec> start_time;
    std::chrono::time_point<Time, dsec> end_time;

   // GameDrawable gameDrawable;
   // std::string warnings {"Repeatition", "Incorrect"};

    std::string current_text;
    std::string last_text;

    std::string repeated_word_communicate = "\nRepetition!";
    std::string typo = "\nTypo!";


    int STATE = -1;

    Game game;
    sf::RenderWindow window{sf::VideoMode(windowSize.x, windowSize.y), "Window majestatic"};

    //void makeWindow();
    bool inputChar(uint);

    int pushWord();
    std::string getText() const ;


public:
    GameGUI();
    void play();
    void eventsService();
    void waitForKeyGoToN(const sf::Event &event, int n) ;
    void startEventsService(const sf::Event &event);
    void roundEventsService(const sf::Event &event);

    string scoreMsg() const;

    sf::VertexArray quads(int r, int g, int b, int alpha, float ax, float bx) const;
};


#endif //SFML_GAME_GAMEGUI_H
