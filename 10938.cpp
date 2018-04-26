#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int n, a, b, i, j, l, e, p, m;
	vector< vector<int> > paths;
	vector<bool> visited;
	vector<int> prev, path;
	queue<int> bfs;
	while (cin >> n && n)
	{
		paths.resize(n);
		for (i = 0; i < n-1; i++)
		{
			cin >> a >> b;
			paths[a-1].push_back(b);
			paths[b-1].push_back(a);
		}
		cin >> l;
		for (i = 0; i < l; i++)
		{
			cin >> a >> b;
			prev.clear();
			visited.clear();
			path.clear();
			for (j = 0; j < n; j++) 
			{
				prev.push_back(-1);
				visited.push_back(false);
			}
			bfs.push(a);
			visited[a-1] = true;
			while (!bfs.empty())
			{
				e = bfs.front();
				for (j = 0; j < paths[e-1].size(); j++)
				{
					if (!visited[paths[e-1][j]-1])
					{
						bfs.push(paths[e-1][j]);
						visited[paths[e-1][j]-1] = true;
						prev[paths[e-1][j]-1] = e;
					}
				}
				bfs.pop();
			}
			p = prev[b-1];
			path.push_back(b);
			while (p != -1)
			{
				path.push_back(p);
				p = prev[p-1];
			}
			m = path.size()/2;
			if (path.size()%2 == 1)
				cout << "The fleas meet at " << path[m] << "." << endl;
			else
			{
				if (path[m-1] < path[m])
					cout << "The fleas jump forever between " << path[m-1] << " and " << path[m] << "." << endl;
				else
					cout << "The fleas jump forever between " << path[m] << " and " << path[m-1] << "." << endl;
			}
		}
		paths.clear();
	}
	return 0;
}

// Solver: RankSS && mochithedog
