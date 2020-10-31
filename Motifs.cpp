#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

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

vector <string>
Motifs( vector <vector <double>> Profile , vector <string> DNA , int k)
{
    vector <string> Motifs;
    for (int i = 0 ; i < DNA.size() ; i++)
    {
        string Text = DNA[i];
        Motifs.push_back(MostProbableKmer(Text , k , Profile));
    }
    return Motifs;
}

int main ()
{
    
}