#include <iostream>
#include <vector>
#include <string>

using namespace std;

unsigned long long i;
int j = 0 ;
int k;

vector <int> PosOfPatternsWithMismatches ;

int HammingDistance(string p , string q)
{
    int counter = 0;
    if (p.length()==q.length())
    {
        for (k = 0 ; k<p.length();k++)
        {
            if(p[k] != q[k]) 
            {
                counter++;
            }
        }
   
    }
    else
    {
        cout << """Two Texts aren't equal can't process (The Hamming Distance Problem) and '-1' indicates that it failed " ; 
    }
    return counter;
}

vector <int> 
ApproximatePatternFindWithMismatches(string pattern , string Genome , int d)
{
    unsigned long long GenomeLength = Genome.length() ;
    unsigned long long  PatternLength = pattern.length();
   
    
        if (HammingDistance(pattern , Genome.substr(i,PatternLength)) <= d)
        {
            PosOfPatternsWithMismatches.push_back(i);
            
        }
    
    for (i=0 ; i<PosOfPatternsWithMismatches.size() ; i++)
    {
        
        cout << PosOfPatternsWithMismatches[i] <<' ';
    }
    cout << "\n\n\n";
    return PosOfPatternsWithMismatches;


}

int main ()
{
    string pattern , Genome ;
    int d; 
    cin >>  pattern  >> d;
    // Enter Genome here
    Genome= "";
    ApproximatePatternFindWithMismatches(pattern,Genome,d);
    



}
