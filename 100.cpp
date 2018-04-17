#include <iostream>
#include <cstring>
using namespace std;

int conjecture(int n)
{
	int count = 0;
	while (n > 1)
	{
		if (n%2) n = 3*n + 1;
		else n = n>>1;
		count++;
	}
	return count+1;
}

int main()
{
	int i, I, J, x, y, DP[1000000], max, temp;
	memset(DP, 0, sizeof(DP));
	while (cin >> I >> J)
	{
		if (I > J)
		{
			x = J;
			y = I;
		}
		else
		{
			x = I;
			y = J;
		}
		max = 0;
		for (i = x; i <= y; i++)
		{
			if (DP[i] == 0)
				DP[i] = conjecture(i);
			if (DP[i] > max)
				max = DP[i];
		}
		cout << I << " " << J << " " << max << endl;
	}
	return 0;
}

// Solver: RankSS
