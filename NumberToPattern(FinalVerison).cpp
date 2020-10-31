#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
string NumberToSymbol(int a)
{
    string value = "n";

    switch(a)
    {
        case 0 :
        value = "A";
        break;

         case 1 :
        value = "C";
        break;

         case 2:
        value = "G";
        break;

         case 3 :
        value = "T";
        break;

        default :
        value = "r";
    }
    return value ;
}

string NumberToPattern(int index , int k)
{

    if (k == 1 )
    {
        return NumberToSymbol(index) ;
    }
    string PrefixPattern;
    unsigned int prefixIndex = index/4;
    int r = index%4;
    string symbol = NumberToSymbol(r);
    
    PrefixPattern = NumberToPattern(prefixIndex,k-1);
    return PrefixPattern + symbol;
}

int main()
{
    int index , k;
    cout << "Enter the index number : ";
    cin >> index ;
    cout << "Enter k-mer length : ";
    cin >> k; 
    cout << NumberToPattern(index,k);
}

// TESTED AND PROVED
