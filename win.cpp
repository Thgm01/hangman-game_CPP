#include <map>
#include <string>

extern std::string secret_word;
extern std::map<char, bool> tried;

bool win()
{
    for(char letter : secret_word)
    {
        if(!tried[letter]) return false;
    }
    return true;
}