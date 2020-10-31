#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

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
    char symbol = Pattern[Pattern.length()-1];
    string prefix = Pattern.substr(0,Pattern.length()-1);

    return 4*PatternToNumber(prefix) + SymbolToNumber(symbol);
}

vector <string> 
FindingFrequentWordsBySortng(string text , int k)
{
    int maxCount;
    string Pattern;
    vector <string> FrequentPatterns;
    vector <int> Index ;
    vector <int> Count ;
    for (int i = 0; i<=text.length()-k ; i++)
    {
        Pattern = text.substr(i,k);
        Index.push_back(PatternToNumber(Pattern));
        Count.push_back(1);
    }
    vector <int> SortedIndex = Index; 
    sort(SortedIndex.begin(),SortedIndex.end());

    for (int i = 1 ; i<=text.length()-k ; i++)
    {
        if(SortedIndex[i]==SortedIndex[i-1])
        {
            Count[i]=Count[i-1] + 1;
        }
         maxCount = *max_element(Count.begin(),Count.end());
        }
    for (int i = 0 ; i <= text.length()-k ; i++)
    {
        if(Count[i] == maxCount )
        {
           string Pattern = NumberToPattern(SortedIndex[i],k);
            FrequentPatterns.push_back(Pattern);
        }
    }
    cout << "MAX COUNT IS " << maxCount<<endl; 
     return FrequentPatterns;
}

int main ()
{
    string text ;
    int k ;
    cin >> text >> k;
    vector <string> FrequentPatterns = FindingFrequentWordsBySortng(text,k);
    cout << "Most Frequent Pattern(s) : ";
    for ( int i = 0 ; i< FrequentPatterns.size(); i++)
    {
        cout << FrequentPatterns[i] << "  ";
    }
}

//TESTED AND PROVED