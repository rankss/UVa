#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int arr[31][11], sorted[31];

bool inside(int a[], int b[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if(a[i] >= b[i]) 
			return false;
	}
	return true;
}

bool smaller(int a[], int b[], int n)
{
	int i;
	bool flag = false;
	for (i = 0; i < n; i++)
	{
		if (b[i] > a[i])
		{
			flag = true;
			break;
		}
		if (b[i] < a[i])
		{
			flag = false;
			break;
		}
	}
	return flag;
}

void sort2d(int k, int n)
{
	int minidx, i, j, used[31] = {};
	for (i = 1; i <= k; i++)
	{
		for (j = 1; j <= k; j++)
		{
			if (used[j] == 0)
			{
				minidx = j;
				break;
			}
		}
		for (j = 1; j <= k; j++)
		{
			if (smaller(arr[j], arr[minidx], n) && used[j] == 0)
			{
				minidx = j;
			}
		}
		used[minidx] = 1;
		sorted[i] = minidx;
	}
}

int main()
{
	int k, n, i, j, max, idx, dp[31] = {}, from[31] = {}, path[31] = {};
	while (cin >> k >> n)
	{
		memset(sorted, 1, sizeof(sorted));
		memset(dp,0,sizeof(dp));
		for (i = 1; i <= k; i++)
		{
			for (j = 0; j < n; j++)
			{
				cin >> arr[i][j];
			}
			sort(arr[i], arr[i]+n);
		}
		sort2d(k, n);
		max = 0;
		for (i = 1; i <= k; i++)
		{
			for (j = i+1; j <= k; j++)
			{
				if (inside(arr[sorted[i]], arr[sorted[j]], n))
				{
					if (dp[i]+1 > dp[j])
					{
						from[j] = i;
						dp[j] = dp[i] + 1;
						if (dp[j] > max) 
						{
							max = dp[j];
							idx = j;
						}
					}
				}
			}
		}
		cout << max+1 << endl;
		for (i = max; i >= 0; i--)
		{
			path[i] = sorted[idx];
			idx = from[idx];
		}
		for (i = 0; i <= max; i++)
		{
			cout << path[i];
			if (i != max) cout << " ";
		}
		cout << endl;
	}
	return 0;
}

// Solver: RankSS
