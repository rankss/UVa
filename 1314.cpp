#include <iostream>
#include <string>
using namespace std;

int solve(int len, string s)
{
	string c = s+s, shift;
	int idx = 0, i;
	for (i = 0; i < len; i++)
	{
		shift = c.substr(i, len);
		if (shift < s)
		{
			s = shift;
			idx = i;
		}
	}
	return idx;
}

int main()
{
	int t, len;
	string s;
	cin >> t;
	while (t--)
	{
		cin >> len >> s;
		cout << solve(len, s) << endl;
	}
	return 0;
}

// Solver: RankSS && mochithedog
