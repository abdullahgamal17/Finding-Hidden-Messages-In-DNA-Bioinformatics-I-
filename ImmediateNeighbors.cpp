#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std ;

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
ImmediateNeighbors(string pattern)
{
    vector <string> Neighborhood;
    

    for (int i = 0 ; i < pattern.length() ; i++ )
    {
        char symbol = pattern[i];
        string temppattern = pattern;
        

        for (int j = 0; j < 4; j++)
        {
            char symbol2 = NumberToSymbol(j);
            if(symbol != symbol2)
            {
                switch(j)
                {
                    case 0 :
                    temppattern[i] = 'A';
                    break;

                    case 1 :
                    temppattern[i] = 'C';
                    break;
                
                    case 2 :
                    temppattern[i] = 'G';
                    break;
                
                    case 3 :
                    temppattern[i] = 'T';
                    break;
                }
                Neighborhood.push_back(temppattern);
            }
        }
    }
    return Neighborhood;
}

int main ()
{
    string pattern;
    cin >> pattern ;
    vector <string> Neighborhood = ImmediateNeighbors(pattern);

    for (int i = 0 ; i<Neighborhood.size() ; i++)
    {
        cout << Neighborhood[i] << "  ";
    }
}

//TESTED AND APPROVED