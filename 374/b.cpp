#include <bits/stdc++.h>
using namespace std;
string s;
void solve()
{
        cin>>s;
        int n=(int)s.size();
        int64_t ans=1,cnt=0;
        for(int i=0;i<n-1;i++)
        {
                int nw=s[i]-'0',nxt=s[i+1]-'0';
                if(nw+nxt==9)cnt++;
                else
                {
                        if(!(cnt&1))ans*=cnt/2+1;
                        cnt=0;
                }
        }
        if(!(cnt&1))ans*=cnt/2+1;
        cout<<ans<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
