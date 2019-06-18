#include <iostream>

#include "search.h"

Search::Search(std::string const& file_path) : dict(file_path) {}

std::vector<std::string> Search::get_valid_changes(std::string const& word) {
    std::vector <std::string> changes;
    for (int i = 0; i < word.size(); i++) {
        for (char letter = 'A'; letter <= 'Z'; letter++) {
            std::string possible_word = word;
            possible_word[i] = letter;
            if (dict.contains(possible_word)) {
                changes.push_back(possible_word);
            }

        }
    }

    return changes;
}

bool Search::is_duplicate(std::string const& word) {
    return seen.count(word);
}

void Search::try_word(std::string const& word) {
    seen.insert(word);
}


void Search::add_relationship(std::string const& child, std::string const& parent) {
    relations.insert({child, parent});
}

std::list<std::string> Search::build_path(std::string const& start, std::string const& goal) {
    std::list<std::string> path;
    std::string current = goal;
    while (current != start) {
        path.push_back(current);
        current = relations.at(current);
    }

    path.push_back(current);
    path.reverse();

    return path;
}