#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iomanip>

#define llong long long

//	a ^ x mod p
llong modp(llong a, llong x, llong p)
{
	a %= p;
	llong res;
	if (x == 0)
		return 1;
	if (x % 2 != 0)
	{
		res = (a * modp(a, x - 1, p)) % p;
	}
	else
	{
		res = modp(a * a, x / 2, p) % p;
	}
	return res;
}

//	решето Сундарама
int sundaram(int n)
{
	int *primes = new int[n];
	memset(primes, 0, sizeof(int) * n);
	for (int i = 1; 3 * i + 1 < n; i++)
	{
		int k;
		for (int j = 1; (k = i + j + 2*i*j) < n && j <= i; j++)
		{
			primes[k] = 1;
		}
	}
	for (int i = n - 1; i >= 0; i--)
		if (primes[i] == 0)
			return 2 * i + 1;
	delete[] primes;
	return 3;
}

int main(int argc, char *argv[])
{
	/*llong a, x, p;
	scanf("%lld %lld %lld", &a, &x, &p);
	printf("%lld\n", modp(a, x, p));
	scanf("%lld", &a);*/
	int n;
	scanf("%d", &n);
	printf("%d\n", sundaram(n));
	scanf("%d", &n);
	return 0;
}