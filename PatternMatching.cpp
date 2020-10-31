// This cpp prints out all the indices of a certain substring in a larger string

#include <iostream>
#include <string>

unsigned long found , i;
using namespace std ;

string str , tofind , s , original;

void printIndex(string str, string s) 
{ 
  
    bool flag = false; 
    for (int i = 0; i < str.length(); i++) { 
        if (str.substr(i, s.length()) == s) { 
            cout << i << " "; 
            flag = true; 
        } 
    } 
  
    if (flag == false) 
        cout << "NONE"; 
} 
int main ()
{
    
    cin >> tofind  ;

    // enter string needed to be checked on 
   str = "" ;
    printIndex(str , tofind);
    
}
