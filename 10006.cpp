#include <iostream>
#include <algorithm>
using namespace std;

bool isPrime(int n)
{
	int i = 2;
	if (n == 1) return false;
	while (i*i <= n)
	{
		if (n%i == 0) return false;
		i++;
	}
	return true;
}

long int fermat(int a, int b, int n)
{
	long int p;
	if (b == 0) return 1;
	p = fermat(a, b/2, n)%n;
	p = (p*p)%n;
	return (b%2 == 0) ? p : (a*p)%n;
}

void carmichael(int primes[], int n)
{
	int i;
	if (primes[n])
	{
		cout << n << " is normal." << endl;
		return;
	}
	for (i = 2; i < n; i++)
	{
		if (__gcd(i,n) == 1 && fermat(i,n,n) != i)
		{
			cout << n << " is normal." << endl;
			return;
		}
	}
	cout << "The number " << n << " is a Carmichael number." << endl;
	return;
}

int main()
{
	int n, i, primes[65000] = {};
	for (i = 3; i < 65000; i++)
		if (isPrime(i))
			primes[i] = 1;
	while (cin >> n && n)
		carmichael(primes, n);
	return 0;
}

// Solver: RankSS & ajc21
