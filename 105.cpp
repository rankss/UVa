#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int l, h, r, dp[10001] = {}, i, left = 10001, right = 0;
	memset(dp, 0, sizeof(dp));
	while (cin >> l >> h >> r)
	{
		if (l < left) left = l;
		if (r > right) right = r;
		for (i = l; i < r; i++)
			if (h > dp[i]) dp[i] = h;
	}
	for (i = left; i <= right; i++)
	{
		if (dp[i-1] != dp[i])
		{
			if (i > left) cout << " ";
			cout << i << " " << dp[i];
		}
	}
	cout << endl;
	return 0;
}

// Solver: RankSS
