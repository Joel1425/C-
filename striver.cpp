#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define int long long int
#define MOD 1e9+7
int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("Console.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
	IOS;
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		v[i] = i;
	}
	for (auto i : v)
	{
		cout << i << " ";
	}
	return 0;
}
