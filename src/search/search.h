#include <list>
#include <map>
#include <string>

#include "../dict/dictionary.h"

#ifndef UNTITLED_SEARCH_H
#define UNTITLED_SEARCH_H


class Search {
public:
    explicit Search(std::string const& file_path);
    virtual std::list<std::string> find_path(std::string start, std::string goal) =0;
    std::vector<std::string> get_valid_changes(std::string const& word);

protected:
    bool is_duplicate(std::string const& word);
    void try_word(std::string const& word);
    void add_relationship(std::string const& child, std::string const& parent);
    std::list<std::string> build_path(std::string const& start, std::string const& goal);

private:
    Dictionary dict;
    std::map<std::string, std::string> relations;
    std::set<std::string> seen;
};


#endif //UNTITLED_SEARCH_H
