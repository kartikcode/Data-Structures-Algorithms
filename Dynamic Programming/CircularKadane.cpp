 /*
 * Author: Hardik Sharma
*/
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repr(i,a,b) for(int i=a;i>=b;i--)
#define endl '\n'
#define pi 3.141592653589793238
#define mp make_pair
#define pb push_back
#define precise cout<<fixed<<setprecision(20)
#define ff first
#define ss second
#define uniq(v) v.resize(distance(v.begin(),unique(all(v))))
#define lb lower_bound
#define ub upper_bound
 
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pair<int,int>> vii;
const int inf=1e18;
const int N=100001;
int mod=1000000007;
//int mod=998244353;
 
int min(int a,int b){if(a<b) return a; else return b;}
int max(int a,int b){if(a>b) return a; else return b;}
int power(int a,int b){int res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int gcd(int p, int q){if(p%q==0) return q; else{return gcd(q,p%q);}} 
int mul(int a,int b){return ((a%mod)*(b%mod))%mod;}
int sub(int a,int b){return (((a-b)%mod)+mod)%mod;}
int kadane(vi a, int n) 
{ 
    int mmax = 0, ans = 0; 
    int i; 
    rep(i,0,n) 
    { 
        ans+=a[i]; 
        ans=max(ans,0); 
        mmax=max(ans,mmax);
    } 
    return mmax; 
} 

void solve()
{
    int n;
    cin>>n;
    vi v(n);
    rep(i,0,n)
    cin>>v[i];
    int sum=0;
    rep(i,0,n)
    sum+=v[i];
    int m1=kadane(v,n);
    rep(i,0,n)
    v[i]-=2*v[i];
    int m2=kadane(v,n);
    int ans=max(m1,sum+m2);
    cout<<ans<<endl;
}
 
signed main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    rep(i,0,t)
    {
    	//cout<<"Case #"<<t+1<<": ";
    	solve();
    }
    return 0;
}

