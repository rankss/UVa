#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define size 751

int s[size];
void constructor(int n)
{
	int i;
	for (i = 0; i <= n; i++)
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

struct edge
{
	int x, y, w;
};
edge e[size*size];

bool cmp(edge a, edge b)
{
	return a.w < b.w;
}

int main()
{
	int t, n, m, a, b, i, j, k, count, x[size], y[size];
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (i = 1; i <= n; i++)
			cin >> x[i] >> y[i];
		constructor(n);
		count = 0;
		cin >> m;
		for (i = 0; i < m; i++)
		{
			cin >> a >> b;
			count+=merge(a,b);
		}
		if (count == n-1)
		{
			cout << "No new highways need" << endl;
			if (t) cout << endl;
			continue;
		}
		k = 0;
		for (i = 1; i <= n; i++)
		{
			for (j = i+1; j <= n; j++)
			{
				e[k].x = i; 
				e[k].y = j; 
				e[k].w = (x[j]-x[i])*(x[j]-x[i]) + (y[j]-y[i])*(y[j]-y[i]);
				k++;
			}
		}
		sort(e, e+k, cmp);
		for (i = 0; i < k; i++)
			if (merge(e[i].x, e[i].y))
				cout << e[i].x << " " << e[i].y << endl;
		if (t) cout << endl;
	}
	return 0;
}

// Solver: RankSS && mochithedog
