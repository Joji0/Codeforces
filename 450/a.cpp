#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n,m;
void solve()
{
        cin>>n>>m;
        queue<pair<int,int>>q;
        for(int i=1;i<=n;i++)
        {
                int a;cin>>a;
                q.push({a,i});
        }
        while(!q.empty())
        {
                auto[x,y]=q.front();
                q.pop();
                x-=m;
                if(x>0)
                        q.push({x,y});
                if(q.empty())
                        cout<<y<<'\n';
        }
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
