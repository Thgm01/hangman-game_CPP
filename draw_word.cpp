#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "read_file.hpp"

extern std::string secret_word;

void draw_word()
{
    std::vector<std::string> words = read_file();

    srand(time(NULL));
    int rand_number = rand() % words.size();

    secret_word = words[rand_number];

}