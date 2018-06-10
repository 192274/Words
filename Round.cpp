//
// Created by w on 2/25/18.
//

#include <iostream>
#include "Round.h"

Round::Round(int round_number, int seconds) : typed_words(0), K{1}, points{0} {
    this->round_number = round_number;
    seconds_per_round = seconds;
}

void Round::start() {
    start_time = Time::now();
    end_time = start_time + sec(seconds_per_round);
    total_duration = sec(seconds_per_round);
}

bool Round::was_typed(std::string word) const {
    for(int i = 0; i < typed_words.size(); ++i) {
        if(word == typed_words.at(i))
            return true;
    }
    return false;
}

int Round::push(std::string word) {     //1 ok, 0 repeated
    if(was_typed(word))
        return 0;
    typed_words.push_back(word);
    points += checkPoints(word);
    return checkPoints(word);
}

int Round::checkPoints(const string &word) {
    if(K != 10) {
        int k = ++typed_per_length[-4 + word.length() > 3 ? word.length() > 10 ? 10 : word.length() : 4];
        if (k >= 3) {
            for (int i = 0; i < 7; ++i)
                if(typed_per_length[i] < 3)
                    return 3 * k;
            K = 10;
            return word.length() * 10 * 3;
        }
        else
            return word.length();
    }
    return 10 * word.length();
}

void Round::add_word_length(int word_length) {
    if(word_length <= 4)
        (typed_per_length[0])++;
    else
    if(word_length >= 10)
        (typed_per_length[6])++;
    else
        (typed_per_length[word_length])++;
}

long Round::show_typed() const {
    for(long i = 0; i < typed_words.size(); ++i) std::cout<<typed_words.at(i);
    return typed_words.size();
}

double Round::duration() const {
    return (Time::now() - start_time)/total_duration;
}

double Round::totalDuration() const {
    return total_duration.count();
}

double Round::leftDuration() const {
    return dsec(end_time - Time::now()).count();
}
