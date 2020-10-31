#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string>

using namespace std;

vector <vector <double>>
InsertProfile(int k)
{
    vector <vector<double>> ProfileMatrix;
    vector<double> ColumnVector;
    double aa;
    for (int i = 0 ; i < 4 ; i++)
    {
        ColumnVector.clear();
        for (int j = 0 ; j < k ; j++)
        {
            cin >> aa;
            ColumnVector.push_back(aa);
        }
        ProfileMatrix.push_back(ColumnVector);
    }
    return ProfileMatrix;
}

string 
MostProbableKmer(string Text , unsigned int k , vector <vector <double>> ProfileMatrix)
{
    vector <double> ScoreMotifStore;
    
    double maxx = -1;
    int maxpos;
    // This loop iterates over the whole text
    for (int i = 0 ; i < Text.length() ; i++)
    {
        double ScoreMotif = 1;
        string Pattern = Text.substr(i,k);
        unsigned short int RowPos;
        // This loop iterates over the pattern (Text.substr(i,k))
        for (int j = 0 ; j < k ; j++)
        {
            char OnChar = Pattern[j];
            switch(OnChar)
            {
                case 'A' :
                RowPos = 0 ;
                break;

                case 'C' :
                RowPos = 1 ;
                break;

                case 'G' :
                RowPos = 2 ;
                break;

                case 'T' :
                RowPos = 3 ;
                break;

            }
            
            ScoreMotif = ScoreMotif * ProfileMatrix[RowPos][j];
        }
        ScoreMotifStore.push_back(ScoreMotif);
        if(ScoreMotif > maxx)
        {
            maxx = ScoreMotif;
            maxpos = i;
        }
    }

    string EndResult = Text.substr(maxpos,k);
    


    return EndResult;
}   

int main ()
{
    int k;
    cin >> k;

    vector <vector <double>> ProfileMatrix = InsertProfile(k);
    cout << MostProbableKmer("CAGTGA",k,ProfileMatrix);

}

//Tested And Proved