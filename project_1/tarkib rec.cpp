#include<iostream>
using namespace std;

int Rtarkib(int n,int r)
{
	if (r == n || r == 0)
		return 1;
	else
		return Rtarkib(n-1, r) + Rtarkib(n-1, r - 1);
}

void main()
{
	int x, y;
	cin >> x >> y;
	cout << Rtarkib(x, y) << endl;
}