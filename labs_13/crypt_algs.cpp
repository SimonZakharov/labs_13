#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>

//	открытая экспонента
#define e 3

unsigned long gcd(long a, long b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

unsigned long invert(long a, long n)
{
	long t = 0, newt = 1, r = n, newr = a;
	while (newr != 0)
	{
		long q = r / newr;
		t = newt; newt = t - q * newt;
		r = newr; newr = r - q * newr;
	}
	if (r > 1)
	{
		printf("is not invertable");
		return -1;
	}
	if (t < 0)
		t += n;
	return t - 1;
}

//	a ^ x mod p
unsigned long modp(long a, long x, long p)
{
	a %= p;
	long res;
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
unsigned long sundaram(long n)
{
	bool *primes = new bool[n];
	memset(primes, false, sizeof(bool) * n);
	for (long i = 1; 3 * i + 1 < n; i++)
	{
		long k;
		for (long j = 1; (k = i + j + 2*i*j) < n && j <= i; j++)
		{
			primes[k] = true;
		}
	}
	for (long i = n - 1; i >= 0; i--)
		if (!primes[i])
			return 2 * i + 1;
	delete[] primes;
	return 3;
}

int main(int argc, char *argv[])
{
	srand(time(NULL));
	/*char a, x, p;
	scanf("%lld %lld %lld", &a, &x, &p);
	printf("%lld\n", modp(a, x, p));
	scanf("%lld", &a);*/
	printf("Block size = %d\n", sizeof(unsigned char));
	long q = rand() % 1000, p = rand() % 1000;
	q = 2579;
	p = 3557;
	unsigned long n = q * p;
	unsigned long phi_n = (q - 1) * (p - 1);
	//scanf("%d", &n);
	printf("q = %d\np = %d\n", q, p);
	printf("e = %d\n n = %d\n", e, n);
	unsigned long d = invert(e, phi_n);
	printf("d = %d\n", d);
	long message = 111111;
	long cypher = modp(message, e, n);
	long orig = modp(cypher, d, n);
	printf("%d -> %d -> %d\n", message, cypher, orig);
	/*FILE *input = fopen("input.dat", "rb");
	unsigned char message;
	while (!feof(input))
	{
		fread(&message, sizeof(unsigned char), 1, input);
		long cypher = modp(message, e, n);
		long orig = modp(cypher, d, n);
		printf("%c -> %d -> %c\n", message, cypher, orig);
	}
	fclose(input);*/
	scanf("%d", &q);
	return 0;
}