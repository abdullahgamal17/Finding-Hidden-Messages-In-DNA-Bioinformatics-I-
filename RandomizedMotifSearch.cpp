#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;


unsigned int 
Random(unsigned int n) //Returns a Random int between 0 and n-1
{
    srand(time(NULL));
    unsigned int Random = rand() % n;

    return Random; 
}

vector <string> 
SelectRandomKmers(vector <string> DNA , unsigned int k , unsigned int t) // Creates Random Motifs
{
    srand(time(0));
    vector <string> RandomMotifs;
    for (int i = 0 ; i < t ; i++)
    {
        unsigned int n = DNA[i].length() - k + 1;
        unsigned int randindex = Random(n);
        string Motif = DNA[i].substr(randindex,k);
        RandomMotifs.push_back(Motif);
    }
    return RandomMotifs;
}

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
InitializeProfileMatrix(int k)//Initializes 4 x k matrix of doubles with 0.0
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
CountFromMotifs(vector <string> Motifs , int k)// Creates a 4 x k Count Matrix with the number of nucleotides found in each column
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
ProfileFromMotif(vector <vector <int>> CountMatrix , vector <string> Motifs, int k)// Creates Profile Matrix out of count matrix
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
ApplyLaPlaceSuccesionOnProfileMatrix(vector <vector <int>> CountMatrix , vector <string> Motifs , int k ) // Adds pseudocounts thus applying laplace rule of succession to eliminate zeroes out of profile matrix
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

string
MostProbableKmer(string Text , unsigned int k , vector <vector <double>> ProfileMatrix) // Finds Out most probable kmer in a long text
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
        if(ScoreMotif > maxx )
        {
            maxx = ScoreMotif;
            maxpos = i;
        }
    }

    string EndResult = Text.substr(maxpos,k);
    


    return EndResult;
}

vector <string> 
MotifsFromProfile(vector < vector <double> > Profile , vector <string> DNA , unsigned int k , unsigned int t) // Creates Motifs From Profile by choosing each string's most probable kmer 
{
    vector <string> Motifs;
    for (int i = 0 ; i < DNA.size() ; i++)
    {
        string Text = DNA[i];
        Motifs.push_back(MostProbableKmer(Text , k , Profile));
    }
    return Motifs;
}

string
Consensus(vector < vector < double > > Profile) // Creates Consensus String From Profile
{
    string Consensus;
    for (int i = 0; i < Profile[0].size() ;i++)
    {
        double maxx = 0;
        char OnChar;

        if(Profile[0][i] > maxx)
        {
            maxx = Profile[0][i];
            OnChar = 'A';
        }

        if(Profile[1][i] > maxx)
        {
            maxx = Profile[1][i];
            OnChar = 'C';
        }

        if(Profile[2][i] > maxx)
        {
            maxx = Profile[2][i];
            OnChar = 'G';
        }

        if(Profile[3][i] > maxx)
        {
            maxx = Profile[3][i];
            OnChar = 'T';
        }
        Consensus += OnChar;
        
        
    }
    return Consensus;
}

int HammingDistance(string p , string q)
{
    int counter = 0;
    
    {
        for (int i = 0 ; i<p.length();i++)
        {
            if(p[i] != q[i]) 
            {
                counter++;
            }
        }
    }
    return counter;
}

int d(string Pattern , string Text)
{
    int min = 100000;
    for (int i = 0 ; i < Text.length() ; i++)
    {
        string Pattern2 = Text.substr(i,Pattern.length());
        if(min > HammingDistance(Pattern,Pattern2))
        {
            min = HammingDistance(Pattern, Pattern2);
        }
    }
    return min;
}

int d(string Pattern , vector <string> DNA)
{
    int SumOfD = 0;
    
    for (int i = 0 ;  i < DNA.size() ;i++)
    {
        int min = 100000;
        for (int j = 0 ; j < DNA[i].length() - Pattern.length() ; j++)
        {
            string Pattern2 = DNA[i].substr(j,Pattern.length());
            int distance = d(Pattern,Pattern2);
            if(min > distance )
            {
                min = d(Pattern,Pattern2);
            }
        }
        SumOfD += min;
    }
    return SumOfD;
}

int
Score(vector <string> Motifs)
{
    vector <vector<int>> CountMatrix;
    int k = Motifs[0].length();
    CountMatrix = CountFromMotifs(Motifs,k);
    vector <vector <double>> Profile = ProfileFromMotif (CountMatrix , Motifs , k);
    int totalscore = 0;
    int columnscore = 0;
    string Cons = Consensus(Profile); 
    for (int i = 0; i < Motifs.size(); i++)
    {
        totalscore += HammingDistance(Cons , Motifs[i]);
    }
    
    
    return totalscore;
}

vector<string>
RandomizedMotifSearch(vector <string> DNA , unsigned int k , unsigned int t) // set of string is DNA , k is the length of kmer , t is number of strings in DNA vector
{
    vector <string> Motifs ;
    vector <string> BestMotifs;

    Motifs = SelectRandomKmers(DNA , k , t);
    BestMotifs = Motifs;

    while (true)
    {
        vector < vector < int > > CountMatrix = CountFromMotifs(Motifs , k);
        vector < vector <double> > Profile = ApplyLaPlaceSuccesionOnProfileMatrix(CountMatrix , Motifs , k);
        Motifs = MotifsFromProfile(Profile , DNA , k , t);

        int MotifScore = Score(Motifs);
        int BestMotifScore = Score(BestMotifs);

        if (MotifScore < BestMotifScore)
        {
            BestMotifs = Motifs;
        }
        else
        {
            return BestMotifs;
        }
    }
}

int main ()
{
    int k , t  ;
    cin >> k >> t;
    vector <string> DNA;
    vector <string> EarlyMotifs;
    vector <string> BestMotifs;
    for (int i = 0 ; i < t ; i++)
    {
        string a;
        cin >> a;
        DNA.push_back(a);
    }
    EarlyMotifs = RandomizedMotifSearch(DNA , k ,t);
    int EarlyMotifScore = Score(EarlyMotifs);
    vector <string> LateMotifs ;

    for(int i = 0 ; i < 500; i++)
    {
        LateMotifs = RandomizedMotifSearch(DNA , k ,t);
        int LateMotifScore = Score(LateMotifs);
        
        if (EarlyMotifScore > LateMotifScore)
        {
            EarlyMotifScore = LateMotifScore;
            EarlyMotifs = LateMotifs;
        }
    }

    for(int i = 0 ; i < EarlyMotifs.size() ; i++)
    {
        cout << EarlyMotifs[i] << endl ; 
    }
    
}