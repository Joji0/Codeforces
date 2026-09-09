#include <bits/stdc++.h>
using namespace std;
const int N=(1505*1505)>>1;
int trie[N][26],node=0,k;
string s,ok;
void solve()
{
        cin>>s>>ok>>k;
        int n=(int)s.size();
        int64_t ans=0;
        for(int i=0;i<n;i++)
        {
                int u=0,bad=0;
                for(int j=i;j<n;j++)
                {
                        int nw=s[j]-'a';
                        if(ok[nw]=='0')
                        {
                                bad++;
                        }
                        if(bad>k)break;
                        if(trie[u][nw]==0)
                        {
                                node++;
                                trie[u][nw]=node;
                                ans++;
                        }
                        u=trie[u][nw];
                }
        }
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
