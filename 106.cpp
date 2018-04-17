#include <iostream>
#include <cstring>
using namespace std;

int gcd(int a, int b)
{
	return b == 0 ? a: gcd(b, a%b);
}

int main()
{	
	int n, i, j, k, arr[1000001], a, b, c, p, t;
	memset(arr, 0, sizeof(arr));
	while (cin >> n)
	{
		p = 0, t = 0;		
		for (i = 1; i*i <= n; i++)
		{
			for (j = i+1; j*j <= n; j++)
			{
				if (gcd(i,j) == 1)
				{
					a = j*j - i*i;
					b = 2*j*i;
					c = j*j + i*i;
					if (c > n) break;
					if (gcd(a,b) == 1) p++;
					for (k = 1; k*c <= n; k++)
					{
						arr[k*a] = 1;
						arr[k*b] = 1;
						arr[k*c] = 1;
					}
				}
			}
		}
		for (i = 1; i <= n; i++)
		{
			if (arr[i] == 0) t++;
			arr[i] = 0;
		}
		cout << p << " " << t << endl;
	}
	return 0;
}

// Solver: RankSS
