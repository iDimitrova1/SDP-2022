#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void ReplaceLetter (char*, char, char);
void ReplaceLetterWithC (const ofstream &string, char, char);

int main()
{  
    char string[100];
    cin.getline(string, 100);
    char charP;
    cout << "enter letter to replace ";
    cin >> charP;
    char chaRep;
    cout << "enter letter to replace ";
    cin >> chaRep;

    ofstream inFile;
    inFile.open ("leremipsum.txt",std::fstream::in);
    ofstream outFile;
    outFile.open ("lereOUT.txt",std::fstream::app);

//ReplaceLetter(string, charP, chaRep);
ReplaceLetterWithC(inFile, charP, chaRep);

    return 0;
}

void ReplaceLetter (char*string, char charP, char chaRep)
{
    for(int i{0}; string[i] != '\0'; i++)
    {
        if(string[i] == charP)
        {
            string[i] = chaRep;
        }
    }
    for(int i{0}; string[i] != '\0'; i++)
    {
        cout << string[i];
    }
}

void ReplaceLetterWithC (const ofstream &string, char charP, char chaRep)
{
   int n{0};
char copy[100];

    for(int i{0}; string[i] != '\0'; i++)
    {
        if(string[i] == charP)
        {   
            copy[i+n] = '"';
            copy[i+n+1] = chaRep;
            copy[i+n+2] = '"';
            n+=2;
        }
        else{
            copy[i+n] = string[i];
        }
        copy[i+n+1] = '\0';

    }
    for(int i{0}; copy[i] != '\0'; i++)
    {
        cout << copy[i];
    }
}