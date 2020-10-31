#include <iostream>
#include <vector>
#include <string>

using namespace std;

string Genome;
unsigned long i;
int minvalueofskew = 0;
int maxvalueofskew = 0;


vector <int> skew(10000) ;
vector <int> minposofskew(10000) ;
vector <int> maxposofskew (10000);

vector <int>
MinSkewFinder(string Genome)
{
    int valueofskew=0 , j=0 , k=0 ;

    for (i=0;i<Genome.length()+1;i++)
    {
        char a = Genome[i];
        switch (a)
        {
            case 'C':
            valueofskew--;
            break;
            
            case 'G':
            valueofskew++;
            break;

        }
        skew[i] = valueofskew;
        if (valueofskew >= maxvalueofskew)
        {
            maxvalueofskew = skew[i];
        }
         if (skew[i] <= minvalueofskew)
        {
            minvalueofskew = skew[i];
        }
    } 

    for (i = 0 ; i<Genome.length() ; i++)
    {
        if (skew [i]== maxvalueofskew)
        {
            maxposofskew[k] = i+1;
            k++;
        }
        if (skew[i] == minvalueofskew)
        {
            minposofskew[j] = i+1;
            j++;
        }
    }
    for (i=0 ; i<10000;i++)
    {
        if (minposofskew[i]==0)
        {
            break;
        }
        cout << minposofskew[i] << "  ";
    }
     for (i=0 ; i<10000;i++)
    {
        if (maxposofskew[i]==0)
        {
            break;
        }
        cout << maxposofskew[i] << "  ";
    }
    
    return minposofskew;
}

int main ()
{
    cin >> Genome;
        int valueofskew=0 , j=0 , k=0 ;

    for (i=0;i<Genome.length()+1;i++)
    {
        char a = Genome[i];
        switch (a)
        {
            case 'C':
            valueofskew--;
            break;
            
            case 'G':
            valueofskew++;
            break;

        }
        skew[i] = valueofskew;
        if (valueofskew >= maxvalueofskew)
        {
            maxvalueofskew = skew[i];
        }
         if (skew[i] <= minvalueofskew)
        {
            minvalueofskew = skew[i];
        }
    } 

    for (i = 0 ; i<Genome.length() ; i++)
    {
        if (skew [i]== maxvalueofskew)
        {
            maxposofskew[k] = i+1;
            k++;
        }
        if (skew[i] == minvalueofskew)
        {
            minposofskew[j] = i+1;
            j++;
        }
    }
    for (i=0 ; i<10000;i++)
    {
        if (minposofskew[i]==0)
        {
            break;
        }
        cout << minposofskew[i] << "  ";
    }
    
    
    
}