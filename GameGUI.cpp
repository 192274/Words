//
// Created by w on 3/2/18.
//

#include <iostream>
#include <sstream>
#include <assert.h>
#include "GameGUI.h"
#include "GameState.h"
#include "GameDrawable.h"
#include "Round.h"

GameGUI::GameGUI() : game(){
}

void GameGUI::play()
{




    fontAddress = "Butler_Regular_Stencil.otf";     //"heneczek-regular-1508762860.otf";    //"FFF_Tusj.ttf";
    font.loadFromFile(fontAddress);
    windowTitle = "Majestic Window";
    windowSize = sf::Vector2u(800, 600);
    inputTextPosition = sf::Vector2f(100, 500);
    inputTextSize = 190;
    backgroundColor = sf::Color(0, 0, 0);
    inputTextColor = sf::Color(255, 255, 255);
    sf::Text welcomeText(L"Witaj w grze!\nPóźniej objaśnię szczegóły.", font);

    float b = 3;
    float a = 0.9;

    sf::VertexArray quad (sf::Quads, 16);
    float a = 0.1, float b = 0.3;
    float o = 2 * (windowSize.x + windowSize.y) * (1 - 2 * a) - 4 * b;
    float ax = 0.9, bx = 0.03, by = 0.03, ay = 0.9;
    for(int i = 0; i < 16; i++) {
        for(int j = 0; j < 4; j++) {
            quad[0].position = sf::Vector2f(windowSize.x / 2 * (1 + ax) + bx, windowSize.y / 2 * (1 + ay) + by);
            quad[0].position = sf::Vector2f(windowSize.x/2*(1+ax)+bx, windowSize.y/2*(1-ay)-by);
            quad[0].position = sf::Vector2f(windowSize.x/2*(1+ax)-bx, windowSize.y/2*(1-ay)-by);
            quad[0].position = sf::Vector2f(windowSize.x/2*(1+ax)-bx, windowSize.y/2*(1+ay)+by);
        }
    }
    quad[0].position = sf::Vector2f(windowSize.x/2*(1+ax)+bx, windowSize.y/2*(1+ay)+by);
    quad[1].position = sf::Vector2f(windowSize.x * ax - bx, windowSize.y * ax+bx);
    quad[0].position = sf::Vector2f(windowSize.x * ax - bx, windowSize.y * (1-ax) +bx);
    quad[0].position = sf::Vector2f(windowSize.x * ax+bx, windowSize.y * (1-a) +bx);

    quad[0].position = sf::Vector2f(windowSize.x * (1-a)+b, windowSize.y * (1-a)+b);
    quad[0].position = sf::Vector2f(windowSize.x * (1-a)+b, windowSize.y * (1-a));
    quad[0].position = sf::Vector2f(windowSize.x * a, windowSize.y * (1-a));
    quad[0].position = sf::Vector2f(windowSize.x * a, windowSize.y * (1-a));

    quad[0].position = sf::Vector2f(windowSize.x * 0.1, windowSize.y * 0.1);
    quad[0].position = sf::Vector2f(windowSize.x * 0.87, windowSize.y * 0.1);
    quad[0].position = sf::Vector2f(windowSize.x * 0.87, windowSize.y * 0.13);
    quad[0].position = sf::Vector2f(windowSize.x * 0.13, windowSize.y * 0.);

    quad[0].position = sf::Vector2f(windowSize.x * 0.9, windowSize.y * 0.1);
    quad[0].position = sf::Vector2f(windowSize.x * 0.9, windowSize.y * 0.1);
    quad[0].position = sf::Vector2f(windowSize.x * 0.9, windowSize.y * 0.1);
    quad[0].position = sf::Vector2f(windowSize.x * 0.9, windowSize.y * 0.1);





    welcomeText.setPosition(100, 300);
    text.setPosition(100, 500);



    duration = 10; //30

    window.setTitle(windowTitle);
    //window.setFramerateLimit(60);

    window.display();
    while(window.isOpen())
    {
        window.draw(quad);
        eventsService();
        window.display();
    }
}

void GameGUI::eventsService()
{
    if(STATE > 0 && STATE < 4 && time(0) - start > duration) {
        current_text = "";
        if(STATE != 3)
            game.start_round(STATE);
        window.clear();
        if(STATE == 3) window.draw(sf::Text(scoreMsg(), font, 120));
        else window.draw(sf::Text(getText(), font, 120));
        STATE++;
        start = time(0);
    }

    sf::Event event;
    while(window.pollEvent(event))
    {
        switch(STATE) {
            case GameState::TITLE: {
                waitForKeyGoToN(event, 0);
                break;
            }
            case GameState::RULES: {
                startEventsService(event);
                break;
            }
            case GameState::ROUND_1: {
                roundEventsService(event);
                break;
            }
            case GameState::ROUND_2: {
                roundEventsService(event);
                break;
            }
            case GameState::ROUND_3: {
                roundEventsService(event);
                break;
            }
            case GameState::SCORES: {
                text.setString(scoreMsg());
                window.clear();
                window.draw(sf::Text(scoreMsg(), font, 120));
                game.start_round(0);
                if(event.type == sf::Event::Closed) {
                    window.close();
                }
                else
                if(time(0) - start > 3 && event.type == sf::Event::KeyPressed) {
                    window.clear();
                    window.draw(sf::Text("Some start message", font, 120));
                    STATE = 0;
                    start = time(0);
                }
                break;
            }
            default:
                break;
        };
    }
}

string GameGUI::scoreMsg() const {
    string s = "You scored " + to_string(game.roundScore()) + " points";
    return s;
}

void GameGUI::waitForKeyGoToN(const sf::Event &event, int n) {
    switch(event.type)
        {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
            {
                window.clear();
                window.draw(sf::Text("Some start message", font, 120));
                STATE = n;
                start = time(0);
                break;
            }
        };
}

void GameGUI::startEventsService(const sf::Event &event) {
    switch(event.type)
    {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyPressed:
        {
            game.start_round(STATE);
            start = time(0);
            window.clear();
            window.draw(sf::Text("Objaśniam zasady gry", font, 120));
            ++STATE;
            break;
        }
    };
}

void GameGUI::roundEventsService(const sf::Event &event) {
    switch(event.type)
    {
        case sf::Event::Closed: {
            window.close();
            break;
        }
        case sf::Event::TextEntered:
        {
            inputChar(event.key.code);
            window.clear();
            window.draw(sf::Text(getText(), font, 120));
            if(time(0) - start > duration) {
                start = time(0);
                nextState = 4;
            }
            break;
        }
    };
}

bool GameGUI::inputChar(uint c)
{
    if(c == 8)                                  //backspace
    {
        if(!current_text.empty())
            current_text.pop_back();
        else
            return false;
    }
    if(c == 13 || c == 32) {                    //return space
        pushWord();
        last_text = current_text;
        current_text = "";
        return true;
    }
    if(c == 9) {                                //tab
        current_text = last_text;
        return false;
    }
    if(c < 65 || c > 90 && c < 97 || c > 122)   //inne nielitery
        return false;
    current_text.push_back(c);                  //litery
    return false;
}

//void GameGUI::makeWindow() //uzywanie setSize rozpierdalalo
//{
//    window.setSize(windowSize);
//    window.setTitle(windowTitle);
//
//}

int GameGUI::pushWord() {
    int result = game.pushWord(getText());
    //return result;
    sf::Text communicate  = sf::Text("Objaśniam zasady gry", font, 120);
    communicate.setPosition(inputTextPosition);
    window.clear();
    window.draw(communicate);
    return result;
}

std::string GameGUI::getText() const {
    return game.getPrefix() + current_text;
}
