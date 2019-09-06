#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int t, employee[3], i = 0;
	cin >> t;
	while (t--)
	{
		cin >> employee[0] >> employee[1] >> employee[2];
		sort(employee, employee+3);
		cout << "Case " << ++i << ": " << employee[1] << endl;
	}
	return 0;
}

// Solver: RankSS
