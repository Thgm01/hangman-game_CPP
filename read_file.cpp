#include <iostream>
#include <fstream>
#include "read_file.hpp"

extern std::vector<std::string> read_file()
{
    std::ifstream file;
    file.open("words.txt");

    if(file.is_open())
    {

        int number_of_words;
        file >> number_of_words;

        std::vector<std::string> words;

        for(int i=0; i<number_of_words; i++)
        {
            std::string read_word;
            file >> read_word;
            words.push_back(read_word);
        }

        file.close();
        return words;
    }
    else
    {
        std::cout << "Erro! File can not be open\n";
        exit(0);
    }
}