#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>>ar;
    for(int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        ar.push_back({x,i});
    }
    sort(ar.begin(),ar.end());
    int l=0;
    int r=n-1;
    while(1)
    {
        if(l==r)break;
        if(ar[l].first+ar[r].first == k)
        {
            cout<<ar[l].second<<" "<<ar[r].second;
            return 0;
        }
        else if(ar[l].first+ar[r].first>k)r--;
        else if(ar[l].first+ar[r].first<k)l++;
    }
    cout<<"IMPOSSIBLE";
    return 0;
}
