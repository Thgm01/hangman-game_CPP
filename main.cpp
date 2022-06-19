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
    print_header();

    while(!hanged() && !win())
    {
        print_wrong_guesses();

        print_secret_word();

        guess();

    }

    cout << "End game!\n";
    cout << "The Secret Word was " << SECRET_WORD << "!\n";
    if(!win())
    {
        cout << "You lost! Try again!\n";
    }
    else 
    {
        cout << "Congratulations! You got right the Secret Word!\n";
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

bool win()
{
    for(char letter : SECRET_WORD)
    {
        if(!tried[letter]) return false;
    }
    return true;
}

bool hanged()
{
    return wrong_guesses.size() > 5;
}

void print_header()
{
    cout << "***************************************\n";
    cout << "***   Welcome to the Hangman Game   ***\n";
    cout << "***************************************\n\n";
}

void print_wrong_guesses()
{
    cout << "Wrong guesses: ";
    for(char letter : wrong_guesses)
    {
        cout << letter << " ";
    }
    cout << endl;
}

void print_secret_word()
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
    cout << endl;
}

void guess()
{
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