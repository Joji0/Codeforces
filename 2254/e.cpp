// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int n;
int64_t b[N];
void solve()
{
        cin>>n;
        int64_t sum=0;
        multiset<int64_t>ms;
        for(int i=1;i<=n;i++)
        {
                cin>>b[i];
                sum+=b[i];
                ms.insert(b[i]);
        }
        if(sum<1)
        {
                cout<<"-1\n";
                return;
        }
        vector<int64_t>ans;
        int64_t pref=0;
        for(int i=1;i<=n;i++)
        {
                auto it=ms.lower_bound(1-pref);
                if(it==ms.end())
                {
                        cout<<"-1\n";
                        return;
                }
                pref+=*it;
                ans.push_back(pref);
                ms.erase(it);
        }
        assert((int)ans.size()==n);
        for(int i=0;i<n;i++)cout<<ans[i]<<" \n"[i==n-1];
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
