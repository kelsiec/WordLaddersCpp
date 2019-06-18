#include <iostream>
#include <string>

#include "search/bfs_search.h"
#include "search/dfs_search.h"

int main() {
    BFSSearch bfs_search("../data/words.txt");
    std::list<std::string> path = bfs_search.find_path("HEAD", "TAIL");

    for (std::string const& element : path) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    DFSSearch dfs_search("../data/words.txt");
    path = dfs_search.find_path("HEAD", "TAIL");

    for (std::string const& element : path) {
        std::cout << element << " ";
    }

    return 0;
}