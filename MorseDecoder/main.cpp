#include <iostream>
#include <string.h>
using namespace std;

class MorseDecoder
{
private:
    char letter;
    MorseDecoder *dash, *dot;
    MorseDecoder(char letter)
    {
        this->letter = letter;
    }
    char decode_letter(string const morse) const;
    MorseDecoder *getDash()
    {
        return dash;
    }
    MorseDecoder *getDot()
    {
        return dot;
    }

public:
    MorseDecoder();
    string decode(string const morse) const
    {

        if(morse=="")
            return;
        
        if(morse[0]=='.')
            mors.dash->

    }
};