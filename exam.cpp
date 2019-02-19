#include <iostream>
#include <cstdlib>
#define INT(a, b, x) (x >= a && x <= b)

using namespace std;

int main()
{
    const int SIZE = 20;
    int* a = new int[SIZE];
    // Вводим массив
    cout << "array" << " ";
    for (int i = 0; i < SIZE; i++) 
	{
        a[i] = rand() % 10;
        cout << a[i] << " ";
    }
    cout << endl << endl;
    // Сортируем массив пузырьком
	for (int i = 0; i < SIZE; i++) 
	{
        for (int j = i + 1; j < SIZE; j++)
		{
            if (a[i] > a[j])
			{
                swap(a[i], a[j]);
            }
        }
    }
    // Выводим отсортированный массив
    cout << "sorted array" << " ";
    for (int i = 0; i < SIZE; i++)
	{
        cout << a[i] << " ";
    }
    cout << endl;
    //Вводим число которое хотим найти
    int f;
    cin >> f;
    // Используем бинарный поиск для поиска нужного числа
    int l = 0;
    int r = SIZE - 1;
    int s = -1;
    while (l <= r)
	{
        int m = (l + r) / 2;
        if (f == a[m])
		{
            s = m;
            break;
        }
        if (f < a[m])
		{
            r = m - 1;
        }
		else
		{
            l = m + 1;
        }

    }
    // индекс левой гранцы и провой равны индексу найденному элементу 
    l = s;
    r = s;
    //изначально сумма равна нулю
    int sum = 0;
    // определяем область с равными, нужными эелементами
    if (s != -1) 
	{
        while (l > 0 && a[l] == a[l - 1]) 
		{
            l--;
        }
        while (r < SIZE - 1 && a[r] == a[r + 1]) 
		{
            r++;
        }
        for (int i = 0; i < SIZE; i++)
		{
            if (a[i] != a[s]) 
			{
                sum += a[i];
            }
        }
        // выводим индексы границ области нужных элементов (если такая область есть)
        cout << "left = " << l << " right = " << r << endl;
        // выводим сумму найденных элементов
        cout << "sum = " << sum << endl;
    } 
    // иначе нет таких эелементов
	else 
	{
        cout << "Not Found" << " ";
    }
    // вводим границы
    int x, y;
    cin >> x >> y;
    // k это счетчик
    int k = 0;
    // Перебрасываем все элементы которые находятся не в области модуля в начало
    for (int i = 0; i < SIZE; i++) 
	{
        if (!INT(x, y, a[i])) 
		{
            a[k] = a[i];
            k++;
        }
    }
    // начиная с k-того эелемента(включительно), зануляем все
    for (int i = k; i < SIZE; i++) 
	{
        a[i] = 0;
    }
    // выводим массив
    for (int i = 0; i < SIZE; i++)
	{
	    cout << a[i] << " ";
    }
    return 0;
}
