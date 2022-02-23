#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

int Fibonacci (int &F2, int &F3, int &n)
{
    if(n > 3)
    {
        if(F2 < F3)
        {
            F2+=F3;
        }
        else
        {
            F3+=F2;
        }
        n--;
        Fibonacci (F2, F3, n);
    }
    else
    {
        if(F2 < F3)
        {
            return F3;
        }
        else
        {
            return F2;
        }
    }
}


int main()
{  
    int F2{1};
    int F3{2};
    int n{0};
    cout << "number to find ( > 3) = ";
    cin >> n;

    if(n>3)
    {
        cout << Fibonacci(F2, F3, n) << endl;
    }
    
    return 0;
}