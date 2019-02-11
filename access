#include <bits/stdc++.h>
using namespace std;
double** matrix;
int n;
void create(int size) 
{
	n = size;
	matrix = new double*[3 * n]; 
	for (int i = 0; i < n; i++) 
	{
		matrix[i] = new double[n]; 
	}
	for (int i = n; i < 3 * n; i++) 
	{
		matrix[i] = new double[2 * n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = rand() % 10; 
		}
	}
	for (int i = n; i < 3 * n; i++) {
		for (int j = 0; j < 2 * n; j++) {
			matrix[i][j] = rand() % 10;
		}
	}
}

int access(int x, int y)
{

	if (x < n && y < n) {
		return matrix[x][y];
	} else if (x < 2 * n && y >= n) {
		return matrix[x + n][y - n];
	} else {
		return 0;
	}
}

void destroy()
{  
	for (int i = 0; i < 3 * n; i++) 
	{
		delete matrix[i]; 
	}
	delete matrix;
}

int main()
{
	int size;
	cin >> size;
	create(size);
	int k, m;
	cin >> k >> m;
	cout << access(k, m);
	destroy();
	return 0;
}


