#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "dictionary.h"

Dictionary::Dictionary(std::string const& file_path) {
    std::ifstream input (file_path);
    for (std::string line; std::getline(input, line); ) {
        dict.insert(line);
    }
}

bool Dictionary::contains(std::string word) {
    for (int i = 0; i < word.size(); i++) {
        word[i] = toupper(word[i]);
    }

    return dict.count(word);
}
