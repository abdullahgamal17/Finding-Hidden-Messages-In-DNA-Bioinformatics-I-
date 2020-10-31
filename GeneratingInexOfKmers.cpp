#include <iostream>
#include <vector>
#include <string>

using namespace std;

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


vector <int>
GeneratingIndexOfKmersNumbers(unsigned int k)
{
    vector <int> PossibleNumberOfKmers;
 for (unsigned int i = 0 ;i<pow(4,k); i++ )
    {
        PossibleNumberOfKmers.push_back(i);
        
    }
    return PossibleNumberOfKmers;
}
vector <string>
GenerateCombinationsOfKmers(unsigned int k)
{
    vector <string> PossibleKmerCombinations;
    for (unsigned int i = 0 ;i<pow(4,k); i++ )
    {
    PossibleKmerCombinations.push_back(NumberToPattern(i,k));
     }
    return PossibleKmerCombinations ;
}

int main ()
{

}