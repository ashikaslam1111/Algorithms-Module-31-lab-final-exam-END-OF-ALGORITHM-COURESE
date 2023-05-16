#include<bits/stdc++.h>
using namespace std;
int num[101];
vector<set<int>>dp;
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)cin>>num[i];
    dp.resize(n+1);
    dp[1].insert(num[1]);
    for(int i=2; i<=n; i++)
    {
        dp[i].insert(num[i]);
        for(auto j:dp[i-1])
        {
            dp[i].insert(j);
            dp[i].insert(j+num[i]);
        }
    }
    cout<<dp[n].size()<<endl;
    for(auto i:dp[n])cout<<i<<" ";
    return 0;
}
