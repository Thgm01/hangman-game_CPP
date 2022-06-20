#include <iostream>
#include <string>
#include <vector>
#include "read_file.hpp"
#include "save_file.hpp"


void add_new_word()
{
    std::cout << "Type the new word in capital letters: ";
    std::string new_word;
    std::cin >> new_word;

    std::vector<std::string> words = read_file();
    words.push_back(new_word);

    save_file(words);
}