#include <bits/stdc++.h>
#include "graph/LCA.hpp"
using namespace std;
int n,q;
LCA G;
int compute(const vector<int>&x)
{
        int s=x[0],t=x[1],f=x[2];
        int sf=G.dist(s,f),tf=G.dist(t,f),st=G.dist(s,t);
        return (sf+tf-st)/2+1;
}
void solve()
{
        cin>>n>>q;
        G.init(n+1);
        for(int i=2;i<=n;i++)
        {
                int p;cin>>p;
                G.add_edge(p,i);
        }
        G.build(1);
        while(q--)
        {
                int ans=-1<<30;
                vector<int>nw(3);
                for(int i=0;i<3;i++)cin>>nw[i];
                sort(nw.begin(),nw.end());
                do
                {
                        ans=max(ans,compute(nw));
                }while(next_permutation(nw.begin(),nw.end()));
                cout<<ans<<'\n';
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
