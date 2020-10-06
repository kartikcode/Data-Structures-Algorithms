// Problem : I - Coins
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_i
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define rev(x) x.rbegin(), x.rend()
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repr(i,a,b) for(int i=a;i>=b;i--)
#define endl '\n'
#define pi 3.141592653589793238
#define mp make_pair
#define pb push_back
#define precise cout<<fixed<<setprecision(15)
#define ff first
#define ss second
#define T int t;cin>>t;rep(mmm,0,t)
#define uniq(v) v.resize(distance(v.begin(),unique(all(v))))

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pair<int,int>> vii;

const int N=100001;
int mod=1000000007;
//mod=998244353;

int min(int a,int b){if(a<b) return a; else return b;}
int max(int a,int b){if(a>b) return a; else return b;}
int power(int a,int b){int res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int gcd(int p, int q){if(p%q==0) return q; else{return gcd(q,p%q);}} 
int mul(int a,int b){return ((a%mod)*(b%mod))%mod;}
int sub(int a,int b){return (((a-b)%mod)+mod)%mod;}

void solve()
{
	int n;
	cin>>n;
	double dp[n+1]={0.0};
	dp[0]=1.0;
	rep(i,1,n+1)
	{
		double p;
		cin>>p;
		repr(j,i+1,0)
		{
			dp[j]*=(1.0-p);
			if(j)
			dp[j]+=dp[j-1]*p;
		}
	}
	double ans=0.0;
	rep(i,(n+1)/2,n+1)
	{
		ans+=dp[i];
	}
	precise<<ans;
}

signed main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0);cout.tie(0);
     solve();
    return 0;
}
