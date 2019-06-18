#include "search.h"


#ifndef UNTITLED_DFS_SEARCH_H
#define UNTITLED_DFS_SEARCH_H


class DFSSearch : public Search {
public:
    explicit DFSSearch(std::string const& file_path);
    std::list<std::string> find_path(std::string start, std::string goal) override;
};


#endif //UNTITLED_DFS_SEARCH_H
