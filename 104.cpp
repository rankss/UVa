#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n, i, j, k, l, path[21][21][21], opt[21];
	double dp[21][21][21], val;
	bool flag;
	while (cin >> n)
	{
		flag = false;
		memset(dp, 0, sizeof(dp));
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				path[i][j][0] = i;
				if (i == j) dp[i][j][0] = 1.0;
				else cin >> dp[i][j][0];
			}
		}
		for (l = 1; l < n; l++)
		{
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					for (k = 0; k < n; k++)
					{
						val = dp[j][i][l-1]*dp[i][k][0];
						if (val > dp[j][k][l])
						{
							dp[j][k][l] = val;
							path[j][k][l] = i;
						}
					}
				}
			}
		}
		for (l = 1; l < n && !flag; l++)
		{
			for (i = 0; i < n; i++)
			{
				if (dp[i][i][l] > 1.01)
				{
					flag = true;
					opt[l] = path[i][i][l];
					for (j = l; j > 0; j--)
						opt[j-1] = path[i][opt[j]][j-1];
					for (j = 0; j <= l; j++)
						cout << opt[j]+1 << " ";
					cout << opt[0]+1 << endl;
					break;
				}
			}
		}
		if (!flag)
			cout << "no arbitrage sequence exists" << endl;
	}
	return 0;
}

// Solver: RankSS
