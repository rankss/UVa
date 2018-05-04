#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool isPrime(int n)
{
	if (n == 1) return false;
	int i = 2;
	while (i*i <= n)
	{
		if (n%i == 0) return false;
		i++;
	}
	return true;
}

int main()
{
	int n, i, cnt, sr, b, size, p;
	vector<int> primes;
	for (i = 2; i < 12500; i++)
		if (isPrime(i))
			primes.push_back(i);
	size = primes.size();

	while (cin >> n)
	{
		cnt = 0;
		while (n != 0)
		{
			sr = INT_MAX;
			for (i = size-1; i >= 0; i--)
			{
				p = primes[i];
				if (n%p == 0)
				{
					sr = n%p;
					b = p;
					break;
				}
				if (n%p < sr)
				{
					sr = n%p;
					b = p;
				}
			}
			if (n == 1)
			{
				cnt++;
				break;
			}
			n-=b;
			cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}

// Solver: RankSS
