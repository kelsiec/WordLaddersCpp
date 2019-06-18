#include "search.h"

#ifndef UNTITLED_BFSSEARCH_H
#define UNTITLED_BFSSEARCH_H


class BFSSearch : public Search {
public:
    explicit BFSSearch(std::string const& file_path);
    std::list<std::string> find_path(std::string start, std::string goal) override;
};


#endif //UNTITLED_BFSSEARCH_H
