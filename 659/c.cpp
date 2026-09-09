// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int n;
int64_t m,a[N];
void solve()
{
        cin>>n>>m;
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a,a+n);
        int x=0;
        int64_t nw=1;
        vector<int>ans;
        while(m>0)
        {
                while(x<n&&nw==a[x])
                {
                        nw++;
                        x++;
                }
                if(m>=nw)
                {
                        m-=nw;
                        ans.push_back(nw);
                }
                else break;
                nw++;
        }
        cout<<(int)ans.size()<<'\n';
        for(int x:ans)cout<<x<<" ";
        cout<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
