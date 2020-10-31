#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int HammingDistance(string p , string q)
{
    int counter = 0;
    
    {
        for (int i = 0 ; i<p.length();i++)
        {
            if(p[i] != q[i]) 
            {
                counter++;
            }
        }
    }
    return counter;
}

string
Suffix(string pattern)
{
    string suffix;
    for (int i =1 ; i<pattern.length() ; i++)
    {
        suffix = suffix + pattern[i];
    }
    return suffix;
}

vector <string>
Neighbors(string pattern , int d)
{
    
    if (d == 0 )
    {
        return {pattern};
    }
    if (pattern.length() == 1)
    {
        return {"A","C","G","T"};
    }

    vector <string> Neighbourhood;

    vector <string> SuffixNeighbors;

    SuffixNeighbors= Neighbors(Suffix(pattern),d) ;

    for (int i = 0 ; i<SuffixNeighbors.size(); i++)
    {
        if (HammingDistance(Suffix(pattern),SuffixNeighbors[i]) < d)
        {
            string value;
            for (int j = 0 ; j < 4 ; j++)
            {
                switch (j)
                {
                    case 0 :
                    value= "A";
                    break;

                    case 1 :
                    value= "C";
                    break;

                    case 2 :
                    value= "G";
                    break;

                    case 3 :
                    value= "T";
                        
                }
                Neighbourhood.push_back(value+SuffixNeighbors[i]);
                
            }
            
        }
        else
        {
            Neighbourhood.push_back(pattern[0] + SuffixNeighbors[i]);
        }
        
    } 
    return Neighbourhood;
}unsigned short 
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

int
ApproximatePatternCount(string text , string pattern , int d)
{
    
    int patternlength = pattern.length();
    int textlength = text.length();
    int c = 0;
    for (int i = 0 ; i<= textlength-patternlength;i++)
    {
        int counter1 = HammingDistance(pattern , text.substr(i,patternlength)); 
        if (counter1 <= d)
        {
            c++;
        }
    }
    return c ;
}


vector <string> 
FrequentWordsWithMismatches(string text , int k , int d)
{
    vector <string> FrequentPatterns;
    vector <int> Close;
    vector <int> FrequencyVector;
    vector <string> Neighbourhood;
    int index = 0 ;
    
    for ( int i =0; i < pow(4,k);i++)
    {
        Close.push_back(0);
        FrequencyVector.push_back(0);
    }
    for(int i = 0; i<=text.length()-k;i++)
    {   string ithpattern = text.substr(i,k);
        Neighbourhood = Neighbors(ithpattern,d);
        string PartOfNeighbourhood;
        for(int j = 0 ; j< Neighbourhood.size();j++)
        {
            PartOfNeighbourhood = Neighbourhood[j] ;
            index = PatternToNumber(PartOfNeighbourhood);
            Close[index]=1;
        }

    }
    for(int i = 0 ; i< pow(4,k); i++)
    {
        if(Close[i]==1)
        {
            string pattern = NumberToPattern(i,k);
            FrequencyVector[i] = ApproximatePatternCount(text , pattern , d);
        }
    }
    int maxCount = *max_element(FrequencyVector.begin(),FrequencyVector.end());
    for (int i = 0 ; i< pow(4,k);i++)
    {
        if (FrequencyVector[i]==maxCount && maxCount > 0)
        {
            string Pattern = NumberToPattern(i,k);
            FrequentPatterns.push_back(Pattern);
        }
    }
    return FrequentPatterns;
}

int main ()
{
    vector <string> FrequentPatterns;
    string text;
    int k,d;
    
    cin >>text >> k >>d;

    FrequentPatterns = FrequentWordsWithMismatches(text,k,d);
    
    for (int i = 0 ; i< FrequentPatterns.size();i++ )
    {
        cout << FrequentPatterns[i] << "  ";
    }
    
}

// Tested And Approved