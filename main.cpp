#include <SFML/Graphics.hpp>
#include <string>

#include <iostream>
#include "Game.h"
#include "GameGUI.h"
#include "GameState.h"


/*
int gameTest() {
    Game game {};
    std::cout<< game.dict.prefixes.size();
    game.start_round(2);
    std::cout<<"\nhej-"<<game.getPrefix()<<"-hej";
    std::cout<<"\ndown: "<<game.pushWord("down");
    std::cout<<"\ncount "<<game.pushWord("count");
    std::cout<<"\nfive "<<game.pushWord("five");
    std::cout<<"\nplay "<<game.pushWord("play");
    return 0;
    for(std::string s: game.dict.prefixes)
        std::cout<<s<<'\n';
    std::cout<< game.dict.prefixes.size();
    for(std::string s: game.dict.prefixes)
        std::cout<<s<<'\n';
    std::cout<< game.dict.prefixes.size();
}
*/
int main3() {
    Dictionary dict {};
    Round round {3, 10};
    std::cout<<"\npush "<<round.push("ass");
    std::cout<<"\npush "<<round.push("669756sffsd");
    std::cout<<"\n"<<round.was_typed("oven");
    std::cout<<"\n"<<round.was_typed("over");
    std::cout<<"\n"<<round.was_typed("over");
    std::cout<<"\n"<<round.was_typed("xxx");
    std::cout<<"\n"<<round.was_typed("xxx");
    std::cout<<"\n"<<round.getPrefix();
    std::cout<<"\npush oven: "<<round.push("oven");
    std::cout<<"\npush oven: "<<round.push("oven");
    std::cout<<"\npush overkdfjkjfd "<<round.push("ovesfrrrrrffkd");
    std::cout<<"\ndoes contain: "<<dict.contains("over");
    round.start();
/*    while(true) {
        std::cout<<"\n"<<round.totalDuration()<<", "<<round.duration()<<", "<<round.leftDuration();
    }*/

}

int main33() {
    Dictionary dict {};
    std::cout<<"\nWords: "<<dict.words.size();
    std::cout<<"\nPrefixes: "<<dict.prefixes.size();
    std::cout<<"\nRandom: "<<dict.random_prefix(3)<<", "<<dict.prefixes.size();
}


int main()
{
    GameGUI game {};
    game.play();
}




