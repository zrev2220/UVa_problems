#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// shortcuts for "common" data types in contests
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

ll N, a, b;

ll f(ll x)
{
	return ((a * x * x) + b) % N;
}

pair<ll, ll> cycleFinding(ll x0)
{
	ll tortoise = f(x0), hare = f(f(x0));
	while (tortoise != hare)
	{
		tortoise = f(tortoise);
		hare = f(f(hare));
	}
	ll mu = 0;
	hare = x0;
	while (tortoise != hare)
	{
		tortoise = f(tortoise);
		hare = f(hare);
		++mu;
	}
	ll lambda = 1;
	hare = f(tortoise);
	while (tortoise != hare)
	{
		hare = f(hare);
		++lambda;
	}
	return pair<ll, ll>(mu, lambda);
}

int main()
{
	scanf("%lld %lld %lld\n", &N, &a, &b);
	while (N != 0ll)
	{
		pair<ll, ll> result = cycleFinding(0);
		printf("mu:%lld lambda:%lld\n", result.first, result.second);

		scanf("%lld %lld %lld\n", &N, &a, &b);
	}
	return 0;
}
