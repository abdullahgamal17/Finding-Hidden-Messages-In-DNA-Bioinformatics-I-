#include <iostream>
#include <string>
#include <vector>

using namespace std;
int i , c , j;

int HammingDistance(string p , string q)
{
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

int
ApproximatePatternCount(string text , string pattern , int d)
{
    
    int patternlength = pattern.length();
    int textlength = text.length();
   
    for (i = 0 ; i<= textlength-patternlength;i++)
    {
        int counter1 = HammingDistance(pattern , text.substr(i,patternlength)); 
        if (counter1 <= d)
        {
            c++;
        }
    }
    return c ;
}


int main ()
{
    string pattern , text ;
    int d , output;
    
    cin >> text >>pattern  >> d ;
    output = ApproximatePatternCount(text , pattern , d);
    cout << output;
}