#include <cstdio>
#include <cmath>

int main()
{
	double n, p, a;
	while (scanf("%lf\n%lf", &n, &p) != EOF)
	{
		a = (double)pow(M_E, log(p)/n);
		printf("%.0lf\n", a);
	}
	return 0;
}

// Solver: RankSS
