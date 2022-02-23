#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{  
    int n{0};
    cout << "n= ";
    cin >> n;
    int counter{1};
    int i{n};
    
    for(int j{0}; j<n; j++)
    {
        for(int k{0}; k<i; k++)
        {
            cout << 0;
        }
        cout << 1;
        counter*=10;
        i--;


    }

    return 0;
}