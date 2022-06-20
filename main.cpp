#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "main.hpp"

using namespace std;
string secret_word;
map<char, bool> tried;
vector<char> wrong_guesses;

vector<string> read_file()
{
    ifstream file;
    file.open("words.txt");

    if(file.is_open())
    {

        int number_of_words;
        file >> number_of_words;

        vector<string> words;

        for(int i=0; i<number_of_words; i++)
        {
            string read_word;
            file >> read_word;
            words.push_back(read_word);
        }

        file.close();
        return words;
    }
    else
    {
        cout << "Erro! File can not be open\n";
        exit(0);
    }
}

int main()
{
    print_header();

    draw_word();

    while(!hanged() && !win())
    {
        print_wrong_guesses();

        print_secret_word();

        guess();

    }

    cout << "End game!\n";
    cout << "The Secret Word was " << secret_word << "!\n";
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
    for(char letter : secret_word)
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
    for(char letter : secret_word)
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
    for(char letter : secret_word)
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



void draw_word()
{
    vector<string> words = read_file();

    srand(time(NULL));
    int rand_number = rand() % words.size();

    secret_word = words[rand_number];

}