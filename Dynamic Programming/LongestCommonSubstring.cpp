#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        int x = n, y = m;
        string s1=S1, s2=S2;
        //declaring the memoization table;
        int dp[x+1][y+1];
        for(int i=0;i<=x;i++) dp[i][0] = 0;
        for(int i=0;i<=y;i++) dp[0][i] = 0;
        
        //bottom up filling 
        int ans = 0;
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                //choice diagrams
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    ans = max(ans,dp[i][j]);
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        
        //return the answer
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends