// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int n,q,pref1[N],pref2[N];
string s,t;
void solve()
{
        cin>>n>>q>>s>>t;
        s='#'+s,t='#'+t;
        for(int i=1;i<=n;i++)
        {
                pref1[i]=pref1[i-1]+(bool)(s[i]=='0'&&t[i]=='1');
                pref2[i]=pref2[i-1]+(bool)(s[i]=='1'&&t[i]=='0');
        }
        while(q--)
        {
                int l,r;cin>>l>>r;
                int cnt1=pref1[r]-pref1[l-1],cnt2=pref2[r]-pref2[l-1];
                if(cnt1*2<=(r-l+1)&&cnt2*2<=(r-l+1))cout<<"YES\n";
                else cout<<"NO\n";
        }
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
