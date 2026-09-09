// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
const int N=1005;
int m,k,d[N],s[N],mx=0,bst=0;
void solve()
{
        cin>>m>>k;
        for(int i=0;i<m;i++)cin>>d[i];
        for(int i=0;i<m;i++)cin>>s[i];
        int curr=0,t=0;
        for(int i=0;i<m;i++)
        {
                curr+=s[i];
                bst=max(bst,s[i]);
                if(curr<d[i])
                {
                        int nd=d[i]-curr,mul=(nd+bst-1)/bst;
                        t+=mul*k;
                        curr+=mul*bst;
                }
                assert(curr>=d[i]);
                curr-=d[i];
                t+=d[i];
        }
        cout<<t<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
