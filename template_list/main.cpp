#include <iostream>

using namespace std;

template< typename T>
class Mylist
{
public:
    Mylist();
    ~Mylist();

    void PopFront();
    void Clear();
    void PushBack(T data);
    void PushFront(T data);
    void Insert(T data, int index);
    int GetSize() {return Size;}
    T& operator[](const int index);

private:

    class Node
    {
    public:
        Node *pNext;
        T data;

        Node(T data = T(), Node *pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };

    int Size;
    Node *head;
};

int main()
{

    Mylist<int> first;

    first.PushBack(5);
    first.PushBack(10);
    first.PushBack(22);

    cout << endl << "new list: " << endl;
    for (int i =0; i<first.GetSize(); i++) {
        cout << first[i] << endl;
    }

    first.PushFront(67);

    cout << endl << "new list: " << endl;
    for (int i =0; i<first.GetSize(); i++) {
        cout << first[i] << endl;
    }

    first.Insert(89,3);

    cout << endl << "new list: " << endl;
    for (int i = 0; i<first.GetSize(); i++) {
        cout << first[i] << endl;
    }


    return 0;
}

template< typename T>
Mylist<T>::Mylist():
    Size(0),
    head(nullptr)
{}

template< typename T>
Mylist<T>::~Mylist()
{
    Clear();
}

template<typename T>
void Mylist<T>::PopFront()
{
    Node *tmp = head;

    head = head->pNext;

    delete tmp;

    Size--;
}

template<typename T>
void Mylist<T>::Clear()
{
    while (Size)
    {
        PopFront();
    }

}

template<typename T>
void Mylist<T>::PushBack(T data)
{
    if (head == nullptr)
    {
        head = new Node(data);
    }
    else
    {
        Node *current = this->head;
        while (current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node(data);
    }
    Size ++;
}

template<typename T>
void Mylist<T>::PushFront(T data)
{
    head = new Node(data, head);
    Size++;
}

template<typename T>
void Mylist<T>::Insert(T data, int index)
{
    if (index == 0)
    {
        PushFront(data);
    }
    else
    {
        Node *prev = this->head;

        for (int i=0; i< index-1 ; i++)
        {
            prev = prev->pNext;
        }

        prev->pNext = new Node(data, prev->pNext);
    }
    Size++;
}

template<typename T>
T &Mylist<T>::operator[](const int index)
{
    int counter = 0;
    Node *current = this->head;
    while (current != nullptr)
    {
        if (counter == index)
            return current->data;

        current = current->pNext;
        counter++;
    }
}
