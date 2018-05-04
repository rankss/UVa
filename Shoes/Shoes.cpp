#include <iostream>
#include <cstring>
#include <sstream>
#include <climits>
using namespace std;

int main()
{
	string buffer;
	int queue[5][100000], count[5], a[100001];
	int i = 0, j, d, k, smallest;
	while (getline(cin, buffer))
	{
		istringstream ss;
		ss.str(buffer);
		j = 0;
		while (ss >> queue[i][j])
			j++;
		count[i++] = j;
		if (i%5 == 0)
		{
			for (k = 0; k < 5; k++)
				for (d = 0; d < count[k]; d++)
					a[queue[k][d]] = -1;
			smallest = INT_MAX;
			for (k = 0; k < 5; k++)
			{
				for (d = 0; d < count[k]; d++)
				{
					if (a[queue[k][d]] == -1)
						a[queue[k][d]] = d;
					else
					{
						a[queue[k][d]]+=d;
						smallest = min(smallest, a[queue[k][d]]);
					}
				}
			}
			i = 0;
			cout << smallest << endl;
		}
	}
	return 0;
}

// Solver: RankSS
