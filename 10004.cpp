#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<int> list[], vector<bool> &visited, vector<bool> &color, int v)
{
	for (int u : list[v])
	{
		if (!visited[u])
		{
			visited[u] = true;
			color[u] = !color[v];
			if (!dfs(list, visited, color, u)) return false;
		}

		if (color[u] == color[v]) return false;
	}
	return true;
}

int main()
{
	int n, l, v1, v2;
	while (cin >> n)
	{
		if (n == 0) break;
		cin >> l;
		vector<int> list[n];
		vector<bool> visited(n, false);
		vector<bool> color(n);
		while (l--)
		{
			cin >> v1 >> v2;
			list[v1].push_back(v2);
			list[v2].push_back(v1);
		}
		visited[0] = true, color[0] = true;
		if (dfs(list, visited, color, 0))
			cout << "BICOLORABLE." << endl;
		else
			cout << "NOT BICOLORABLE." << endl;
	}
	return 0;
}

// Solver: RankSS
