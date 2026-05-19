#include <bits/stdc++.h>
using namespace std;
int n,k,a[1<<20],b[1<<20];
set<int>seen;
void solve()
{
        seen.clear();
        cin>>n>>k;
        for(int i=0;i<n;i++)cin>>a[i];
        bool dup=false;
        for(int i=0;i<n;i++)
        {
                cin>>b[i];
                if(seen.contains(b[i])&&b[i]!=-1)dup=true;
                seen.insert(b[i]);
        }
        if(dup)
        {
                cout<<"NO\n";
                return;
        }
        int cnt=0;
        map<int,int>mp;
        for(int i=0;i<k;i++)
        {
                mp[a[i]]++;
                if(mp[a[i]]==0)mp.erase(a[i]);
                if(b[i]==-1)cnt++;
                else
                {
                        mp[b[i]]--;
                        if(mp[b[i]]==0)mp.erase(b[i]);
                }
        }
        if((int)mp.size()!=cnt)
        {
                cout<<"NO\n";
                return;
        }
        for(int i=k;i<n;i++)
        {
                // cout<<"ERE\n";
                mp[a[i-k]]--;
                if(mp[a[i-k]]==0)mp.erase(a[i-k]);
                if(b[i-k]==-1)cnt--;
                else
                {
                        mp[b[i-k]]++;
                        if(mp[b[i-k]]==0)mp.erase(b[i-k]);
                }
                mp[a[i]]++;
                if(mp[a[i]]==0)mp.erase(a[i]);
                if(b[i]==-1)cnt++;
                else
                {
                        mp[b[i]]--;
                        if(mp[b[i]]==0)mp.erase(b[i]);
                }
                // for(auto&[el,cnt]:mp)
                // {
                //         cerr<<el<<" "<<cnt<<'\n';
                // }
                if((int)mp.size()!=cnt)
                {
                        cout<<"NO\n";
                        return;
                }
        }
        cout<<"YES\n";
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
