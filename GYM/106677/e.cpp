#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define inf 0x3f3f3f3f3f3f3f3f
int n;
pair<ll,ll>p[100005];
void solve()
{
        ll mn=inf;
        bool ok=0;
        for(int i=1;i<=n;i++)
        {
                cin>>p[i].first>>p[i].second;
                if(p[i].second>0)
                {
                        mn=min(mn,p[i].first);
                        ok=1;
                }
        }
        sort(p+1,p+n+1,[](const auto& l, const auto& r){return l.first<r.first;});
        int l=1,r=n;
        ll ans=0,ac=0;
        vector<ll>a;
        while(l<=r)
        {
                ans+=p[l].first;
                ac+=p[l].second;
                a.push_back(p[l].first);
                while(r>l&&ac>0)
                {
                        ac+=p[r].second;
                        ac--;
                        r--;
                }
                l++;
        }
        sort(a.rbegin(),a.rend());
        for(int i=0;i<min((ll)a.size(),ac);i++)
                ans-=a[i];
        cout<<max(ans,(ok?mn:0))<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        // int tc=1;
        // cin>>tc;
        while(cin>>n)
        {
                if(!n)
                        break;
                solve();
        }
        return 0;
}
