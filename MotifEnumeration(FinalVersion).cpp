#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

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

char NumberToSymbol(int a)
{
    char value = 'n';

    switch(a)
    {
        case 0 :
        value = 'A';
        break;

         case 1 :
        value = 'C';
        break;

         case 2:
        value = 'G';
        break;

         case 3 :
        value = 'T';
        break;

        default :
        value = 'r';
    }
    return value ;
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
}

string NumberToSymbol1(int a)
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
        return NumberToSymbol1(index) ;
    }
    string PrefixPattern;
    unsigned int prefixIndex = index/4;
    int r = index%4;
    string symbol = NumberToSymbol1(r);
    
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
MotifEnumeration(vector <string> DNA , int k , int d)
{
    vector <string> Patterns;
    vector <string> FirstNeighborhood;
    vector <int> FirstNeighborhoodNumbers;
    vector <int> check;
    
    //This loop iterates over the first string DNA and creates FirstNeighborhood 
    for (int i = 0 ; i<=DNA[0].length()-k ; i++)
    {
        string pattern = DNA[0].substr(i,k);
        vector <string> tempNeighborhood;
        tempNeighborhood = Neighbors(pattern,d);
        //this loop generates the neighborhood of each kmer in the pattern and creates FirstNeighborhood
        for(int j = 0 ; j < tempNeighborhood.size() ; j++)
        {
            FirstNeighborhood.push_back(tempNeighborhood[j]);
        }
    }
    //this loop creates pattern order lexographically
    for(int i = 0 ; i < FirstNeighborhood.size() ; i++)
    {
        unsigned int NumberPattern = PatternToNumber(FirstNeighborhood[i]);
        FirstNeighborhoodNumbers.push_back(NumberPattern);       
    }
    //Sorts The lexographical patterns
    sort(FirstNeighborhoodNumbers.begin(),FirstNeighborhoodNumbers.end());
    for (int i = 0 ; i<pow(4,k);i++)
    {
        check.push_back(0);
    }
    //marks the place of occurences
    for(int i = 0 ; i < FirstNeighborhoodNumbers.size(); i++)
    {
        check[FirstNeighborhoodNumbers[i]] = 1;
        check.shrink_to_fit();
    }
    //----------------------------------------------------------------------------------------------------------------
    for (int counter = 1 ; counter < DNA.size() ; counter++)
    {
       vector <string> Neighborhood1 , tempNeighborhood1;
       vector <int> check2;
       vector <int> NeighborhoodNumbers1;

       for (int i = 0 ; i<=DNA[counter].length()-k ; i++)
        {
        string pattern = DNA[counter].substr(i,k);
        vector <string> tempNeighborhood1;
        tempNeighborhood1 = Neighbors(pattern,d);
        //this loop generates the neighborhood of each kmer in the pattern and creates FirstNeighborhood
            for(int j = 0 ; j < tempNeighborhood1.size() ; j++)
            {
                Neighborhood1.push_back(tempNeighborhood1[j]);
            }
        }
        //this loop creates pattern order lexographically
        for(int i = 0 ; i < Neighborhood1.size() ; i++)
        {
            unsigned int NumberPattern1 = PatternToNumber(Neighborhood1[i]);
            NeighborhoodNumbers1.push_back(NumberPattern1);       
        }
        //Sorts The lexographical patterns
        sort(NeighborhoodNumbers1.begin(),NeighborhoodNumbers1.end());
        for (int i = 0 ; i<pow(4,k);i++)
        {
            check2.push_back(0);
        }
        //marks the place of occurences
        for(int i = 0 ; i < NeighborhoodNumbers1.size(); i++)
        {
            check2[NeighborhoodNumbers1[i]] = 1;
            check2.shrink_to_fit();
        }
        for (int i = 0 ; i< check.size(); i++)
        {
            if(check2[i] == 1)
            {
                check[i]= check[i]+1;
            }
        }
    }
    for (int i = 0 ; i < check.size() ; i++ )
    {
        if (check[i] == DNA.size())
        {
            Patterns.push_back(NumberToPattern(i,k));
        }
    } 
    return Patterns;
}   


int main()
{
    string DNA;
    vector <string> DNAVEC ;
    vector <string> Patterns;
    unsigned int sizeofDNA , k ,d;
    cin >> sizeofDNA;
    for (int i = 0 ; i<sizeofDNA ;i++)
    {
        cout << "Enter DNA string : ";
         cin >> DNA;
         DNAVEC.push_back(DNA);
    }
    cout << "Enter K : ";
    cin >> k ;
    cout << "Enter D : ";
    cin >> d;
    Patterns = MotifEnumeration(DNAVEC,k,d);

    for (int i = 0 ; i<Patterns.size() ; i++)
    {
        cout << Patterns[i] << "  "; 
    }
}

// TESTED AND APPROVED
