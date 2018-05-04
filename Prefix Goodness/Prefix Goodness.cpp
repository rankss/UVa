#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int cplen(string a, string b)
{
	int len = min(a.length(), b.length()), i = 0;
	while (a[i] == b[i] && i < len)
		i++;
	return i;
}

int main()
{
	int T, n, maxh, i, j, len, diff[50001], set[50001];
	string bin[50001];
	cin >> T;
	while (T--)
	{
		cin >> n;
		maxh = 0;
		for (i = 0; i < n; i++)
			cin >> bin[i];
		sort(bin, bin+n);

		for (i = 1; i < n; i++)
		{
			diff[i] = cplen(bin[i-1], bin[i]);
			set[i] = 2;
		}
		for (i = 1; i < n-1; i++)
		{
			for (j = i+1; j < n; j++)
			{
				if (diff[j] == 0)
					break;
				if (diff[i] <= diff[j])
					set[i]++;
				else
					break;
			}
			set[j] = max(set[j], set[i]+1);
		}

		for (i = 0; i < n; i++)
		{
			len = bin[i].length();
			maxh = max(maxh, diff[i]*set[i]);
			maxh = max(maxh, len);
		}
		cout << maxh << endl;
	}
	return 0;
}

// Solver: RankSS
