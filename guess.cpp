#include <iostream>
#include <map>
#include <vector>
#include "have_letter.hpp"

extern std::map<char, bool> tried;
extern std::vector<char> wrong_guesses;

void guess()
{
    char guess;

    std::cout << "Guess one letter: ";
    std::cin >> guess;

    tried[guess] = true;

    if(have_letter(guess))
    {
        std::cout << "The letter " << guess << " was in the secret word\n\n";
    }else
    {
        std::cout << "The letter " << guess << " wasn't in the secret word\n\n";
        wrong_guesses.push_back(guess);
    }
}