#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

static int i{0};

void IsPalindrome (char* str, int counter)
{
    if(i == counter/2 && str[i] == str[counter-1-i])
    {
        i++;
        IsPalindrome (str, counter);
    }
    else if(i < counter/2 && str[i] == str[counter-1-i])
    {
        cout << "Palindrome.";
    }
    else
    {
        cout << "Not a palindrome.";
    }
}

int main()
{  
    char str [100];
    cin.getline (str, 100);

    int counter{0};
    while(str[counter] != '\0')
    {
        counter++;
    }

    IsPalindrome(str, counter);

    return 0;
}