#include <iostream>
#include <string>
using namespace std;

using namespace std;

struct Car_warehouse
{
	bool emp[5];
	int speed[5], price[5];
	string color[5], name[5];
	void func1();
	void func2();
	void func3();
	void func4();
};

void Car_warehouse::func1()
{
	for (int i = 0; i < 2; i++)
	{
		emp[i] = false;
	}
}

void Car_warehouse::func2()
{
	for (int i = 0; i < 2; i++)
	{
		cout << "the number of the Car: " << i + 1 << endl;
		if (emp[i] == false)
		{
			cout << "enter the name ";
			cin >> name[i];
			cout << "enter the color ";
			cin >> color[i];
			cout << "enter the speed ";
			cin >> speed[i];
			cout << "enter the price ";
			cin >> price[i];
			cout << endl << endl;
		}
	}
}
void Car_warehouse::func3()
{
	for (int i = 0; i < 2; i++)
	{
		cout << "Car number " << i + 1 << endl;
		cout << "name " << name[i] << endl;
		cout << "color " << color[i] << endl;
		cout << "speed " << speed[i] << endl;
		cout << "price " << price[i] << endl << endl;
	}
}
void Car_warehouse::func4()
{
	int j;
	cin >> j;
	if (emp[j] == true)
	{
		cout << "to sell a auto with number " << j + 1;
		emp[j] = false;
	}
}
int main()
{
	Car_warehouse a;
	int count;
	bool EXIT = true;
	while (EXIT)
	{
		cin >> count;
		if (count == 5)
		{
			EXIT = false;
		}
		switch (count)
		{
		case 1:
			a.func1();
			break;
		case 2:
			a.func2();
			break;
		case 3:
			a.func3();
			break;
		case 4:
			a.func4();
			break;
		case 5:
			cout << "end of program";
		}
	}

	system("pause");
	return 0;
}