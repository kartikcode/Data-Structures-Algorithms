#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define loop(x,n) for(int x = 0; x < n; ++x)
#define ll long long int
typedef vector<int> vi; 
typedef pair<int, int> pi; 
#define pb push_back 
int binarysearch(int a[], int x, int l, int r) 
{ 
    if (r >= l) { 
        int m = l + (r - l) / 2; 
        if (a[m] == x) return m; 
        if (a[m] > x) return binarysearch(a, x, l, m-1); 
        else return binarysearch(a,x, m + 1, r); 
    }
    return -1; 
} 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[5]={0,1,2,3,4};
    int x=binarysearch(a,4,0,4);
    if(x==-1)cout<<"Element not present";
    else cout<<"Element present at index : "<<x;
    
    return 0;
}