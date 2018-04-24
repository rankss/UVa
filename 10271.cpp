#include <iostream>
#include <climits>
using namespace std;

int dp[1001][5001];

int main()
{
	int n, k, t, i, j, L[5001], B[5001];
	cin >> t;
	while (t--)
	{
		cin >> k >> n;
		for (i = 0; i < n; i++)
			cin >> L[i];
		for (i = 1; i < n; i++)
			B[i-1] = (L[i]-L[i-1])*(L[i]-L[i-1]);
		k+=8;
		for (i = 0; i <= n; i++)
			dp[0][i] = 0;
		for (i = 1; i <= k; i++)
		{
			dp[i][n-3*i+1] = INT_MAX;
			for (j = n-3*i; j >= 0; j--)
				dp[i][j] = min(dp[i][j+1], dp[i-1][j+2]+B[j]);
		}
		cout << dp[k][0] << endl;
	}
	return 0;
}

// Solver: RankSS && mochithedog
