#include <iostream>
#include <iomanip>
#include<string>
#include<list>
#include<time.h> 
#include<vector> 
#include<fstream>
#include<sstream>

using namespace std;

struct Jivotno
{
    string vid;
    string poroda;
    double age;
    unsigned int price;

    friend ostream& operator<< (ostream &output, Jivotno &jiv)
    {
        output << jiv.vid << endl << jiv.poroda << endl << jiv.age << endl << jiv.price << endl;
        return output;
    }
};

string SetPoroda (const struct Jivotno & animal)
{
    if(animal.vid == "kuche")
    {
        vector<string> porodiKu;
        porodiKu.push_back("dakel");
        porodiKu.push_back("huski");
        porodiKu.push_back("ovcharka");
        porodiKu.push_back("pitbul");
        porodiKu.push_back("pincher");
        int random = rand() % porodiKu.size();
        return porodiKu.at(random);
    }
    else if (animal.vid == "kotka")
    {
        vector<string> porodiKo;
        porodiKo.push_back("persiiska");
        porodiKo.push_back("sterling");
        porodiKo.push_back("bengalska");
        porodiKo.push_back("britanska");
        porodiKo.push_back("savana");
        int random = rand() % porodiKo.size();
        return porodiKo.at(random);
    }
}

Jivotno SetRandom (struct Jivotno & animal)
{
    animal.age = (rand() % 160);
    animal.age /= 10;
    animal.price = rand() % 501 + 81;
    int random = rand() % 10 + 1;
    if (random < 6)
    {
        animal.vid = "kuche";
    }
    else
    {
        animal.vid = "kotka";
    }
    animal.poroda = SetPoroda(animal);
    return animal;
}

void PrintJivotno (const struct Jivotno & animal)
{
    cout << "vid = " << animal.vid
    << "| poroda = " << animal.poroda
    << "| age = " << animal.age
    << "| price = " << animal.price << endl;
}

double CopyFileToDouble (string BalanceFile)
{
    double ret{0};
    ifstream File;
    File.open(BalanceFile);
    string cLine;
    getline(File, cLine);
    ret = atof(cLine.c_str());
    return ret;
}

class Shelter
{
    public:
    
    Shelter()
    {
        int broi_nalichni = rand() % 13 + 4;
        for(int i{0}; i < broi_nalichni; i++)
        {
            Jivotno novo;
            SetRandom(novo);
            nalichni.push_back(novo);
        }
        int broi_klienti = rand() % 5 + 2;
        for(int i{0}; i < broi_klienti; i++)
        {
            Jivotno novo;
            SetRandom(novo);
            klient.push_back(novo);
        }
        balans = rand() % 1000 + 100;
        svobodni = MAX_Cap - broi_nalichni;
    }

    void CopyFileToList (string FileN, list<Jivotno> &lista)
    {
        ifstream File;
        File.open(FileN);
        int broi_nalichni{0};
        string copyLine;
        while (getline(File, copyLine))
        {
            broi_nalichni++;
        }
        broi_nalichni /= 4;

        File.clear();
        File.seekg (0, ios::beg);

        for(int i{0}; i < broi_nalichni; i++)
        {
            Jivotno novo;
            getline(File, novo.vid);
            getline(File, novo.poroda);
            getline(File, copyLine);
            novo.age = atof(copyLine.c_str());
            getline(File, copyLine);
            novo.price = atof(copyLine.c_str());
            lista.push_back(novo);
        }
    }

    Shelter(string FileN, string FileK, const double balance)
    {
        CopyFileToList (FileN, nalichni);
        CopyFileToList (FileK, klient);
        svobodni = MAX_Cap - getListNalichni().size();
        balans = balance;
    }

    list<Jivotno> & getListNalichni ()
    {
        return nalichni;
    }

    list<Jivotno> & getListKlient ()
    {
        return klient;
    }

    void PrintList ()
    {
        cout << "NALICHNI: " << endl;
        auto my_it = getListNalichni().begin();
        while (my_it != getListNalichni().end())
        {
            PrintJivotno(*my_it);
            my_it++;
        }
        cout << "TURSQT SE: " << endl;
        my_it = getListKlient().begin();
        while (my_it != getListKlient().end())
        {
            PrintJivotno(*my_it);
            my_it++;
        }
        cout << "BALANS: " << endl << getBalans();
    }

    void CopyListToFile (list<Jivotno> &list, ofstream &MyFile)
    {
        auto my_it = list.begin();
        while (my_it != list.end())
        {
            MyFile << *my_it;
            my_it++;
        }
    }

    void CopyBalanceToFile (ofstream &MyFile)
    {
        MyFile << balans;
    }

    double & getBalans ()
    {
        return balans;
    }

    private:

    const unsigned int MAX_Cap {30};
    list<Jivotno> nalichni;
    list<Jivotno> klient;
    double balans;
    unsigned int svobodni;
};

void OneDay (Shelter &shel)
{
    auto my_it = (shel.getListNalichni()).begin();
    while (my_it != (shel.getListNalichni()).end())
    {
        double temp{0};
        temp = (my_it->price)*2;
        temp /= 100;
        shel.getBalans() -= temp;
    }
}

int main()
{
    srand(time(NULL));

    // ofstream MyFile1, MyFile2;
    // MyFile1.open("my_file_nalichni.txt");
    // MyFile2.open("my_file_klient.txt");
    // ofstream BalanceFile;
    // BalanceFile.open("balance.txt");
    //Shelter test;
    //test.PrintList();
    // test.CopyListToFile(test.getListNalichni(), MyFile1);
    // test.CopyListToFile(test.getListKlient(), MyFile2);
    // test.CopyBalanceToFile(BalanceFile);
    //BalanceFile.close();
    Shelter My_shelter ("my_file_nalichni.txt", "my_file_klient.txt", CopyFileToDouble("balance.txt"));
    My_shelter.PrintList();

 return 0;
}