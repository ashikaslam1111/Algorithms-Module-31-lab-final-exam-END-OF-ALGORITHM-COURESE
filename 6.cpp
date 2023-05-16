#include<bits/stdc++.h>
using namespace std;
const int N=3005;
vector<char> dp[N][N];
string s,t;
int main()
{
    //s="abracadabra";
    //t="avadakedavra";
    cin>>s;
    cin>>t;
    int n=s.size();
    int m=t.size();
    for(int i=0; i<=n; i++)dp[i][0]= {};
    for(int i=0; i<=m; i++)dp[0][i]= {};
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(s[i-1]==t[j-1])
            {
                for(auto k:dp[i-1][j-1] )dp[i][j].push_back(k);
                dp[i][j].push_back(s[i-1]);
            }
            else
            {
                if(dp[i-1][j].size()>dp[i][j-1].size())
                    for(auto k:dp[i-1][j] )dp[i][j].push_back(k);
                else
                    for(auto k:dp[i][j-1] )dp[i][j].push_back(k);
            }
        }
    }
    for(auto k:dp[n][m])cout<<k;
    return 0;
}
