#include <iostream>
using namespace std;

template<class T>
struct ANode
{
    T data;
    ANode<T>* down, * right;
    ANode(T dd, ANode<T>* d = nullptr, ANode<T>* r = nullptr) :
        data(dd), down(d), right(r) {}
};

/*find the number of sons*/
template<class T>
int number_grandsons(ANode<T>* r)
{
    if (r == nullptr)
    {
        return 0;
    }
    int result = 0;
    int count = 0;
    ANode<T>* temp = r->down;
    while (temp != nullptr)
    {        
        temp = temp->right;
        count++;
    }
    for (int i = 0; i < count; ++i)
    {
        temp = r->down;
        for (int j = 0; j < i; ++j)
        {
            temp = temp->right;
        }
        temp = temp->down;
        while (temp != nullptr)
        {
            temp = temp->right;
            result++;
        }
    }
    return result;
};

/*find first son with data d1
second son has data d2*/
template<class T>
ANode<T>* find_son_first(ANode<T>* r, T d1, T d2)
{
    if (r == nullptr)
    {
        return nullptr;
    }
    int count = 0;
    r->down->right->data = d2;
    ANode<T>* temp = r->down;
    while (temp->data != d1)
    {
        temp = temp->right;
    }
    return temp;
}

/*pointer to the first son with data d1,
who has a son with data d2*/
template<class T>
int find_son_second(ANode<T>* r, T d1, T d2)
{
    /*if (r == nullptr)
    {
        return 0;
    }*/
    int count = 0;
    ANode<T>* temp = r->down;
    ANode<T>* answer = r->down;
    while (temp != nullptr)
    {
        if (temp->data == d2)
        {
            while (answer->data != d1)
            {
                answer = answer->right;
                count++;
            }
            return count;
        }
        temp = temp->right;
    }
    return count;
}
int main()
{
    ANode<int>* tree = new ANode<int>(0, new ANode<int>(1, nullptr, new ANode<int>(2, nullptr, new ANode<int>(3, nullptr, nullptr))), nullptr);
    int d1 = 3, d2 = 3;
    cout << find_son_second(tree, d1, d2);
    return 0;
}