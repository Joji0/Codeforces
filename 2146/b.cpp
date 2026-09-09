#include <bits/stdc++.h>
using namespace std;
int n,m,l;
void solve()
{
        cin>>n>>m;
        vector<vector<int>>a(n);
        vector<int>b(m+1,0);
        for(int i=0;i<n;i++)
        {
                cin>>l;
                a[i].resize(l);
                for(int j=0;j<l;j++)
                {
                        cin>>a[i][j];
                        b[a[i][j]]++;
                }
        }
        for(int i=1;i<=m;i++)
        {
                if(!b[i])
                {
                        cout<<"NO\n";
                        return;
                }
        }
        int ans=1;
        for(int i=0;i<n;i++)
        {
                bool ok=true;
                for(int j=0;j<(int)a[i].size();j++)
                {
                        if(b[a[i][j]]==1)ok=false;
                }
                if(ok)ans++;
        }
        cout<<(ans>=3?"YES\n":"NO\n");
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
