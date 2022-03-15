#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

static int finalP{0};

struct Spisuk
{
    char name[20]={};
    int quant;
    float price;
};

void read_Spisuk (Spisuk& I)
{
    cin.ignore();
    //cout << "ime:";
    cin.getline(I.name, 20);
    //cout << "koli4estvo:";
    cin >> I.quant;
    //cout << "cena:";
    cin >> I.price;
}

void read_Spisuk_arr (Spisuk d[], int n)
{
    for(int i{0}; i<n; i++)
    {
        read_Spisuk(d[i]);
    }
}

void print_Spisuk (const Spisuk& d)
{
    cout << d.name << endl;
    cout << "kolichestvo:" << d.quant << endl;
    cout << "cena:" << d.price << endl;
}

void check_Magazin (Spisuk Magazin[], Spisuk Baba[], int m, int n)
{
    for(int i{0}; i<m; i++)
    {
        for(int j{0}; j<n; j++)
        {
            if(strcmp(Baba[j].name, Magazin[i].name) == 0)
            {
                if(Baba[j].quant <= Magazin[i].quant && Baba[j].price >= Magazin[i].price)
                {
                    finalP += Baba[j].quant * Magazin[i].price;
                    Magazin[i].quant -= Baba[j].quant;
                    Baba[j].quant = 0;
                }
                else if(Baba[j].quant > Magazin[i].quant && Baba[j].price >= Magazin[i].price)
                {
                    finalP += Magazin[j].quant * Magazin[i].price;
                    Baba[j].quant -= Magazin[i].quant;
                    Magazin[i].quant = 0;
                }
            }
        }
    }
}

void check_Result (const Spisuk Magazin[],const Spisuk Baba[], int m, int n)
{
    for(int i{0}; i<n; i++)
    {
        if(Baba[i].quant > 0)
        {
            print_Spisuk (Baba[i]);
        }
    }
    cout << "Obshto cena:" << finalP << endl;
}

int main()
{
    int n{0};
    //cout << "kolko produkta 6te kupuva babata?" << endl;
    cin >> n;
    int m{0};
    //cout << "kolko produkta ima v magazina?" << endl;
    cin >> m;
    Spisuk Baba[n];
    Spisuk Magazin[m];

    read_Spisuk_arr (Baba, n); read_Spisuk_arr (Magazin, m);
    cout << "=========================" << endl;
    check_Magazin (Magazin, Baba, m, n);
    check_Result (Magazin, Baba, m, n);

return 0;
}