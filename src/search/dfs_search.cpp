#include <iostream>
#include <stack>

#include "dfs_search.h"

DFSSearch::DFSSearch(std::string const& file_path) : Search(file_path) {}

std::list<std::string> DFSSearch::find_path(std::string start, std::string goal) {
    std::stack<std::string> s;
    s.push(start);

    while (!s.empty()) {
        std::string word = s.top();
        s.pop();

        for (std::string const& option : get_valid_changes(word)) {
            add_relationship(option, word);

            if (option == goal) {
                return build_path(start, goal);
            } else if (!is_duplicate(option)) {
                try_word(option);
                s.push(option);
            }
        }
    }

    return {};
}