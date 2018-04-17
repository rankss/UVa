#include <iostream>
#include <climits>
using namespace std;

int minimum(int a, int b, int c)
{
	int x = (b < c) ? b : c;
	return (a < x) ? a : x;
}

int main()
{
	int arr[10][100], dp[10][100], m, n, i, j, k, rt[100], min, init, lim, trace, minidx;
	while (cin >> m >> n)
	{
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				cin >> arr[i][j];
				dp[i][j] = 0;
			}
		}

		for (i = 0; i < m; i++)
			dp[i][n-1] = arr[i][n-1];

		for (j = n-2; j >= 0; j--)
			for (i = 0; i < m; i++)
				dp[i][j] = minimum(dp[(i-1+m)%m][j+1], dp[i][j+1], dp[(i+1+m)%m][j+1]) + arr[i][j];

		min = INT_MAX;
		for (i = 0; i < m; i++)
			if (dp[i][0] < min)
				min = dp[i][0];

		init = 0, lim = m, k = 0, trace = min;
		for (j = 0; j < n; j++)
		{
			minidx = INT_MAX;
			for (i = init; i < lim; i++)
				if (dp[i%m][j] == trace)
					if (i%m < minidx) 
						minidx = i%m;
			rt[k++] = minidx%m + 1;
			trace-=arr[minidx%m][j];
			init = (minidx-1+m)%m;
			lim = init + 3;
		}

		cout << rt[0];
		for (i = 1; i < k; i++)
			cout << " " << rt[i];
		cout << endl;
		cout << min << endl;
	}
	return 0;
}

// Solver: RankSS
