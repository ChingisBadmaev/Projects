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
ANode<T>* find_son_second(ANode<T>* r, T d1, T d2)
{
    if (r == nullptr)
    {
        return 0;
    }
    ANode<T>* temp = r->down;
    ANode<T>* answer = r->down;
    while (temp != nullptr)
    {
        if (temp->data == d2)
        {
            while (answer->data != d1)
            {
                answer = answer->right;
            }
            return answer;
        }
        temp = temp->right;
    }
    return nullptr;
}

/*the function returns a pointer to the node obtained from the root by successive movements
down into the first son with given data
the data sequence is stored in an array that is passed in
as parameter*/
template<class T>
ANode<T>* data_descent(ANode<T>* r, int mass[], int SIZE)
{
    if (r == nullptr)
    {
        return;
    }
    ANode<T>* temp = r;
    for (int i = 0; i < SIZE; ++i)
    {
        while (true)
        {
            if (temp->data == mass[i] && i != SIZE - 1)
            {
                temp = temp->down;
                break;
            }
            if (temp->data == mass[i] && i == SIZE - 1)
            {
                break;
            }
            temp = temp->right;
        }
    }
    return temp;
}

/*function adds a new root to the tree
the old root becomes the only son of the new*/
template<class T>
void new_root(ANode<T>*& r, T d)
{
    if (r == nullptr)
    {
        return;
    }
    r = new ANode<T>(d, r, nullptr);
}

/*procedure removes the first son of the root
his sons, if any, become sons
root in front of the former second root son*/
template<class T>
void delete_first_son(ANode<T>*& r)
{
    if (r == nullptr)
    {
        return;
    }
    ANode<T>* temp = r->down->down;
    ANode<T>* new_first_son = r->down->right;
    while (temp->right != nullptr)
    {
        temp = temp->right;
    }
    temp->right = r->down->right->down;
    new_first_son->down = r->down->down;
    delete r->down;
    r->down = new_first_son; 
}

int main()
{
    int arr[4] = {100, 1, 3, 8 };
    ANode<int>* tree = new ANode<int>(1,
        new ANode<int>(2,
            new ANode<int>(5,
                nullptr,
                new ANode<int>(6,
                    nullptr,
                    new ANode<int>(7))),
            new ANode<int>(3,
                new ANode<int>(8),
                new ANode<int>(4,
                    new ANode<int>(9,
                        nullptr,
                        new ANode<int>(10))))));  
    //new_root(tree, 100);
    cout << tree->down->data << endl;
    delete_first_son(tree);
    //data_descent(tree, arr, 4)->data;
    cout << tree->down->down->data << endl;
    return 0;
}