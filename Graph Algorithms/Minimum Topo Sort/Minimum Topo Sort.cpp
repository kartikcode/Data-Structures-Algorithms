//The conditions and requirements of topo sort may change which would be reflected by the in degree
//This is a general example for implementation of Topo Sort
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m;
vector<ll>ad[100005];
ll in_deg[100005];
vector<ll>topo;
ll cnt = 0;
bool vis[100005];
void tpsort()
{
    ll cur = 0;
    multiset<ll> s;
    for (ll i = 1; i <= n; i++)
    {
        if (in_deg[i] == 0)
        {
            vis[i] = true;
            s.insert(i);
        }
    }
    while (!s.empty())
    {
        ll tp = *(s.begin());
        s.erase(tp);
        topo.pb(tp);
        for (auto x : ad[tp])
        {
            in_deg[x] = in_deg[x] - 1;
            if (vis[x] == false && in_deg[x] == 0)
            {
                vis[x] = true;
                s.insert(x);
            }
        }
        cnt++;
    }
}
int main()
{
    cin >> n >> m;
    memset(in_deg, 0, sizeof(in_deg));
    for (i = 0; i < m; i++)
    {
        cin >> j >> k;
        ad[j].pb(k);
        in_deg[k]++;
    }
    memset(vis, false, sizeof(vis));
    tpsort();
    return 0;
}