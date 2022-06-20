#include <iostream>
#include <map>
#include <string>

extern std::string secret_word;
extern std::map<char, bool> tried;

void print_secret_word()
{
    for(char letter : secret_word)
    {
        if(tried[letter])
        {
            std::cout << letter << " ";
        }else
        {
            std::cout << "_ ";
        }            
    }
    std::cout << std::endl;
}