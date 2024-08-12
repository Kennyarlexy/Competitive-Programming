// Fibonacci Series using Optimized Method
#include <bits/stdc++.h>
using namespace std;

#define ll long long

void multiply(ll F[2][2], ll M[2][2]);
void power(ll F[2][2], ll n);

ll mod = 1e9+7;

// Function that returns nth Fibonacci number
ll fib(ll n)
{
	ll F[2][2] = {{1, 1}, {1, 0}};
	if (n == 0)
		return 0;
	power(F, n - 1);

	return F[0][0];
}

// Optimized version of power() in method 4
void power(ll F[2][2], ll n)
{
	if(n == 0 || n == 1)
	return;
	ll M[2][2] = {{1, 1}, {1, 0}};
	
	power(F, n / 2);
	multiply(F, F);
	
	if (n % 2 != 0)
		multiply(F, M);
}

void multiply(ll F[2][2], ll M[2][2])
{
	ll x = ((F[0][0] % mod * M[0][0] % mod) + (F[0][1] * M[1][0] % mod)) % mod;
	ll y = ((F[0][0] % mod * M[0][1] % mod) + (F[0][1] * M[1][1] % mod)) % mod;
	ll z = ((F[1][0] % mod * M[0][0] % mod) + (F[1][1] * M[1][0] % mod)) % mod;
	ll w = ((F[1][0] % mod * M[0][1] % mod) + (F[1][1] % mod * M[1][1] % mod)) % mod;
	
	F[0][0] = x;
	F[0][1] = y;
	F[1][0] = z;
	F[1][1] = w;
}

// Driver code
int main()
{
	ll n; cin >> n;
	
	cout << fib(n+1);
	return 0;
}