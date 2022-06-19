#include <iostream>
#include <string>
#include <map>

#include "main.hpp"

using namespace std;

const string SECRET_WORD = "MELANCIA";
map<char, bool> tried;

int main()
{
    bool hanged = false;
    bool win = false;

    while(!hanged && !win)
    {
        for(char letter : SECRET_WORD)
        {
            if(tried[letter])
            {
                cout << letter << " ";
            }else
            {
                cout << "_ ";
            }
            
        }

        char guess;
        cin >> guess;

        tried[guess] = true;

        if(have_letter(guess))
        {
            cout << "The letter " << guess << " was in the secret word\n";
        }else
        {
            cout << "The letter " << guess << " wasn't in the secret word\n";
        }
    }
}

bool have_letter(char guess)
{
    for(char letter : SECRET_WORD)
    {
        if(guess == letter)
        {
            return true;
        }
    }
    return false;
}