#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "main.hpp"

using namespace std;

const string SECRET_WORD = "MELANCIA";
map<char, bool> tried;
vector<char> wrong_guesses;

int main()
{
    cout << "***************************************\n";
    cout << "***   Welcome to the Hangman Game   ***\n";
    cout << "***************************************\n\n";

    bool hanged = false;
    bool win = false;

    while(!hanged && !win)
    {
        cout << "Wrong guesses: ";
        for(char letter : wrong_guesses)
        {
            cout << letter << " ";
        }
        cout << endl;


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
        cout << endl;

        char guess;

        cout << "Guess one letter: ";
        cin >> guess;

        tried[guess] = true;

        if(have_letter(guess))
        {
            cout << "The letter " << guess << " was in the secret word\n\n";
        }else
        {
            cout << "The letter " << guess << " wasn't in the secret word\n\n";
            wrong_guesses.push_back(guess);
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