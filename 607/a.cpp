#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define inf 0x3f3f3f3f
int n,dp[100005][2];
pair<int,int>p[100005];
vector<int>c;
int f(int x){return lower_bound(c.begin(),c.end(),x)-c.begin()+1;}
void solve()
{
        cin>>n;
        for(int i=1;i<=n;i++)
                cin>>p[i].first>>p[i].second;
        sort(p+1,p+n+1,[](const auto& l, const auto& r){return l.first<r.first;});
        for(int i=1;i<=n;i++)
                c.push_back(p[i].first);
        // sort(c.begin(),c.end());
        memset(dp,0x3f,sizeof(dp));
        dp[1][0]=1;
        dp[1][1]=0;
        for(int i=2;i<=n;i++)
        {
                {//alive guy
                        auto it=lower_bound(c.begin(),c.end(),p[i].first-p[i].second);
                        if(it==c.begin())
                                dp[i][1]=i-1;
                        else
                        {
                                --it;
                                int idx=it-c.begin()+1;
                                if(!idx)
                                        dp[i][1]=i-1;
                                else
                                        dp[i][1]=dp[idx][1]+i-idx-1;
                                // cerr<<"i: "<<i<<" idx: "<<idx<<'\n';
                        }
                }
                {//this guy is dead
                        dp[i][0]=min(dp[i-1][0],dp[i-1][1])+1;
                }
        }
        // for(int i=1;i<=n;i++)
        //         cerr<<"i: "<<i<<" DP: "<<dp[i][0]<<" "<<dp[i][1]<<'\n';
        int ans=dp[n][1];
        for(int i=n-1;i>=1;i--)
                ans=min(ans,dp[i][1]+n-i);
        cout<<ans<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
