// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
int n,m,k,a[55];
void solve()
{
        cin>>n>>m>>k;
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a,a+n,greater<>());
        int tot=0,r=k;
        if(k>=m)
        {
                cout<<"0\n";
                return;
        }
        for(int i=0;i<n;i++)
        {
                tot+=a[i];
                r--;
                if(tot+r>=m)
                {
                        cout<<i+1<<'\n';
                        return;
                }
        }
        cout<<"-1\n";
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
