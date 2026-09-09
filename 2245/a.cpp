#include <bits/stdc++.h>
using namespace std;
int n,k;
string s;
void solve()
{
        cin>>n>>k>>s;
        if(k>n/2)
        {
                cout<<"-1\n";
                return;
        }
        int ans=0;
        for(int i=0;i<k;i++)ans+=bool(s[i]!='R');
        for(int i=n-k;i<n;i++)ans+=bool(s[i]!='L');
        cout<<ans<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
