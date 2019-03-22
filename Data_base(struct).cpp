	#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Tax_inspection
{
	string name;
	string address;
	string passport;
	double price;
	bool active;
}b;

struct Data_base
{
	Tax_inspection **p;
	//создаем конструктор
	int n;
	Data_base(int n)
	{
		p = new Tax_inspection*[n];
		for (int i = 0; i < n; i++) 
		{
			p[i] = new Tax_inspection();
		}
		//делаем все записи неактивными
		for (int i = 0; i < n; i++)
		{
			p[i]->active = false;
		}
	}
	~Data_base()
	{
		for (int i = 0; i < n; i++)
		{
			delete p[i];
		}
		delete p;
	}
	//метод "пополнить базу данных"(сделать неактивы активами)
	void to_fill_the_database(int n)
	{
		cout << "пополнить базу данных" << endl;
		for (int i = 0; i < n; i++)
		{
			if (p[i]->active == false)
			{
				p[i]->active = true;
			}
			cout << "введите адрес владельца № " << i + 1 << ": ";
			cin >> p[i]->address;
			cout << "введите имя" << ": ";
			cin >> p[i]->name;
			cout << "введите паспортные данные" << ": ";
			cin >> p[i]->passport;
			cout << "введите цену объекта" << ": ";
			cin >> p[i]->price;
			cout << endl;
		}
	}
	//метод "расчитать налог" 
	void calculate_tax(int n, int w)
	{
		double tax = 0.01 * w;
		for (int i = 0; i < n; i++)
		{
			if (p[i]->active == true)
			{
				cout << "налог владельца номер " << i + 1 << ": ";
				cout << tax * p[i]->price << endl;
			}
		}
	}
	//метод "зарегистрировать продажу" (what???) name, paaport
	void register_a_sale(int k, string new_owner, string new_passport)
	{
		cout << "введите новое имя и пасспортные данные ";
		cin >> new_owner >> new_passport;
		cout << "продаем объект владельца " << p[k]->name << " владельцу " << new_owner << endl;
		p[k]->name = new_owner;
		p[k]->passport = new_passport;
	}
	//метод "зарегистрировать снос объекта" 
	void the_demolition_of_the_object(int k)
	{
		cout << "зарегистрировать снос объекта c адресом " << ": " << p[k]->address << endl;
		p[k]->active = false;
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");
	int count;
	bool EXIT = true;
	//вводим количество объектов
	cout << "введите количество объектов ";
	int q, w, j;
	cin >> q;
	string new_owner, new_passport;
	Data_base* ar = new Data_base(q);
	//описываем методы
	cout << "1) пополнить базу данных" << endl;
	cout << "2) расчитать налог" << endl;
	cout << "3) зарегистрировать продажу" << endl;
	cout << "4) зарегистрировать снос объекта" << endl;
	cout << "5) выход из программы" << endl;
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
			ar->to_fill_the_database(q);
			break;
		case 2:
			cout << "введите налог на объект ";
			cin >> w;
			ar->calculate_tax(q, w);
			break;
		case 3:
			cout << "введите номер продаваемого объекта ";
			cin >> j;
			ar->register_a_sale(j - 1, new_owner, new_passport);
			break;
		case 4:
			ar->the_demolition_of_the_object(j - 1);
			break;
		case 5:
			cout << "end of program";
		}
		
	}
	delete ar;
	system("pause");
	return 0;
}


