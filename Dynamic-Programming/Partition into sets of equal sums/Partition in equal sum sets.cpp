//checks if its possible to split elements of vector arr into two sets of equal sums
#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll,ll>
using namespace std;
bool findPartiion (vll arr, ll n)
{
	int sum = 0;
	int i, j;

	for (i = 0; i < n; i++)
		sum += arr[i];

	if (sum % 2 != 0)
		return false;

	bool part[sum / 2 + 1][n + 1];
	for (i = 0; i <= n; i++)
		part[0][i] = true;

	for (i = 1; i <= sum / 2; i++)
		part[i][0] = false;
	for (i = 1; i <= sum / 2; i++)
	{
		for (j = 1; j <= n; j++)
		{
			part[i][j] = part[i][j - 1];
			if (i >= arr[j - 1])
				part[i][j] = part[i][j] ||
				             part[i - arr[j - 1]][j - 1];
		}
	}
	return part[sum / 2][n];
}
int main()
{
	ll n;
	vll tp;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> tp[i];
	}
	if (findPartiion(tp, n))
	{
		cout << "POSSIBLE" << endl;
	}
	else
	{
		cout << "NOT POSSIBLE" << endl;
	}
	return 0;
}