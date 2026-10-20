#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n,a[105],b[105],p;
void solve()
{
        cin>>n;
        map<int,int>f;
        for(int i=1;i<=n;i++)
                cin>>a[i],f[a[i]]++;
        p=1;
        while(!f.empty())
        {
                vector<int>d;
                for(auto it=f.rbegin();it!=f.rend();++it)
                {
                        b[p++]=it->first;
                        it->second--;
                        if(!it->second)
                                d.push_back(it->first);
                }
                for(auto&x:d)
                        f.erase(x);
        }
        for(int i=1;i<=n;i++)
                cout<<b[i]<<" \n"[i==n];
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
