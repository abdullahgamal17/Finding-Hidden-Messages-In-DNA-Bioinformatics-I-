/*Second function in the course
Using this pseudocode :
FASTERFREQUENTWORDS(Text , k) FrequentPatterns an empty set FREQUENCYARRAY COMPUTINGFREQUENCIES(Text,k) maxCount maximal value in FREQUENCYARRAY for i 0 to 4 k1 if FREQUENCYARRAY(i)=maxCount Pattern NUMBERTOPATTERN(i,k) add Pattern to the set FrequentPatterns return FrequentPatterns

Found in page 39 in the textbook of the course 
Written by Abdullah Gamal 
Faculty of Computer Science and Artificial Intelligence (Bioinformatics Department)
Date of Creation : 4/9/2020 DD/MM/YYYY
10:32 AM
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

char
NumberToSymbol(int a)
    {
        char value = 'L';
        switch(a)
        {
            case 0 :
            value = 'A' ;
            break;
            case 1 :
            value = 'C' ;
            break;
            case 2 :
            value = 'G' ;
            break;
            case 3 :
            value = 'T' ;
            break;
        }
        return value ;
    }

int 
SymbolToNumber(char a)
    {
        int value = -1 ;
        switch(a)
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
        return value ;
    }    
 
unsigned int 
PatternToNumber(string Pattern)
   {
       char symbol = Pattern[Pattern.length()-1];
       string prefix = "";
       for  (int i=0;i<Pattern.length()-2;i++)
       {
           prefix += Pattern[i];
       }
       return 4 * PatternToNumber(prefix) + SymbolToNumber(symbol);
   }
   
vector <int> 
ComputingFrequencies(string text , int k)
{
    vector <int> FrequencyVector ;

    for (int i = 0 ; i< text.length() ; i++)
    {
        string Pattern = text.substr(i,k);
        int j = PatternToNumber(Pattern);
        FrequencyVector[j]++;
    }
    return FrequencyVector ; 
}

string 
NumberToPattern(unsigned long index , unsigned long k)
{
    if (k = 1)
    {
         cout << NumberToSymbol(index);
    }
     unsigned int prefixindex = index/4;
     unsigned int r = index % 4;
     char symbol = NumberToSymbol(r);
     string PrefixPattern = NumberToPattern(prefixindex,k-1);

     return PrefixPattern;
}

vector <string> 
FasterFrequentWords(string text , int k)
{
    string Pattern ;
    vector <string> FrequentPatterns;
    vector <int> FrequencyVector = ComputingFrequencies(text,k);
    int maxCount = *max_element(FrequencyVector.begin(),FrequencyVector.end());

    for (int i = 0 ; i < pow(4,k)-1;i++)
    {
        if (FrequencyVector[i]==maxCount)
        {
            Pattern = NumberToPattern(i,k);
            FrequentPatterns.push_back(Pattern);
        }
    }
    return FrequentPatterns ;
}

int main ()
{
    
}