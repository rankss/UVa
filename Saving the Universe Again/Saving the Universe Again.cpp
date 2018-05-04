#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int T, D, dmg, total, CASE = 0, dp[31], i, max, idx, sc, cc, swaps;
	string P;
	cin >> T;
	while (T--)
	{
		cin >> D >> P;
		sc = 0, cc = 0;
		dmg = 1, total = 0;
		memset(dp, 0, sizeof(dp));
		for (i = 0; i < P.length(); i++)
		{
			if (P[i] == 'C')
			{
				dmg+=dmg;
				cc++;
			}
			if (P[i] == 'S')
			{
				total+=dmg;
				dp[i] = dmg;
				sc++;
			}
		}
		if (sc > D)
		{
			cout << "CASE #" << ++CASE << ": IMPOSSIBLE" << endl;
			continue;
		}
		if (total <= D)
		{
			cout << "CASE #" << ++CASE << ": " << 0 << endl;
			continue;
		}
		swaps = 0;
		while (total > D)
		{
			max = -1;
			for (i = 0; i < 31; i++)
				if (dp[i] > max)
					max = dp[i], idx = i;
			dp[idx-1] = max/2;
			total-=dp[idx-1];
			dp[idx] = 0;
			swaps++;
		}
		cout << "CASE #" << ++CASE << ": " << swaps << endl;
	}
	return 0;
}

// Solver: RankSS
