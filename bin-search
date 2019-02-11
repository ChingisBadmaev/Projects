#include <iostream>
#include <stdlib.h>
#include <ctime> 

using namespace std;

void quicksort(int *a, int left, int right)
{
    int i = left;
    int j = right;
    int c = a[(right + left)/2];

    while (i <= j)
    {
        while (a[i] < c)
        {
            i++;
        }
        while (a[j] > c)
        {
            j--;
        }
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if (left < j)
    {
        quicksort(a, left, j);
    }
    if (i < right)
    {
        quicksort(a, i, right);
    }
}

int insert(int len, int a[], int x)
{
	int l = 0;
	int r = len - 1;
	while (l != r - 1) 
	{
		int m = (l + r) / 2;
		if (a[m] > x) 
		{
			r = m;
		} 
		else 
		{
			l = m;
		}
	}
	if (l == 0) 
	{
		l--;
	}
	for (int i = len - 1; i >= l + 1; i--) 
	{
		a[i] = a[i - 1];
	}
	a[l + 1] = x;
	return 0;
}

int main() 
{
	srand(time(NULL));
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) 
	{
		a[i] = rand() % 10;
	}
	quicksort(a, 0, n - 1);
	cout << endl;
	int x;
	cin >> x;
	insert(n, a, x);
	for (int i = 0; i < n; i++) 
	{
		cout << a[i] << " ";
	}
	return 0;
}
