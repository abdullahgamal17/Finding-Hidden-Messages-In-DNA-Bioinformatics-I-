// This string counts the most repeated kmer in a DNA strand

#include <iostream>
#include <string>
using namespace std;

string original , test , originalcmpr ;

int   startoriginal , i , j , ii , jj , k ,counter ;

int maxCount = 0 ;

int starttest = -1 ;

int main()
{
    cin >> original >> k ;

    string FreqPtrns[1000];
    int FreqCnt[1000];
// initilization start

    for (ii=0 ; ii < 1000 ; ii++)
    {
    FreqPtrns[ii]="null";
    }

    for (jj = 0 ; jj < 1000 ; jj++)
    {
    FreqCnt[jj]=0;
    }
// initilization done

//Comparing
    for (i = 0 ; i < original.length()-k ; i++) 
    {
        counter = 0;
        starttest++;
        string test = original.substr(starttest,k);
        for (j=0 ; j< original.length()-k;j++)
        {
            originalcmpr = original.substr(j,k);
            
            if (test.compare(originalcmpr)==0)
            {
                counter++;
            }
            else
            {
                continue;
            }
            
        }

        if (counter > maxCount )
        {
        FreqPtrns[i] = test;
        FreqCnt[i]=counter;
        maxCount = counter;
        }
    }

 
  for (i = 0; i<1000;i++)
  {
      if (FreqCnt[i]>=maxCount)
      {
          cout << FreqPtrns[i] << "  Repeated " << FreqCnt[i]<< "  ";
      }
  }
}