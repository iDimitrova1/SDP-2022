#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

struct Chaos
{
    int el1;
    int el2;
    int el3;
    int sum;
};

void readChaos(Chaos &d)
{
    // cout << "el1= ";
    cin >> d.el1;
    // cout << "el2= ";
    cin >> d.el2;
    // cout << "el3= ";
    cin >> d.el3;
    d.sum = d.el1 + d.el2 + d.el3;
}

void readChaos_arr(Chaos B[], int numberB)
{
    for (int i{0}; i < numberB; i++)
    {
        readChaos(B[i]);
    }
}

void CheckChaos1(Chaos *ptr, Chaos B[], int numberB, int& counter1, int& counter2)
{
    while (counter1 < numberB)
    {
        if (B[counter1].el1 == B[counter1].el2 && B[counter1].el2 == B[counter1].el3 && B[counter1].el1 == B[counter1].el3)
        {
            counter1++;
            CheckChaos1(ptr, B, numberB, counter1, counter2);            }
            else if (B[counter1].sum > 50)
        {
            counter1++;
            CheckChaos1(ptr, B, numberB, counter1, counter2);
        }
        else if (B[counter1].el3 > (B[counter1].el1 * B[counter1].el2))
        {
            counter1++;
            CheckChaos1(ptr, B, numberB, counter1, counter2);
        }
        else
        {
            ptr[counter2] = B[counter1];
            counter1++;
            counter2++;
            CheckChaos1(ptr, B, numberB, counter1, counter2);
        }
        
    }
}

void PChaos6 (Chaos *ptr, int counter2, int counter1)
{
    int j{0};
    counter1 = 1;
    if(counter2 > 5)
    {
        for(int k{0}; k < counter2; k++)
        {
            for (int i{0}; i < counter2; i++)
            {
                if(ptr[k].sum > ptr[i].sum)
                {
                    j++;
                }
            }
            if(j < 6)
            {
            cout << "for bedstvie " << counter1 << " || " << ptr[k].el1;
            cout << " | " << ptr[k].el2;
            cout << " | " << ptr[k].el3 << endl;
            counter1++;
            }
            j=0;
        }
    }
    else
    {
        for (int i{0}; i < counter2; i++)
        {
            cout << "for bedstvie " << i << " || " << ptr[i].el1;
            cout << " | " << ptr[i].el2;
            cout << " | " << ptr[i].el3;
            cout << " | " << ptr[i].sum << endl;
        }
    }
}

int main()
{
    int counter1{0};
    int counter2{0};

    int numberB{0};
    cout << "nomer na bedstviq= ";
    cin >> numberB;
    Chaos B[numberB];
    readChaos_arr(B, numberB);
    Chaos *ptr = new Chaos[numberB];

    CheckChaos1(ptr, B, numberB, counter1, counter2);
    PChaos6(ptr, counter2, counter1);

    delete[] ptr; //???
    //cout << endl << "test delete:  " << ptr[1].el2 << endl;

    return 0;
}