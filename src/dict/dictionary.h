#include <set>
#include <string>
#include <vector>

#ifndef UNTITLED_DICT_H
#define UNTITLED_DICT_H

class Dictionary {
public:
    explicit Dictionary(std::string const& file_path);
    bool contains(std::string word);

private:
    std::set<std::string> dict;
};

#endif //UNTITLED_DICT_H
