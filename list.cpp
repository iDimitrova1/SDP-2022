#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Node
{
    int data = 0;
    Node* next = nullptr;
};

Node* GetLast (Node* first)
{
    while(first->next != nullptr)
    {
        first = first->next;
    }
    return first;
}

int GetSize (Node* first)
{
    int n{1};
    while(first->next != nullptr)
    {
        first = first->next;
        n++;
    }
    return n;
}

void AddNode (Node* last, int d)
{
    Node* temp = new Node;
    temp->data = d;
    last->next = temp;
}

void CreateList(const int &z, Node* first)
{
    int num;
    cout << "element 1 = " << endl;
    cin >> first->data;
    for(int i{1}; i < z; i++)
    {
        cout << "element " << i+1 << " = " << endl;
        cin >> num;
        AddNode(GetLast(first), num);
    }
}

int GetNth(Node* first, int index)
{
    Node* temp = first;
    for(int i{0}; i < index; i++)
    {
        temp = temp->next;
    }
    return temp->data;
}

void InsertNth(const int &index, Node* first,const int &number)
{
    if(index == 1)
    {
        Node* temp = first;
        first = new Node;
        first->data = number;
        first->next = temp;
        return;
    }
    for(int i{2}; i < index; i++)
    {
        first = first->next;
    }
    Node* temp = first->next;
    AddNode (first, number);
    first = first->next;
    first->next = temp;
}

void DeleteList (Node* &first)
{
    Node* temp;
    while(first != nullptr)
    {
        temp = first;
        first = first->next;
        delete temp;
    }
}

Node* CopyList(Node* first)
{
    int n;
    n = GetSize(first);
    Node list[n];
    for(int i{0}; i < n; i++)
    {
        list[i].data = first->data;
        list[i].next = first->next;
        first = first->next;
    }
    Node* temp =  &list[0];
    return temp;
}

int main()
{
    Node* head = new Node;
    CreateList(5, head);
    InsertNth(6, head, 69);
    Node* nov = new Node;
    nov = CopyList(head);

    head->data = 100;
    //cout << GetSize(head) << endl;
    // DeleteList(head);

    return 0;
}
