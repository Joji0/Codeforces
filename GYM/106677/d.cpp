#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll s,k,ans;
map<int,int>freq;
vector<int>a;
void solve()
{
        a.clear();
        freq.clear();
        int prv=s;
        ans=s;
        freq[s]++;
        a.push_back(s);
        for(int i=2;i<=k;i++)
        {
                prv=freq[prv];
                freq[prv]++;
                ans=prv;
                a.push_back(ans);
        }
        // cout<<"ANS: "<<ans<<'\n';
        for(auto&x:a)
                cout<<x<<" ";
        cout<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        // int tc=1;
        // cin>>tc;
        while(cin>>s>>k)
        {
                if(!s&&!k)
                        break;
                solve();
        }
        return 0;
}
