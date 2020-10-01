#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <fstream>
#include <typeinfo>
#define ll long long
#define ld long double
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define I insert
#define pb push_back
#define F first
#define S second
#define endl "\n"
#define repi(i, a, b) for (ll i = a; i < b; i++)
#define repj(j, a, b) for (ll j = a; j < b; j++)
#define vi vector<int>
#define pii pair<int, int>
#define vpii vector<pii>
#define mod 1000000007
#define lim 100001
#define pi 3.14159265

using namespace std;
ll factorial(ll n) { return (n == 1 || n == 0) ? 1 : n * factorial(n - 1); }
int max3(int a, int b, int c) { return max(a, max(c, b)); }
int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    else
    {
        return gcd(b % a, a);
    }
}
ll power(ll a, ll n)
{
    if (n == 1)
        return a;
    else if (n == 0)
        return 1;
    else
    {
        ll r = power(a, n / 2);
        if (n % 2 == 0)
            return r * r;
        else
            return r * a * r;
    }
}
ll nCr(ll n, ll r) { return ((factorial(n)) / (factorial(n - r) * factorial(r))); }
void dfs(vector<vector<int>> &v, vi &check, int start)
{
    check[start - 1] = 1;
    repj(j, 0, v[start - 1].size())
    {
        if (!check[v[start - 1][j] - 1])
        {
            dfs(v, check, v[start - 1][j]);
        }
    }
}
bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
//works under 2 till 1e12

double newPrecision(double n)
{
    return floor(pow(10, 250) * n) / pow(10, 250);
}

ll f( ll arr[][3], ll pos, ll n, ll prev, ll rec[][3]){
    ll num = INT_MIN;
    if(pos == (n-1)){
        for (int i = 0; i < 3; i++)
        {
            if(i==prev)
                continue;
            num = max(num, arr[pos][i]);
        }
        return num;
    }
    /*if(rec[pos]!=-1){
        return rec[pos];
    }*/
    for (int i = 0; i < 3; i++)
    {
        if (i == prev)
            continue;
        if(rec[pos][i]!=-1){
            num = max(num, rec[pos][i]);
            continue;
        }
        rec[pos][i] = arr[pos][i] + f(arr, pos + 1, n, i, rec);
        num = max(num, rec[pos][i]);
    }
    return num;
}

    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        ll n;
        cin >> n;
        ll arr[n][3];
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < 3; j++)
            {
                cin >> arr[i][j];
            }
        }
        ll rec[n][3];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                rec[i][j] = -1;
            }
        }
        cout << f(arr, 0, n, -1, rec);

        return 0;
}
