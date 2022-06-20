#include <string>

extern std::string secret_word;

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