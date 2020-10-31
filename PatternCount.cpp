// This cpp finds how many a substring is repeated in bigger string 

#include <iostream>
#include <string>
using namespace std ;
int i;
string sub , test;
long c = 0;

int main()
{
    cin >> sub >> test;
      for (i=0 ; i < sub.length() ; i++)
    {
        if (test.compare(sub.substr(i,test.length()))==0)
        {
            c++;
        }
    }
    cout<< c ;
}