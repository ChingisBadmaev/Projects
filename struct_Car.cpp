#include <iostream>
#include <string>
#include <clocale>
using namespace std;

struct Car
{
	bool emp;
	int speed, price;
	string color, name;
};

void func1(Car *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i].emp = false;
	}
}

void func2(Car *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "the number of the Car: " << i + 1 << endl;
		if (a[i].emp == false)
		{
			cout << "enter the name ";
			cin >> a[i].name;
			cout << "enter the color ";
			cin >> a[i].color;
			cout << "enter the speed ";
			cin >> a[i].speed;
			cout << "enter the price ";
			cin >> a[i].price;
			cout << endl << endl;
		}
	}
}
void func3(Car *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Car number " << i + 1 << endl;
		cout << "name " << a[i].name << endl;
		cout << "color " << a[i].color << endl;
		cout << "speed " << a[i].speed << endl;
		cout << "price " << a[i].price << endl << endl;
	}
}

void func4(Car *a, int n)
{
	int j;
	cin >> j;
	if (a[j].emp == true)
	{
		cout << "to sell a auto with number " << j + 1;
		a[j].emp = false;
	}
}
int main()
{
	setlocale(LC_ALL, "rus");
	int SIZE = 2;
	Car array[SIZE];
	int count;
	bool EXIT = true;
	while (EXIT)
	{
		cin >> count;
		if (count == 5)
		{
			EXIT = false;
		}
		switch(count)
		{	
			case 1:
				func1(array, SIZE);
				break;
			case 2:
				func2(array, SIZE);
				break;
			case 3:
				func3(array, SIZE);
				break;	
			case 4:
				func4(array, SIZE);
				break;
			case 5: 
				cout << "end of program";
		}
	}
	return 0;
}







