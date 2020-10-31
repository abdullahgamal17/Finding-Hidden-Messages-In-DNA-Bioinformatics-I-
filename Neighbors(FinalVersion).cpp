#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

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



int main ()
{
    string pattern;
    int d ;
    cin >> pattern >> d ;
    vector <string> a = Neighbors(pattern , d);
    for (int i = 0 ; i< a.size() ; i++)
    {
        cout << a[i] << "  ";
    }
}

//TESTED AND APPROVED
