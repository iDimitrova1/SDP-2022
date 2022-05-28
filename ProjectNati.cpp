#include <iostream>
#include <iomanip>
#include<string>
#include<list>
#include<time.h> 
#include<vector> 
#include<fstream>
#include<sstream>
#include<iterator>

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

    bool operator== (const Jivotno& jiv1)
    {
        return (vid    == jiv1.vid &&
                poroda == jiv1.poroda &&
                age    == jiv1.age &&
                price  == jiv1.price);
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

    void addToBalans (int price)
    {
        balans += price;
    }

    void AddAnimal (const Jivotno & animal, list<Jivotno> &name_list)
    {
        name_list.push_front(animal);
    }

    void RemoveAnimal (const Jivotno & animal, list<Jivotno> &name_list)
    {
        balans += animal.price;
        name_list.remove(animal);
    }

    void ChangeSvobodni (int a)
    {
        svobodni += a;
    }

    void AddRandomAnimal (list<Jivotno> &name_list)
    {
        Jivotno novo;
        SetRandom(novo);
        name_list.push_back(novo);
    }

    private:

    const unsigned int MAX_Cap {30};
    list<Jivotno> nalichni;
    list<Jivotno> klient;
    double balans;
    unsigned int svobodni;
};

bool CompareAnimal (const Jivotno nalichno, const Jivotno tursi)
{
    return (nalichno.vid == tursi.vid &&
            nalichno.poroda == tursi.poroda &&
            (tursi.age != 0 && nalichno.age - tursi.age < 1.00) &&
            nalichno.price <= tursi.price);
}

void OneDay (Shelter &shel)
{
    if(rand()% 9 > 2)
    {
        shel.AddRandomAnimal(shel.getListNalichni());
    }
    if(rand()% 9 < 5)
    {
        shel.AddRandomAnimal(shel.getListKlient());
    }

    auto my_it = shel.getListNalichni().begin();
    double sum{0};
    while (my_it != shel.getListNalichni().end())
    {
        double temp{0};
        temp = (my_it->price)*2;
        temp /= 100;
        sum += temp;
        shel.getBalans() -= temp;
        my_it++;
    }
    cout << sum << endl;

    auto new_it = shel.getListNalichni().begin();
    auto new_it2 = shel.getListKlient().begin();
    Jivotno novo;
    shel.getListKlient().push_front(novo);
    while (new_it2 != (shel.getListKlient()).end())
    {
        while (new_it != (shel.getListNalichni()).end())
        {
            if(CompareAnimal(*new_it, *new_it2))
            {
                shel.addToBalans(-(new_it->price));
                my_it = new_it;
                new_it++;
                shel.RemoveAnimal(*my_it, shel.getListNalichni());
                my_it = new_it2;
                new_it2--;
                shel.RemoveAnimal(*my_it, shel.getListKlient());
                shel.ChangeSvobodni(-1);
                cout << "animal removed" << endl;
                break;
            }
            else
            {
                new_it++;
            }
        }
        new_it = shel.getListNalichni().begin();
        new_it2++;
    }
    shel.getListKlient().remove(novo);

    ofstream new_file1, new_file2, new_balance;
    new_file1.open("day.nalichni.txt");
    new_file2.open("day.klient.txt");
    new_balance.open("day.balance.txt");
    shel.CopyListToFile(shel.getListNalichni(), new_file1);
    shel.CopyListToFile(shel.getListKlient(), new_file2);
    shel.CopyBalanceToFile(new_balance);
    new_file1.close();
    new_file2.close();
    new_balance.close();
}

int main()
{
    srand(time(NULL));

    // ofstream MyFile1, MyFile2;
    // MyFile1.open("my_file_nalichni.txt");
    // MyFile2.open("my_file_klient.txt");
    // ofstream BalanceFile;
    // BalanceFile.open("balance.txt");
    //Shelter testt;
    //test.PrintList();
    // test.CopyListToFile(test.getListNalichni(), MyFile1);
    // test.CopyListToFile(test.getListKlient(), MyFile2);
    // test.CopyBalanceToFile(BalanceFile);
    //BalanceFile.close();

    //Shelter My_shelter ("my_file_nalichni.txt", "my_file_klient.txt", CopyFileToDouble("balance.txt"));
    //My_shelter.PrintList();
    
    Shelter My_shelter ("day.nalichni.txt", "day.klient.txt", CopyFileToDouble("day.balance.txt"));
    for(int i{0}; i < 10; i++)
    {
    OneDay(My_shelter);
    }
    
    // Jivotno j_test;
    // SetRandom(j_test);
    // Jivotno j_test2 = j_test;
    // cout<<boolalpha<<CompareAnimal(j_test,j_test2);
    //testt.RemoveAnimal(j_test, test_list);
    //cout << test_list.back();


 return 0;
}