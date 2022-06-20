#include <vector>

extern std::vector<char> wrong_guesses;

bool hanged()
{
    return wrong_guesses.size() > 5;
}