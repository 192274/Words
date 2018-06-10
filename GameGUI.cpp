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

    welcomeText.setPosition(100, 300);
    text.setPosition(100, 500);





    window.setTitle(windowTitle);
    window.setFramerateLimit(60);

    //gameDrawable.draw(window);
    window.display();
    while(window.isOpen())
    {
        //std::cout<<'\n'<<game.rounds[0].duration();
        eventsService();
        window.display();
    }
    std::cout<<"The end";
}

void GameGUI::eventsService()
{
    if(STATE > 0 && time(0) - st > secondsPast)
        STATE = nextState;

    sf::Event event;
    while(window.pollEvent(event))
    {
        switch(STATE) {
            case -1: {
                welcomeEventsService(event);
                break;
            }
            case 0: {
                startEventsService(event);
                break;
            }
            case 1: {
                roundEventsService(event);
                break;
            }
            case 2: {
                if (time(0) - st < 5)
                std::cout<<"222 ";
                break;
            }
            case 3: {
                std::cout<<"333 ";
                break;
            }
            case 4: {
                showScores();
                std::string s = "You scored " + std::to_string(game.roundScore()) + " points";
                text.setString(s);
                window.clear();
                window.draw(sf::Text(s, font, 120));
                window.display();
                st = time(0);
                secondsPast = 5;
                STATE = 2;
                break;
            }
            default:
                break;
        };
    }
}

void GameGUI::welcomeEventsService(const sf::Event &event) {
    switch(event.type)
        {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
            {
                window.clear();
                window.draw(sf::Text("Some start message", font, 120));
                STATE++;
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
            //start_time = Time::now();
            st = time(0);
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

void GameGUI::makeWindow() //uzywanie setSize rozpierdalalo
{
    window.setSize(windowSize);
    window.setTitle(windowTitle);

}

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

int GameGUI::showScores() {
    std::string s = "You scored " + std::to_string(game.roundScore()) + " points";
    text.setString(s);
    window.clear();
    window.draw(sf::Text(s, font, 120));
    window.display();
}
