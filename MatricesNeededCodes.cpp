#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

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

vector <vector <double>> 
InitializeProfileMatrix(int k)
{
    vector <double> RowMatrix ;
    vector <vector <double>> InitialProfileMatrix;
    for (int j = 0 ; j < k ; j++ )
        {
            RowMatrix.push_back(0);
        } 
    for (int i = 0 ; i < 4 ; i++)
    {
        InitialProfileMatrix.push_back(RowMatrix);
    }
    return InitialProfileMatrix;
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

vector <vector <double>>
ComputeProfileMatrix(vector <vector <int>> CountMatrix , vector <string> Motifs, int k)
{
    double NumberOfMotifsStrings = Motifs.size();
    vector <vector <double>> ProfileMatrix ;
    ProfileMatrix = InitializeProfileMatrix(k);
    for(int i = 0 ; i < 4 ; i++)
    {
        for (int j = 0 ; j < k ; j++)
        {
            ProfileMatrix[i][j] = CountMatrix[i][j]/NumberOfMotifsStrings;
        }
    }
    return ProfileMatrix;

    // Profile Matrix Built
}

vector <vector  <double> >
ApplyLaPlaceSuccesionOnProfileMatrix(vector <vector <int>> CountMatrix , vector <string> Motifs , int k )
{
    
    
    vector <vector <double>> LaPlaceProfileMatrix;
    LaPlaceProfileMatrix = InitializeProfileMatrix(k); 
    for (int i = 0 ; i < 4 ; i++)
    {
        for (int j = 0 ; j < k ; j++)
        {
            CountMatrix[i][j]++;
        }
    }
    double Divisor = 0;
    for (int i = 0; i < 4; i++)
    {
        Divisor += CountMatrix[i][0];
    }
     for (int i = 0 ; i < 4 ; i++)
    {
        for (int j = 0 ; j < k ; j++)
        {
            LaPlaceProfileMatrix[i][j] = CountMatrix[i][j] / Divisor;
        }
    }
    return LaPlaceProfileMatrix;

    // LaPlaceProfile Matrix built
}
int main()
{
    vector <vector<int>> CountMatrix;
    vector <vector <double>> ProfileMatrix;
    vector <vector <double>> LaPlaceProfileMatrix;
    vector <string> Motifs = {"ACCT"};
    CountMatrix = ComputeCountMatrix(Motifs,4);
    ProfileMatrix = ComputeProfileMatrix(CountMatrix , Motifs, 4);
    LaPlaceProfileMatrix = ApplyLaPlaceSuccesionOnProfileMatrix(CountMatrix ,  Motifs , 4);
}
