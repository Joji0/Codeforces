#include <bits/stdc++.h>
using namespace std;
int n;
string s;
void solve() 
{
        cin>>n>>s;
        int ptra=n/2,ptrb=n/2;
        while(ptra>=0&&s[ptra]==s[n/2])
        {
                ptra--;
        }
        while(ptrb<n&&s[ptrb]==s[n/2])
        {
                ptrb++;
        }
        int ans=ptrb-ptra-1;
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
