#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int h, n, i, j;
	bool found;
	while (cin >> h >> n && h && n)
	{
		if (h == 1 && n == 1)
		{
			cout << 0 << " " << 1 << endl;
			continue;
		}
		if (h-n == 1)
		{
			cout << 1 << " " << h+n << endl;
			continue;
		}

		found = false;
		for (i = 1; i < h-1 && !found; i++)
		{
			for (j = 1; pow(i+1,j) <= h && !found; j++)
			{
				if (pow(i,j) == n && pow(i+1,j) == h)
				{
					found = true;
					i--;
					j--;
				}
			}
		}
		if (i == 1)
			cout << j << " " << i*(h-n)+h << endl;
		else
			cout << (1-pow(i,j))/(1-i) << " " << i*(h-n)+h << endl;
	}
	return 0;
}

// Solver: RankSS
