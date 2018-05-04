#include <iostream>
using namespace std;

int dp[51][501][501], t[51], c[51], b[51];

int main()
{
	int C, T, M, n, i, j, k;
	cin >> C;
	while (C--)
	{
		cin >> T >> M >> n;
		for (i = 0; i < n; i++)
			cin >> t[i] >> c[i] >> b[i];

		for (i = 0; i <= n; i++)
		{
			for (j = 0; j <= M; j++)
			{
				for (k = 0; k <= T; k++)
				{
					if (i == 0 || j == 0 || k == 0)
						dp[i][j][k] = 0;
					else if (t[i-1] <= k && c[i-1] <= j)
						dp[i][j][k] = max(b[i-1]+dp[i-1][j-c[i-1]][k-t[i-1]], dp[i-1][j][k]);
					else
						dp[i][j][k] = dp[i-1][j][k];
				}
			}
		}
		cout << dp[n][M][T] << endl;
	}
	return 0;
}

// Solver: RankSS && mochithedog
