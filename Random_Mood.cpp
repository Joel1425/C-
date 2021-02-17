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
	double p;
	cin >> n >> p;
	double prob = 1.0;
	while (n > 0)
	{
		if (n % 2 == 1)
		{
			prob = prob * (1 - p) + (1 - prob) * p;
		}
		p = p * (1 - p) + (1 - p) * p;
		n /= 2;
	}
	cout << setprecision(10) << prob << "\n";
	return 0;
}
