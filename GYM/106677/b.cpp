#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n,d,x[105];
vector<int>a;
void solve()
{
        for(int i=1;i<=n;i++)
                cin>>x[i];
        a.clear();
        for(int i=1;i<=n;i++)
        {
                if(!a.empty()&&x[i]-a.back()<=d)
                        continue;
                else
                        a.push_back(x[i]+d);
        }
        cout<<a.size()<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(cin>>n>>d)
        {
                if(!n&&!d)
                        break;
                solve();
        }
        return 0;
}
