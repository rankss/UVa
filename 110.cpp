#include <iostream>
using namespace std;

char v[8] = {'a','b','c','d','e','f','g','h'};

void dft(int d, int n)
{
	int i;
	if (d == n)
	{
		for (i = 0; i < n; i++)
			cout << "  ";
		cout << "writeln(" << v[0];
		for (i = 1; i < n; i++)
			cout << "," << v[i];
		cout << ")" << endl;
		return;
	}
	for (i = 0; i <= d; i++)
		cout << "  ";
}

int main()
{
	int m, n, i, j;
	
	cin >> m;
	while (m--)
	{
		cin >> n;
		cout << "program sort(input, output);\nvar" << endl;
		cout << v[0];
		for (i = 1; i < n; i++)
			cout << "," << v[i];
		cout << " : integer;\nbegin\n  readln(" << v[0];
		for (i = 1; i < n; i++)
			cout << "," << v[i];
		cout << ")\n";
		dft(1, n);
		cout << "end.";
		if (m) cout << endl;
	}
	return 0;
}