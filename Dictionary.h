//
// Created by w on 2/25/18.
//

#ifndef SFML_GAME_DICTIONARY_H
#define SFML_GAME_DICTIONARY_H

#include <string>
#include <vector>

using namespace std;

class Dictionary {

private:
public:
    string language;
    string file_name;
    std::vector<std::string> words;
    std::vector<std::string> prefixes;

    int loadWords();
    int loadPrefixes();
    void decide_if_add_prefix(const string &prefix, int * words_length);

public:
    explicit Dictionary(std::string file_name = "/home/w/Workplace/DictionaryAnalysis/words_alpha.txt");
    Dictionary(std::string file_name, std::string language);
    bool remove(string);
    bool contains(string) const ;
    std::string random_prefix(int length) const ;


};


#endif //SFML_GAME_DICTIONARY_H
