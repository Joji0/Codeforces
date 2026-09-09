// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int n,t[N],pref[N],suff[N];
void solve()
{
        cin>>n;
        for(int i=1;i<=n;i++)cin>>t[i];
        for(int i=1;i<=n;i++)pref[i]=pref[i-1]+(bool)(t[i]>=0);
        for(int i=n;i>=1;i--)suff[i]=suff[i+1]+(bool)(t[i]<=0);
        int mn=N;
        for(int i=2;i<=n-1;i++)mn=min(mn,pref[i-1]+suff[i+1]+(bool)(t[i]==0));
        if(n==2)
        {
                bool ok1=bool(t[1]>=0),ok2=bool(t[2]<=0);
                mn=min(mn,ok1+ok2);
        }
        cout<<mn<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
