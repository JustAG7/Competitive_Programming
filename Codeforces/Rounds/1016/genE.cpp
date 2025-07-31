#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll i, j;
	mt19937_64 rnd(1);

	ll n = 2e5, k = 1000;

	vector<ll> a(n);
	for (i = 0; i < n; i++)
		a[i] = i;

	int t = 1;
	cout << t << '\n';
	while (t--)
	{
		cout << n << ' ' << k << '\n';
		for (i = 0; i < n; i++)
			cout << a[i] << (i == n - 1 ? '\n' : ' ');
	}
}