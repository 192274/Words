//
// Created by w on 2/25/18.
//

#include <fstream>
#include <algorithm>
#include <iostream>
#include "Dictionary.h"

Dictionary::Dictionary(std::string file = "/home/w/Workplace/DictionaryAnalysis/words_alpha.txt") : prefixes(0), words(0){
    file_name = file;
    loadWords();
    loadPrefixes();
}

Dictionary::Dictionary(std::string file_name, std::string language): Dictionary(file_name) {
    this->language = language;
}

bool Dictionary::contains(string word) const {
    for(int i = 0; i < words.size() && words[i] <= word; ++i)
        if(word == words.at(i)) return true;
    return false;
}

int Dictionary::loadWords() {
    ifstream ifs(file_name.c_str());
    std::string temp;
    while(ifs >> temp)
        words.push_back(temp);
    ifs.close();
    std::sort(words.begin(), words.end());
}

int Dictionary::loadPrefixes() {
    std::string prefix = "";
    int words_length[7] {0};
    std::string word = "";
    for(int i = 0; i < words.size(); ++i) {
        word = words[i];
        if(word.length() >= 3)
        {
        if(word.substr(0, 3) != prefix) {
            decide_if_add_prefix(prefix, words_length);
            prefix = word.substr(0, 3);
        }
        int wl = word.length();
        if(wl >= 4 && wl <= 10)
            ++(words_length[wl - 4]);}
    }
}

void Dictionary::decide_if_add_prefix(const string &prefix, int *words_length) {
    int j = 6;
    while(j >=0 && words_length[j] >= 3) {
        words_length[j] = 0;
        --j;
    }
    if(j<0)
        prefixes.push_back(prefix);
    else
        while (j >= 0) {
            words_length[j] = 0;
            --j;
        }
}

std::string Dictionary::random_prefix(int length) const {
    srand(time(0));
    if(prefixes.size() > 0)
        return (prefixes.at(rand() % prefixes.size())).substr(0, length);
    return "Brak akceptowalnych prefiksów";
}



