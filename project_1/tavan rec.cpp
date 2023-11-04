#include<iostream>
using namespace std;

int Rtavan(int a, int b)
{
	if (b == 1)
		return a;
	else
		return a*Rtavan(a, b - 1);
}

void main()
{
	int x, y;
	cin >> x >> y;
	cout << Rtavan(x, y) << endl;
}