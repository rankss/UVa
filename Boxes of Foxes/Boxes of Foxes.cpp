#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int T, M, N, K, x1, y1, x2, y2, math, music, i, j, k;
	char graph[501][501];
	bool counted[501][501];
	cin >> T;
	while (T--)
	{
		cin >> M >> N >> K;
		for (i = 0; i < M; i++)
			for (j = 0; j < N; j++)
				cin >> graph[i][j];

		math = 0, music = 0;
		memset(counted, false, sizeof(counted));
		for (i = 0; i < K; i++)
		{
			cin >> x1 >> y1 >> x2 >> y2;
			x1--, x2--;
			y1 = M-y1, y2 = M-y2;
			for (j = y2; j <= y1; j++)
			{
				for (k = x1; k <= x2; k++)
				{
					if (!counted[j][k])
					{
						counted[j][k] = true;
						if (graph[j][k] == 'R') music++;
						else math++;
					}
				}
			}
		}
		cout << math << " " << music << endl;
	}
	return 0;
}

// Solver: RankSS
