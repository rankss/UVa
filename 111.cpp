#include <iostream>
using namespace std;

int maximum(int a, int b)
{
	return (a < b) ? b : a;
}

int main()
{
	int n, r, i, j, k = 0, c[21], s[21], dp[21][21] = {};
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> r;
		c[r-1] = i;
	}
	while (cin >> r)
	{
		s[r-1] = k++;
		if (k%n == 0)
		{
			for (i = 1; i <= n; i++)
			{
				for (j = 1; j <= n; j++)
				{
					if (c[i-1] == s[j-1])
						dp[i][j] = dp[i-1][j-1]+1;
					else
						dp[i][j] = maximum(dp[i-1][j], dp[i][j-1]);
				}
			}
			cout << dp[n][n] << endl;
			k = 0;
		}
	}
	return 0;
}

// Solver: RankSS
