#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

struct Book
{
	int ISBN;
	string name;
	string author;
	int number_case;
	int number_shelf;
	int place;
	string publishing;
	int publication_date;
	bool presence;
	bool active;
};

struct Library
{
	Book **p;
	int n;
	Library(int n)
	{
		p = new Book*[n];
		for (int i = 0; i < n; ++i)
		{
			p[i] = new Book();
		}
		for (int i = 0; i < n; ++i)
		{
			p[i]->active = false;
		}
	}
	~Library()
	{
		for (int i = 0; i < n; ++i)
		{
			delete p[i];
		}
		delete p;
	}
	void to_fill_the_library(int n)
	{
		for (int i = 0; i < n; ++i)
		{
			if (p[i]->active == false)
			{
				p[i]->active = true;
			}
			cout << "books number: " << i + 1 << endl;
			cout << "enter the ISBN: ";
			cin >> p[i]->ISBN;
			cout << "enter the name: ";
			cin >> p[i]->name;
			cout << "enter the author :";
			cin >> p[i]->author;
			cout << "number case: ";
			cin >> p[i]->number_case;
			cout << "enter the number shelf: ";
			cin >> p[i]->number_shelf;
			cout << "enter the place: ";
			cin >> p[i]->place;
			cout << "enter the publishing: ";
			cin >> p[i]->publishing;
			cout << "enter the publishing date: ";
			cin >> p[i]->publication_date;
			cout << "enter the presence: ";
			cin >> p[i]->presence;
			cout << endl;
		}
	}
	void find_the_book(int n, string author1, string name1)
	{
		for (int i = 0; i < n; ++i)
		{
			if (author1 == p[i]->author && name1 == p[i]->name)
			{
				cout << "number case: " << p[i]->number_case << endl;
				cout << "number shelf: " << p[i]->number_shelf << endl;
				cout << "place: " << p[i]->place << endl;
				cout << endl;
			}
			else
			{
				cout << "no such book ";
				cout << endl << endl;
			}
		}
	}
	void rearrange_books(int n, int ISBN1)
	{
		for (int i = 0; i < n; ++i)
		{
			if (ISBN1 == p[i]->ISBN)
			{
				cout << "old position: " << endl;
				cout << "old number case: " << p[i]->number_case << endl;
				cout << "old numder shelf: " << p[i]->number_shelf << endl;
				cout << "old place: " << p[i]->place << endl;
				
				cout << "enter the new position :" << endl;
				cout << "enter the new number case: ";
				cin >> p[i]->number_case;
				cout << "enter the number shelf: ";
				cin >> p[i]->number_shelf;
				cout << "place: ";
				cin >> p[i]->place;
				cout << endl;
			}
		}
	}
	void to_give_a_book(int n, string name1)
	{
		for (int i = 0; i < n; ++i)
		{
			if (name1 == p[i]->name && p[i]->presence == true)
			{
				cout << "to give a book: ";
				p[i]->presence = false;
				cout << endl;
			}
		}
	}
	
};


int main()
{
	int n;
	cout << "enter the count books: ";
	cin >> n;
	int count;
	Library* ar = new Library(n);
	string q, w, nm;
	int isbn;
	bool EXIT = true;
	while (EXIT)
	{
		cout << "1) to_fill_the_library" << endl;
		cout << "2) find_the_book" << endl;
		cout << "3) rearrange_books" << endl;
		cout << "4) to_give_a_book" << endl;

		cin >> count;
		if (count == 5)
		{
			EXIT = false;
		}
		switch (count)
		{
		case 1:
			ar->to_fill_the_library(n);
			break;
		case 2:
			cout << "enter the author and name book: ";
			cin >> q >> w;
			cout << q << " " << w;
			ar->find_the_book(n, q, w);
			break;
		case 3:
			cout << "enter the ISBN: ";
			cin >> isbn;
			ar->rearrange_books(n, isbn);
			break;
		case 4:
			cout << "enter the name book: ";
			cin >> nm;
			ar->to_give_a_book(n, nm);
			break;
		}
	}
	delete ar;
	system("pause");
	return 0;
}
