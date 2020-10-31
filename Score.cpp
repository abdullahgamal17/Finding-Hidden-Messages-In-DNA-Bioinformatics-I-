#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

vector <vector <int>> 
InitializeCountMatrix(int k)
{
    vector <int> RowMatrix ;
    vector <vector <int>> InitialCountMatrix;
    for (int j = 0 ; j < k ; j++ )
        {
            RowMatrix.push_back(0);
        } 
    for (int i = 0 ; i < 4 ; i++)
    {
        InitialCountMatrix.push_back(RowMatrix);
    }
    return InitialCountMatrix;
}

vector <vector <int>> 
ComputeCountMatrix(vector <string> Motifs , int k)
{
    vector <vector<int>> CountMatrix;
    CountMatrix = InitializeCountMatrix(k);
    /*
    In this loop i demonstrates the Motifs string in Motifs vector
    and j represents the position of character in the i-th Motifs string
    where 0 represents 'A'
    where 1 represents 'C'
    where 2 represents 'G'
    where 3 represents 'T'
    */
    for (int i = 0 ; i < Motifs.size() ; i++)
    {
        for (int j = 0 ; j < Motifs[i].length() ; j++)
        {
            char OnChar = Motifs[i][j];
            switch(OnChar)
            {
                case 'A' :
                CountMatrix[0][j]++;
                break;

                case 'C' :
                CountMatrix[1][j]++;
                break;

                case 'G' :
                CountMatrix[2][j]++;
                break;

                case 'T' :
                CountMatrix[3][j]++;
                break;

            }

        }

    }
    return CountMatrix;

    // CountMatrix Correctly Built
}

int
Score(vector <string> Motifs)
{
    vector <vector<int>> CountMatrix;
    int k = Motifs[0].length();
    CountMatrix = ComputeCountMatrix(Motifs,k);
    int totalscore = 0;
    int columnscore = 0;
    

    for (int i = 0 ; i < k ; i++ )
    {
        int maxx = 0;
        for (int j = 0 ; j < 4 ; j++)
        {
            if (CountMatrix[j][i] > maxx)
            {
                maxx = CountMatrix[j][i];
            }
        }
        totalscore += (Motifs.size() - maxx);
    }
    return totalscore;
}

int main()
{
    vector <string> Motifs;
    
    for (int i = 0 ; i < 5 ; i++ )
    {
        string a;
        cin>> a;
        Motifs.push_back(a);
    }
    cout << Score(Motifs);
}