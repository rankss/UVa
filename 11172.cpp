#include <iostream>
using namespace std;

int main()
{
	uint64_t a, b;
	int t;

	cin >> t;
	while (t--)
	{
		cin >> a >> b;
		if (a > b) cout << ">" << endl;
		else if (b > a) cout << "<" << endl;
		else cout << "=" << endl;
	}
	return 0;
}

// Solver: RankSS
