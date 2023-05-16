#include<bits/stdc++.h>
using namespace std;
set<int>adj(long long int n)
{
    set<int>a;
    if(n<10 && n>1)
    {
        a.insert(n);
        return a;
    }
    else
    {
        while(n>=10)
        {
            long long int c=n%10;
            if(c>1)a.insert(c);
            n=n/10;
            if(n<10)
            {
                if(n<10 && n>1)
                {
                    a.insert(n);
                }
            }
        }
    }
    return a;
}
int digit(long long int number)
{
    int x;
    x=0;
    while(number>0)
    {
        number/=10;

        x+=1;
    }
    return x;
}
map<long long int,int> level;
int len;
int bfs(long long int n);
int main()
{
    long long int  n;
    cin>>len>>n;
    if(n==1 || n==0 || digit(n)>len)
    {
        cout<<-1;
        return 0;
    }
    cout<<bfs(n);
    return 0;
}
int bfs(long long int n)
{
    level[n]=0;
    if(digit(n)==len)return level[n];
    queue<long long int>q;
    q.push(n);
    while(!q.empty())
    {
        long long int head =q.front();
        q.pop();
        set<int>edge = adj(head);
        for (auto i:edge)
        {
            if(digit(head*i)==len)return level[head]+1;
            else
            {
                if (level.find(head*i) == level.end())
                {
                    level[head*i] =  level[head]+1;
                    q.push(head*i);
                }
            }
        }
    }
    return -1;
}
