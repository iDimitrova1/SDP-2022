#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

static int counter{0};

int MaxN (int maxN, int n)
{
    for(int i{0}; i < n; i++)
    {
        maxN+=pow(2,i);
    }
    return maxN;
}

void BinaryN (int n, int* answA, int maxN)
{
    int k{counter};
        for(int j{0}; j<n; j++)
        {   
            answA [n-j-1] = k%2;
            k/=2;
        }
        for(int p{0}; p < n; p++)
        {
            cout << answA[p];
        }
        cout << endl;
    if(counter < maxN)
    {
        counter++;
        BinaryN(n,answA,maxN);
    }
    else
    {
        return;
    }
}

void BinaryNoRec (int n, int* answA, int maxN)
{
    for(int i{0}; i < maxN+1; i++)
    {
        int k{i};
        for(int j{0}; j<n; j++)
        {   
            answA [n-j-1] = k%2;
            k/=2;
        }
        for(int p{0}; p < n; p++)
        {
            cout << answA[p];
        }
        cout << endl;
    }
}

int main()
{  
    int n{0};
    cout << "n= ";
    cin >> n;
    int maxN{0};
    maxN+=MaxN(maxN, n);
    int answA [n];

    BinaryN(n,answA, maxN);

    return 0;
}