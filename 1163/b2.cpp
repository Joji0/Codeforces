#include <bits/stdc++.h>
using namespace std;
int n,u[1<<17],cnt[1<<17];
map<int,int>mp;
void solve() 
{
        cin>>n;
        for(int i=0;i<n;i++)
        {
                cin>>u[i];
                cnt[u[i]]++;
        }
        for(int i=0;i<1<<17;i++)if(cnt[i])mp[cnt[i]]++;
        int ans=-1;
        for(int i=n-1;i>=0;i--)
        {
                if((int)mp.size()==1&&(mp.begin()->first==1||mp.begin()->second==1))
                {
                        ans=i+1;
                        goto DONE;
                }
                if((int)mp.size()==2)
                {
                        auto it=mp.begin();
                        pair<int,int>p1=*it;
                        it++;
                        pair<int,int>p2=*it;
                        // cerr<<p1.first<<" "<<p1.second<<'\n';
                        // cerr<<p2.first<<" "<<p2.second<<'\n';
                        if(p1.second==1)
                        {
                                if(p1.first-1==p2.first||p1.first==1)
                                {
                                        ans=i+1;
                                        goto DONE;
                                }
                        }
                        else if(p2.second==1)
                        {
                                if(p2.first-1==p1.first||p2.first==1)
                                {
                                        ans=i+1;
                                        goto DONE;
                                }
                        }
                        swap(p1,p2);
                        if(p1.second==1)
                        {
                                if(p1.first-1==p2.first||p1.first==1)
                                {
                                        ans=i+1;
                                        goto DONE;
                                }
                        }
                        else if(p2.second==1)
                        {
                                if(p2.first-1==p1.first||p2.first==1)
                                {
                                        ans=i+1;
                                        goto DONE;
                                }
                        }
                }
                mp[cnt[u[i]]]--;
                if(mp[cnt[u[i]]]==0)mp.erase(cnt[u[i]]);
                cnt[u[i]]--;
                if(cnt[u[i]]>0)
                {
                        mp[cnt[u[i]]]++;
                }
                if(mp[cnt[u[i]]]==0)mp.erase(cnt[u[i]]);
        }
DONE:
        cout<<max(ans,1)<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
