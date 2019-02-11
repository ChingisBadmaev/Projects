#include <iostream>
#include <math.h>

using namespace std;

double f(double x)
{
	return 2 * x + 3;
}

double solution(double (*f)(double), double left, double right)
{
	long double eps = 0.000000001, middle;
	if (f(left) * f(right) > 0)
	{
		cout << "корня нет";
		return 0;
	}
	while (right - left > eps)
	{
		middle = (left + right) / 2.0;
		
		if (f(middle) * f(left) <= 0)
		{
			right = middle;
		}
	
		else if (f(middle) * f(right) <= 0)
		{
    	 	left = middle;
		}		
	}
	return right;
}

int main()												
{
	int a, b;
	cin >> a >> b;
	cout << solution(f, a, b);
	return 0;
}
