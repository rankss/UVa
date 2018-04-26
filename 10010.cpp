#include <iostream>
using namespace std;

char lower(char a)
{
	if (a >= 65 && a <= 90) return char(a+32);
	return a;
}

int main()
{
	int c, m, n, w, i, j, k, x, y, z, flag, eow, d[8][2] = {{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
	char input[51][51], ch, word[51];
	cin >> c;
	while (c--)
	{
		cin >> m >> n;
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				cin >> ch;
				input[i][j] = lower(ch);
			}
		}
		cin >> w;
		while (w--)
		{
			cin >> word;
			for (i = 0; word[i] != '\0'; i++)
				word[i] = lower(word[i]);
			eow = i;
			flag = 1;
			for (i = 0; i < m && flag; i++)
			{
				for (j = 0; j < n && flag; j++)
				{
					for (k = 0; k < 8 && flag; k++)
					{
						x = i, y = j, z = 0;
						while (input[x][y] == word[z] && flag)
						{
							x+=d[k][0], y+=d[k][1], z++;
							if (z == eow)
							{
								cout << i+1 << " " << j+1 << endl;
								flag = 0;
							}
							if (x < 0 || y < 0 || x >= m || y >= n) break;
						}
					}
				}
			}
		}
		if (c) cout << endl;
	}
	return 0;
}

// Solver: RankSS && mochithedog
