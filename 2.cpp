#include<bits/stdc++.h>
using namespace std;
//......... macros.........
#define ull  unsigned long long
#define ll long long
#define ld double
#define pii pair<int,int>
#define F first
#define S  second
#define vi vector<int>
#define vii vector<pii>
#define vc vector
#define nl cout<<"\n"

// ........ constant.......
const ll inf=1e18;
const ll mod = 1000000007;
//.......global.........
ll dpar[1000005];
int dp(int i)
{
    ll f =0;
    if(i>=1 && i<=6)
    {
        f=pow(2,i-1);
    }
    else
    {

        for(int j=1; j<=6; j++)
        {
            if(dpar[i-j]!=0)f+=dpar[i-j];
            else f+=dp(i-j);
        }
    }
    return dpar[i]=f%mod;
}
void solve()
{
    int n;
    cin>>n;
    cout<<dp(n);
}
int main()
{
    solve();
    return 0;
}
