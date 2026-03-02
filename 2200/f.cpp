#include <bits/stdc++.h>
using namespace std;
int n,m,x,y;
array<int64_t,2>sh[1<<20];
void solve() 
{
        cin>>n>>m;  
        vector<vector<int64_t>>byy(n+67);
        for(int i=0;i<n;i++)
        {
                cin>>x>>y;
                byy[y].push_back(x);
        }
        for(int i=0;i<m;i++)cin>>sh[i][0]>>sh[i][1];
        priority_queue<int64_t,vector<int64_t>,greater<int64_t>>pq; 
        int64_t mx=0,sum=0;
        vector<int64_t>bst(n+67,0);
        for(int i=n;i>=0;i--)
        {
                for(int64_t x:byy[i])
                {
                        pq.push(x);
                        sum+=x;
                }
                while((int)pq.size()>i+1)
                {
                        sum-=pq.top();
                        pq.pop();
                }
                if((int)pq.size()==i+1)
                {
                        mx=max(mx,sum);
                        bst[i+1]=sum-pq.top();
                }
                else
                {
                        bst[i+1]=sum;
                }
        }
        for(int i=1;i<=n+1;i++)bst[i]=max(bst[i],bst[i-1]);
        for(int i=0;i<m;i++)
        {
                int64_t xx=sh[i][0],yy=sh[i][1],ans=max(mx,xx+bst[yy+1]);
                cout<<ans<<" \n"[i==m-1];
        }
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
