#include <iostream>
#include <string>

#include "main.hpp"

using namespace std;

const string SECRET_WORD = "MELANCIA";

int main()
{
    cout << SECRET_WORD << endl;

    bool hanged = false;
    bool win = false;

    while(!hanged && !win)
    {
        char guess;
        cin >> guess;

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