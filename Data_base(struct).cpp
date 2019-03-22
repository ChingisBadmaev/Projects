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
	//������� �����������
	int n;
	Data_base(int n)
	{
		p = new Tax_inspection*[n];
		for (int i = 0; i < n; i++) 
		{
			p[i] = new Tax_inspection();
		}
		//������ ��� ������ �����������
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
	//����� "��������� ���� ������"(������� �������� ��������)
	void to_fill_the_database(int n)
	{
		cout << "��������� ���� ������" << endl;
		for (int i = 0; i < n; i++)
		{
			if (p[i]->active == false)
			{
				p[i]->active = true;
			}
			cout << "������� ����� ��������� � " << i + 1 << ": ";
			cin >> p[i]->address;
			cout << "������� ���" << ": ";
			cin >> p[i]->name;
			cout << "������� ���������� ������" << ": ";
			cin >> p[i]->passport;
			cout << "������� ���� �������" << ": ";
			cin >> p[i]->price;
			cout << endl;
		}
	}
	//����� "��������� �����" 
	void calculate_tax(int n, int w)
	{
		double tax = 0.01 * w;
		for (int i = 0; i < n; i++)
		{
			if (p[i]->active == true)
			{
				cout << "����� ��������� ����� " << i + 1 << ": ";
				cout << tax * p[i]->price << endl;
			}
		}
	}
	//����� "���������������� �������" (what???) name, paaport
	void register_a_sale(int k, string new_owner, string new_passport)
	{
		cout << "������� ����� ��� � ����������� ������ ";
		cin >> new_owner >> new_passport;
		cout << "������� ������ ��������� " << p[k]->name << " ��������� " << new_owner << endl;
		p[k]->name = new_owner;
		p[k]->passport = new_passport;
	}
	//����� "���������������� ���� �������" 
	void the_demolition_of_the_object(int k)
	{
		cout << "���������������� ���� ������� c ������� " << ": " << p[k]->address << endl;
		p[k]->active = false;
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");
	int count;
	bool EXIT = true;
	//������ ���������� ��������
	cout << "������� ���������� �������� ";
	int q, w, j;
	cin >> q;
	string new_owner, new_passport;
	Data_base* ar = new Data_base(q);
	//��������� ������
	cout << "1) ��������� ���� ������" << endl;
	cout << "2) ��������� �����" << endl;
	cout << "3) ���������������� �������" << endl;
	cout << "4) ���������������� ���� �������" << endl;
	cout << "5) ����� �� ���������" << endl;
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
			cout << "������� ����� �� ������ ";
			cin >> w;
			ar->calculate_tax(q, w);
			break;
		case 3:
			cout << "������� ����� ������������ ������� ";
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


