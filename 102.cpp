#include <iostream>
using namespace std;

int main()
{
	int bin[3][3], i = 0, total = 0, j, k, max, sum, chosen;
	int arrangement[6][3] = {{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};
	char color[3] = {'B', 'C', 'G'};
	while (cin >> bin[i][0] >> bin[i][2] >> bin[i][1])
	{
		total = total + bin[i][0] + bin[i][2] + bin[i][1];
		i++;
		if (i%3 == 0)
		{
			max = -1;
			for (j = 0; j < 6; j++)
			{
				sum = 0;
				for (k = 0; k < 3; k++)
				{
					sum+=bin[k][arrangement[j][k]];
				}
				if (sum > max)
				{
					max = sum;
					chosen = j;
				}
			}
			for (j = 0; j < 3; j++)
				cout << color[arrangement[chosen][j]];
			cout << " " << total-max << endl;
			i = 0;
			total = 0;
		}
	}
	return 0;
}

// Solver: RankSS
