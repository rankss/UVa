#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct point
{
	int x, y;
};
point temp;

double area(point ch[], int n)
{
	int i;
	double sum = 0;
	for (i = 1; i < n; i++)
		sum+=(ch[i-1].x*ch[i].y - ch[i].x*ch[i-1].y);
	return sum/2;
}

int cross(point c, point a, point b)
{
	return (a.x - c.x)*(b.y - c.y) - (b.x - c.x)*(a.y - c.y);
}

bool operator <(point a, point b)
{
	return cross(temp, a, b) < 0;
}

int main()
{
	int n, i, j, k = 0, a[21], len[21], min, nuked[21] = {};
	double ta = 0.0;
	bool safe;
	point map[21][201], ch[21][201];
	while (cin >> n && n != -1)
	{	
		for (i = 0; i < n; i++)
			cin >> map[k][i].x >> map[k][i].y;

		min = 0;
		for (i = 1; i < n; i++)
			if (map[k][i].x < map[k][min].x && map[k][i].y < map[k][min].y)
				min = i;
		temp = map[k][min];
		map[k][min] = map[k][0];
		map[k][0] = temp;
		sort(map[k]+1, map[k]+n);

		map[k][n] = temp;
		len[k] = 0;
		for (i = 0; i <= n; i++)
		{
			while (len[k] >= 2 && cross(ch[k][len[k]-2], ch[k][len[k]-1], map[k][i]) > 0)
				len[k]--;
			ch[k][len[k]++] = map[k][i];
		}
		k++;
	}

	while (cin >> temp.x >> temp.y)
	{
		for (i = 0; i < k; i++)
		{
			safe = false;
			if (nuked[i]) continue;
			for (j = 1; j < len[i] && !safe; j++)
				if (cross(ch[i][j-1], ch[i][j], temp) > 0)
					safe = true;
			if (!safe)
			{
				nuked[i] = 1;
				ta-=area(ch[i], len[i]);
			}
		}
	}
	printf("%.2f\n", ta);
	return 0;
}

// Solver: RankSS
