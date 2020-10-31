#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

string
ProduceComplementary(string b)
{
    string complementarystrand = "";

    string text = b;
    unsigned long t = text.length();
    char *a;
    a = new char [t]; 

    for (unsigned long i = 0 ; i < t ; i++ )
    {
        char s = text[i];
        switch(s)
        {
            case 'A' :
            a[i] = 'T';
            break;

            case 'T' :
            a[i] = 'A';
            break;

            case 'G' :
            a[i] = 'C';
            break;

            case 'C' :
            a[i] = 'G';
            break;

        }
    }

    for (unsigned long i = t-1 ; i > 0 ; --i)
    {
        complementarystrand = complementarystrand + a[i];
    }
    complementarystrand = complementarystrand + a[0];
    
    return complementarystrand;
}

int HammingDistance(string p , string q)
{
    int j ;
    int counter = 0;
    {

        for (j = 0 ; j < p.length();j++)
        {
            if(p[j] != q[j]) 
            {
                counter++;
            }
        }
   
    }
    return counter;
}

//PatterToNumberFunction
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

//NumberToPattern
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
    int c = 0 ;
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
MakeCountVector(string text , int k, int d)
{
    vector <int> SumOfTwoCounts;
    vector <int> IndexOfMax;
    vector <string> PatternMax;


   

    
    //Loop Through The Whole String
    for (int i = 0 ; i< text.length()-k; i++)
    {
    //Creating Pattern and its complementary in all k mer in the string
    string pattern = text.substr(i,k);
    string comppattern=ProduceComplementary(pattern);

    //Calculating Hamming Distance For The Pattern and its Complementary against the kmer we are on
    int d_of_pattern = HammingDistance(pattern , text.substr(i,k));
    int d_of_comppattern = HammingDistance(comppattern,text.substr(i,k));

    //Calculating count of pattern and its complementary and storing it in SumOfTwoCounts vector
    int Countofpattern = ApproximatePatternCount(text ,pattern,d_of_pattern);
    int Countofcomppattern = ApproximatePatternCount(text , comppattern , d_of_comppattern);

    SumOfTwoCounts.push_back(Countofpattern+Countofcomppattern);
    }

    // Finds maxCount 
    int MaxCount = *max_element(SumOfTwoCounts.begin(),SumOfTwoCounts.end());

    // Make Two Vectors One Containing MAX indeces and one containg the kmers found at those indeces
    for (int i = 0 ; i < SumOfTwoCounts.size() ; i++)
    {
        if (SumOfTwoCounts[i]==MaxCount)
        {
            IndexOfMax.push_back(i);
            PatternMax.push_back(text.substr(i,k));
        }
    }
   return PatternMax; 
}

int main()
{
    vector <string> VectorCount;
    string text;
    int k , d ;
    cin >> text >> k >> d ;
    VectorCount = MakeCountVector(text ,k ,d);
    
    for (int i = 0 ; i< VectorCount.size();i++)
    {
        cout << VectorCount[i] << "  " << ProduceComplementary(VectorCount[i])<<endl;
    }
}