#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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

    for (unsigned long i = t-1 ; i >= 0 ; --i)
    {
        complementarystrand = complementarystrand + a[i];
    }
    complementarystrand = complementarystrand + a[0];
    
    return complementarystrand;
}

int main ()
{

}