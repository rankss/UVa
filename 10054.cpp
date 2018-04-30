#include <iostream>
#include <cstring>
using namespace std;
#define size 51

int s[size];
void constructor(int n)
{
	int i;
	for (i = 0; i < n; i++)
		s[i] = i;
}

int find(int x)
{
	return (s[x] == x) ? x : s[x] = find(s[x]);
}

bool sameset(int x, int y)
{
	return (find(x) == find(y));
}

int merge(int x, int y)
{
	if (!sameset(x, y))
	{
		s[find(x)] = find(y);
		return 1;
	}
	return 0;
}

void dfs(int g[][size], int a)
{
	int i;
	for (i = 1; i < size; i++)
	{
		if (g[a][i])
		{
			g[a][i]--;
			g[i][a]--;
			dfs(g, i);
			cout << i << " " << a << endl;
		}
	}
}

int main()
{
	int g[size][size], d[size], t, n, a, b, c = 0, i, test;
	bool flag;
	cin >> t;
	while (t--)
	{
		memset(g, 0, sizeof(g));
		memset(d, 0, sizeof(d));
		cin >> n;
		constructor(size);
		for (i = 0; i < n; i++)
		{
			cin >> a >> b;
			g[a][b]++;
			g[b][a]++;
			d[a]++;
			d[b]++;
			merge(a,b);
		}
		cout << "Case #" << ++c << endl;
		flag = false;
		for (i = 1; i < size; i++)
		{
			if (d[i]%2 == 1) flag = true;
			if (d[i]) test = i;
		}
		if (flag)
			cout << "some beads may be lost" << endl;
		else
			dfs(g, test);
		if (t)
			cout << endl;
	}
	return 0;
}

// Solver: RankSS && mochithedog
