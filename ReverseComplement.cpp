// This cpp prints out the Complementary DNA strand printed from 5' to 3'

#include <iostream>
#include <string>

using namespace std ;
long long i , t ;
string text ;

char s , a ;
int main ()
{
    // Enter text between "" as max input is 4094 chars
    text = "AAGG";
    t = text.length();
    cout << t << endl << endl;
    char * a;
    a = new char [t]; 

    for (i = 0 ; i < t ; i++ )
    {
        s = text[i];
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

    for (i = t-1 ; i >= 0 ; i--)
    {
        cout << a[i];
    }
}