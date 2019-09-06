#include <iostream>
using namespace std;

int main()
{
	int k, n, m, x, y, vx, vy;
	while (cin >> k)
	{
		if (k == 0) break;
		cin >> n >> m;
		while (k--)
		{
			cin >> x >> y;
			vx = x - n;
			vy = y - m;
			if (vx == 0 || vy == 0) 
			{
				cout << "divisa" << endl;
				continue;
			}
			if (vy > 0)
			{
				if (vx > 0) cout << "NE" << endl;
				else cout << "NO" << endl;
			}
			else
			{
				if (vx > 0) cout << "SE" << endl;
				else cout << "SO" << endl;
			}
		}
	}
	return 0;
}

// Solver: RankSS
