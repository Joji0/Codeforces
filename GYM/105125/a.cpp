#include <bits/stdc++.h>
using namespace std;
int n,m,a[1<<17];
void solve()
{
        map<vector<int>,int>mp;
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
                vector<int>nw(3);
                for(int j=0;j<3;j++)
                {
                        cin>>nw[j];
                }
                sort(nw.begin(),nw.end());
                nw.erase(unique(nw.begin(),nw.end()),nw.end());
                mp[nw]++;
        }
        vector<vector<int>>o;
        for(auto&[cl,cnt]:mp)if(cnt&1)o.push_back(cl);
        if(o.empty())
        {
                cout<<"NO\n";
                return;
        }
        cout<<"YES\n";
        mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
        for(;;)
        {
                for(int i=1;i<=n;i++)a[i]=rng()%2;
                int sum=0;
                for(auto&cl:o)
                {
                        int trm=1;
                        for(int x:cl)trm&=a[x];
                        sum^=trm;
                }
                if(sum&1)
                {
                        for(int i=1;i<=n;i++)cout<<a[i]<<" \n"[i==n];
                        return;
                }
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
