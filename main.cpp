#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
// #include "main.hpp"
#include "header_print.hpp"
#include "draw_word.hpp"
#include "hanged.hpp"
#include "win.hpp"
#include "print_wrong_guesses.hpp"
#include "print_secret_word.hpp"
#include "guess.hpp"
#include "add_new_word.hpp"
//#include "have_letter.hpp"
//#include "read_file.hpp"
//#include "save_file.hpp"


using namespace std;
string secret_word;
map<char, bool> tried;
vector<char> wrong_guesses;

int main()
{
    header_print();

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

        cout << "Do you want to add a new word? (Y/N)\n";
        char answer;
        cin >> answer;
        if(answer == 'Y')
        {
            add_new_word();
        }
    }
}
