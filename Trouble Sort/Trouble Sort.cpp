#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int arr1[100000], arr2[100000];
	int T, N, i, CASE, c1, c2, idx;
	bool flag;
	cin >> T;
	while (T--)
	{
		cin >> N;
		i = 0, c1 = 0, c2 = 0;
		memset(arr1, -1, sizeof(arr1));
		memset(arr2, 0, sizeof(arr2));
		while (i < N)
		{
			if (!(i++%2))
				cin >> arr1[c1++];
			else
				cin >> arr2[c2++];
		}
		sort(arr1, arr1+c1);
		sort(arr2, arr2+c2);

		flag = true;
		for (i = 0; i < c2 && flag; i++)
		{
			if (arr2[i] < arr1[i])
				flag = false, idx = i*2;
			if (arr2[i] > arr1[i+1] && arr1[i+1] != -1)
				flag = false, idx = i*2 + 1;
		}
		if (flag)
			cout << "Case #" << ++CASE << ": OK" << endl;
		else
			cout << "Case #" << ++CASE << ": " << idx << endl;
	}
	return 0;
}

// Solver: RankSS
