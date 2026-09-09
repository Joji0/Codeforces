#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int k;
void solve()
{
        cin>>k;
        vector<array<int,2>>ans;
        int curr=0,mx=0;
        while(k>0)
        {
                int l=0,r=505,tk=-1;
                while(l<=r)
                {
                        int md=(l+r)>>1;
                        if(md*(md-1)/2>k)r=md-1;
                        else
                        {
                                tk=md;
                                l=md+1;
                        }
                }
                assert(tk!=-1);
                k-=tk*(tk-1)/2;
                assert(k>=0);
                // if(ans.empty())for(int i=0;i<tk;i++)ans.push_back({i,0});
                // else
                // {
                //         assert(curr<ans.size());
                //         for(int i=0;i<tk;i++)ans.push_back({ans[curr][0],i+1});
                //         curr++;
                // }
                for(int i=0;i<tk;i++)
                {
                        ans.push_back({curr,mx});
                        mx++;
                }
                curr++;
                // cerr<<"TK: "<<tk<<'\n';
                // cerr<<"K: "<<k<<'\n';
        }
        assert(ans.size()<=500);
        cout<<ans.size()<<'\n';
        for(auto[x,y]:ans)cout<<x<<" "<<y<<'\n';
        // cerr<<ans.size()<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
