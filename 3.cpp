#include<bits/stdc++.h>
using namespace std;
long long int dp[1000005];
long long int num[105];
const long long int mod = 1000000007;
int main()
{
    int n,k;
    cin>>n>>k;
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(long long int i=1; i<=n; i++)cin>>num[i];
    for(long long int i=1; i<=k; i++)
    {
        long long  int sum =0;
        for(long long int j=1; j<=n; j++)
        {

            if(i-num[j]>=0)
            {
                sum +=dp[i-num[j]];
            }
        }
        dp[i] = sum%mod;
    }
    cout<<dp[k];
    return 0;
}
