#include <iostream>
#include <vector>
#include <string>
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



int d(string Pattern , string Text)
{
    int min = 100000;
    for (int i = 0 ; i < Text.length() ; i++)
    {
        string Pattern2 = Text.substr(i,Pattern.length());
        if(min > HammingDistance(Pattern,Pattern2))
        {
            min = HammingDistance(Pattern, Pattern2);
        }
    }
    return min;
}

int d(string Pattern , vector <string> DNA)
{
    int SumOfD = 0;
    
    for (int i = 0 ;  i < DNA.size() ;i++)
    {
        int min = 100000;
        for (int j = 0 ; j < DNA[i].length() - Pattern.length() ; j++)
        {
            string Pattern2 = DNA[i].substr(j,Pattern.length());
            int distance = d(Pattern,Pattern2);
            if(min > distance )
            {
                min = d(Pattern,Pattern2);
            }
        }
        SumOfD += min;
    }
    return SumOfD;
}

string
NumberToSymbol(int a)
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

string
NumberToPattern(int index , int k)
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


string
MedianString(vector <string> DNA , unsigned int k)
{
    int distance = 1000000;
    string Median;
    for (int i = 0 ; i < pow(4,k) ; i++)
    {
        string Pattern = NumberToPattern(i,k);
        if(distance > d(Pattern , DNA))
        {
            distance = d(Pattern ,DNA);
            Median = Pattern;
        }
    }
    
    return Median;
}

int main ()
{
    vector <string> a;
    int ah;
    cin >> ah;
    for (int i = 0 ; i < 3 ; i++)
    {
        string pattern;
        cin >> pattern;
        a.push_back(pattern);
    }
    cout << MedianString(a,ah);
}

// TO BE TESTED