#include <vector>
#include<string>
#include <iostream>
#include <algorithm>
using namespace std;

vector <string>
ClumpFinding(string genome , int k , int l, int t)
{
    vector <string> EndResult;
    string TestedKmer;
    for(int i = 0 ; i < genome.length()- l ; i++) // Creates Window
    {
        string SearchWindow = genome.substr(i,l);
        int count;
        for (int j = 0; j < l - k; j++)// Creates TestedKmer
        {
            count = 0;
            TestedKmer = SearchWindow.substr(j,k);
            
            for (int jj = 0; jj < l-k; jj++)// Compare TestedKmer Against all kmers in search window
            {
                string OnKmer = SearchWindow.substr(jj,k);
                if (TestedKmer == OnKmer)
                {
                    count++;
                }
                
            }
            int test = count ;
            
            if (count >= t)
            {
                EndResult.push_back(TestedKmer);
                break;
            }
            break;
        }
        
    }
    return EndResult;
}
