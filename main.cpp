#include <iostream>
#include <string>
using namespace std;

int main()
{
    string secret_word = "MELANCIA";
    cout << secret_word << endl;

    bool hanged = false;
    bool win = false;

    while(!hanged && !win)
    {
        char guess;
        cin >> guess;

        cout << "Your guess was " << guess << endl;
        
    }

}