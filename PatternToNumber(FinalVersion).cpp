#include <iostream>
#include <string>
#include <vector>

using namespace std;

unsigned short 
SymbolToNumber(char symbol)
{
    int value;
    switch (symbol)
    {
        case 'A':
        value = 0;
        break;

         case 'C':
        value = 1;
        break;

         case 'G':
        value = 2;
        break;

         case 'T':
        value = 3;
        break;
    }
    return value;
} 

unsigned int
PatternToNumber(string Pattern)
{
    if (Pattern.empty())
    {
        return 0 ;
    }
    char symbol = Pattern.back();
    string prefix = Pattern.substr(0,Pattern.length()-1);
    return 4*PatternToNumber(prefix) + SymbolToNumber(symbol);
}


int main ()
{
    string Pattern;
    cout << "Enter Pattern : ";
    
    
    cin >> Pattern;
    cout << PatternToNumber(Pattern) << "\n";
}

//TESTED AND VERIFIED