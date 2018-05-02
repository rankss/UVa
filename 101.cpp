#include <iostream>
using namespace std;

int world[26][26], count[26], location[26], position[26];

void reset(int n)
{
	int i, origpos = position[n], origloc = location[n], upper = count[origloc];
	for (i = origpos+1; i < upper; i++)
	{
		world[world[origloc][i]][0] = world[origloc][i];
		position[world[origloc][i]] = 0;
		location[world[origloc][i]] = world[origloc][i];
		count[world[origloc][i]] = 1;
	}
	count[origloc] = count[origloc] - i + origpos + 1;
}

void move(int a, int b)
{
	count[location[a]]--;
	world[location[b]][count[location[b]]] = a;
	position[a] = count[location[b]];
	count[location[b]]++;
	location[a] = location[b];
}

void pile(int a, int b)
{
	int i, origpos = position[a], origloc = location[a], upper = count[origloc];
	for (i = origpos; i < upper; i++)
	{
		world[location[b]][count[location[b]]] = world[origloc][i];
		position[world[origloc][i]] = count[location[b]];
		location[world[origloc][i]] = location[b];
		count[location[b]]++;
	}
	count[origloc] = count[origloc] - i + origpos;
}

int main()
{
	int n, a, b, i, j;
	string command, action;
	for (i = 0; i < 26; i++)
	{
		count[i] = 1;
		world[i][0] = i;
		location[i] = i;
		position[i] = 0;
	}
		
	cin >> n;
	while (cin >> command >> a >> action >> b)
	{
		if (location[a] == location[b]) continue;
		if (command.compare("move") == 0)
		{
			if (action.compare("onto") == 0)
			{
				reset(a);
				reset(b);
				move(a,b);
			}
			else
			{
				reset(a);
				move(a,b);
			}
		}
		else
		{
			if (action.compare("onto") == 0)
			{
				reset(b);
				pile(a,b);
			}
			else
			{
				pile(a,b);
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		cout << i << ':';
		for (j = 0; j < count[i]; j++)
			cout << " " << world[i][j];
		cout << endl;
	}
	return 0;
}

// Solver: RankSS
