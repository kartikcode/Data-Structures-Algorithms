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

bool anyTwo(int a, int b, int c){
    if((a>=0) and (b>=0)) return true;
    if((c>=0) and (b>=0)) return true;
    if((a>=0) and (c>=0)) return true;
    return false;
}

int locMaximum (int a[], int l, int r, int n){
    int ind = l + (r-l)/2;
    if(r==1){
        return 1;
    }
    if(l==n-1) return n;
    if(a[ind]>a[ind-1] and a[ind]>a[ind+1]){
        return ind+1;
    }
    else if(a[ind]<a[ind-1]){
        return locMaximum(a,l,ind-1,n);
    }
    else if(a[ind]<a[ind+1]){
        return locMaximum(a,ind+1,r,n);
    }
}

void solve(){
    int n,num;
    cin>>n>>num;
    int a[n];
    repi(i,0,n){
        cin>>a[i];
    }
    int maxIndex = locMaximum(a,0,n,n);
    if(a[maxIndex]==num){
        cout<<maxIndex+1<<endl;
        return;
    }
    

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