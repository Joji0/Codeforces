#include <bits/stdc++.h>
using namespace std;
int n,x,y,p[1<<20];
void solve() 
{
        cin>>n>>x>>y;
        for(int i=0;i<n;i++)cin>>p[i];
        vector<int>a,b;
        for(int i=0;i<x;i++)a.push_back(p[i]);
        for(int i=x;i<y;i++)b.push_back(p[i]);
        for(int i=y;i<n;i++)a.push_back(p[i]);
        int mn=b[0],mnidx=0;
        for(int i=0;i<(int)b.size();i++)
        {
                if(b[i]<mn)
                {
                        mn=b[i],mnidx=i;
                }
        }
        vector<int>bb;
        for(int i=mnidx;i<(int)b.size();i++)bb.push_back(b[i]);
        for(int i=0;i<mnidx;i++)bb.push_back(b[i]);
        int pos=(int)a.size();
        for(int i=0;i<(int)a.size();i++)
        {
                if(a[i]>bb[0])
                {
                        pos=i;
                        break;
                }
        }
        vector<int>ans;
        for(int i=0;i<pos;i++)ans.push_back(a[i]);
        for(int i=0;i<(int)bb.size();i++)ans.push_back(bb[i]);
        for(int i=pos;i<(int)a.size();i++)ans.push_back(a[i]);
        assert((int)ans.size()==n);
        for(int i=0;i<n;i++)
        {
                cout<<ans[i]<<" \n"[i==n-1];
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
