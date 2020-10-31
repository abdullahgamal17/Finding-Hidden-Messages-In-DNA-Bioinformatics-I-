#include <iostream>
#include <string>
#include <vector>

using namespace std;
int i;
string p , q;

int HammingDistance(string p , string q)
{
    int counter = 0;
    
    {
        for (i = 0 ; i<p.length();i++)
        {
            if(p[i] != q[i]) 
            {
                counter++;
            }
        }
    }
    return counter;
}

int main()
{
    cin >> p >> q;
    cout << HammingDistance(p,q);
    
}

//TESTED AND PROVED
    
