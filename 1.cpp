#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=1005;
int grid[N][N];
bool visited[N][N];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool insidegrd(pair<int,int>src);
int dfs(pair<int,int>src);
bool not_block(pair<int,int>src);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        memset(visited, false, sizeof(visited));
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                cin>> grid[i][j];
                if(grid[i][j]==0)
                {
                    visited[i][j]=true;
                }
            }
        }
        int long_Deep =0;

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(visited[i][j]==false)
                {
                    long_Deep= max(long_Deep,dfs({i,j}));
                }

            }
        }
        cout<<long_Deep<<"\n";
    }
    return 0;
}
int dfs(pair<int,int>src)
{
    visited[src.first][src.second]=true;
    int total =grid[src.first][src.second];
    pair<int,int>head;
    head=src;
    int x=head.first;
    int y=head.second;
    for(int i=0; i<4; i++)
    {
        pair<int,int> newnode= {x+dx[i],y+dy[i]};
        if(insidegrd(newnode)&&not_block(newnode)
                &&visited[newnode.first][newnode.second]==false)
        {
            total = total+ dfs({newnode.first,newnode.second});

        }
    }
    return total;
}
bool insidegrd(pair<int,int>src)
{
    if(src.first<=n&&src.first>=0&&src.second<=m&&src.second>=0)return true;
    return false;
}
bool not_block(pair<int,int>src)
{
    if(grid[src.first][src.second]!=0)return true;
    return false;
}
