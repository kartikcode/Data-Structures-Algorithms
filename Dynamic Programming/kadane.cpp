// Author - Kartikeya Gupta
// Codeforces - kartikea_gupta
// Github - kartikcode

#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <fstream>
#include <typeinfo>
#include <sstream>
#define ll long long
#define ld long double
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define I insert
#define pb push_back
#define F first
#define S second
#define br "\n"
#define repi(i, a, b) for (ll i = a; i < b; i++)
#define repj(j, a, b) for (ll j = a; j < b; j++)
#define vi vector<int>
#define pii pair<int, int>
#define vpii vector<pii>
#define mod 1000000007
#define lim 100001
#define pi 3.14159265

using namespace std;

ll factorial(ll n)      {    return (n == 1 || n == 0) ? 1 : n * factorial(n - 1); }
ll gcd(ll a, ll b)      {    if (a == 0)  return b; else return gcd(b % a, a);}
ll power(ll a, ll n)    {    if (n == 1) return a;else if (n == 0) return 1; else{ ll r = power(a, n / 2);if (n % 2 == 0)    return r * r;    else    return r * a * r;}}
ll nCr(ll n, ll r)      {    return ((factorial(n)) / (factorial(n - r) * factorial(r))); }
double precise(double n){    return floor(pow(10, 250) * n) / pow(10, 250);}

int kadane(int a[], int n) 
{ 
    int maximum_i = INT_MIN, local_maximum = 0; 
  
    for (int i = 0; i < n; i++) 
    { 
        local_maximum = local_maximum + a[i]; 
        if (maximum_i < local_maximum) 
            maximum_i = local_maximum; 
  
        if (local_maximum < 0) 
            local_maximum = 0; 
    } 
    return maximum_i; 
} 
  

void solve(){
    ll n;
    cin>>n;
    ll a[n];
    repi(i,0,n){
        cin>>a[i];
    }
    int maxContiguousSum = kadane(a,n);
    return maxContiguousSum;
}

int main()
{    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
/*#ifndef ONLINE_JUDGE
    // for getting input from input.
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif*/
    ll t;
	t = 1;
	cin >> t;
	while(t--){
		solve();
	}
	//cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
	return 0;
}  
