#include <iostream>
#include <climits>
#include <cstring>
#include <algorithm>
using namespace std;

int kadane(int arr[], int n)
{
	int maxhere = arr[0], maxcurr = arr[0], i;
	for (i = 1; i < n; i++)
	{
		maxhere = max(arr[i], maxhere+arr[i]);
		maxcurr = max(maxcurr, maxhere);
	}
	return maxcurr;
}

int main()
{
	int n, i, j, l, r, arr[101][101], dp[101], sum, maxsum;
	while(cin >> n)
	{
		maxsum = INT_MIN;
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				cin >> arr[i][j];
		for (l = 0; l < n; l++)
		{
			memset(dp,0,sizeof(dp));
			for (r = l; r < n; r++)
			{
				for (i = 0; i < n; i++)
					dp[i]+=arr[i][r];
				sum = kadane(dp, n);
				if (sum > maxsum)
					maxsum = sum;
			}
		}
		cout << maxsum << endl;
	}
	return 0;
}

// Solver: RankSS
