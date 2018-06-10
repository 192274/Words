//
// Created by w on 2/25/18.
//

#ifndef SFML_GAME_ROUND_H
#define SFML_GAME_ROUND_H

#include <vector>
#include <string>
#include <chrono>
#include "Dictionary.h"

using namespace std;

class Round {

    typedef std::chrono::high_resolution_clock Time;
    typedef std::chrono::milliseconds msec;
    typedef std::chrono::seconds sec;
    typedef std::chrono::duration <double> dsec;

private:
public:
    std::chrono::time_point<Time, dsec> start_time;
    std::chrono::time_point<Time, dsec> end_time;
    dsec total_duration;
    int seconds_per_round;
    int round_number;
    int K;
    int points;
    int typed_per_length[6] {0};
    vector<string> typed_words;
    string prefix;
    ///const Dictionary & dict;

    void add_word_length(int word_length);
    int figure_points(string);

public:
    Round(int round_number, int seconds);

    void setPrefix(std::string pref) {
        prefix = pref;
    };
    double duration() const ;           //%
    double leftDuration() const;
    double totalDuration() const;
    bool is_active() const ;

    long show_typed() const;
    bool was_typed(std::string word) const;

    std::string getPrefix() const {
        return prefix;
    };
    int score() const {
        return points;
    };

    int push(std::string word);
    void start();

    int checkPoints(const string &word);
};


#endif //SFML_GAME_ROUND_H
