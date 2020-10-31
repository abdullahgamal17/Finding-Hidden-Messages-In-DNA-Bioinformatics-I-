/* First Function in charging station
Computing Frequencies using this pseudocode :
COMPUTINGFREQUENCIES(Text, k) for i 0 to 4 k1 FREQUENCYARRAY(i) 0 for i 0 to|Text|k Pattern Text(i,k) j PATTERNTONUMBER(Pattern) FREQUENCYARRAY(j) FREQUENCYARRAY(j)+1 return FREQUENCYARRAY
Found in page 39 of the course textbook

Written by : Abdullah Gamal 
Faculty of Computer Science and Artificial Intelligence (Bioinformatics Department)
Date of Creation : 4/9/2020 DD/MM/YYYY
10;00 AM
*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath> 
using namespace std ;
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


 vector <int> 
 ComputingFrequencies(string text , int k)
{
    int size = pow(4,k);
    vector <int> FrequencyVector(size,0) ;

    for (int i = 0 ; i<= text.length()-k ; i++)
    {
        string Pattern = text.substr(i,k);
        int j = PatternToNumber(Pattern);
        FrequencyVector[j]++;
        
    }
    return FrequencyVector ; 
}

int main ()
{
    vector <int> a = ComputingFrequencies("ACGCGGCTCTGAAA",2);
}