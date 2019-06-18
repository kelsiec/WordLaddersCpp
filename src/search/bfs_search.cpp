#include <iostream>
#include <queue>

#include "bfs_search.h"

BFSSearch::BFSSearch(std::string const& file_path) : Search(file_path) {}

std::list<std::string> BFSSearch::find_path(std::string start, std::string goal) {
    std::queue<std::string> q;
    q.push(start);

    while (!q.empty()) {
        std::string word = q.front();
        q.pop();

        for (std::string const& option : get_valid_changes(word)) {
            add_relationship(option, word);

            if (option == goal) {
                return build_path(start, goal);
            } else if (!is_duplicate(option)) {
                try_word(option);
                q.push(option);
            }
        }
    }

    return {};
}