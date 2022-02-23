#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

static int n{0};

void CheckIfPrime (int *arr, int &counter, int &answer)
{
    int devider{2};
    while(arr[counter]%devider != 0 && devider < arr[counter]/2)
    {
        devider++;
    }
    if(arr[counter]%devider == 0 && arr[counter] != 2)
    {
        counter++;
        if (counter < n)
        {
            CheckIfPrime(arr, counter, answer);
        }
    }
    else if(devider >= arr[counter]/2 || arr[counter] == 2)
    {
        answer+=arr[counter];
        counter++;
        if (counter < n)
        {
            CheckIfPrime(arr, counter, answer);
        }
    }
}

int main()
{  
    cout << "n = ";
    cin >> n;
    int answer{0};
    int counter{0};

    int arr[n];
    for(int i{0}; i<n; i++)
    {
        cout << "number " << i << " = ";
        do
        {
            cin >> arr[i];
        }
        while (arr[i] <= 1);
    }

    CheckIfPrime (arr, counter, answer);
    
    cout << "The sum of the primes is  " << answer << endl;
    return 0;
}