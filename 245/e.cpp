// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
int n,p=0,o=0,mx=1;
string s;
void solve()
{
        cin>>s;
        n=(int)s.size();
        for(int i=0;i<n;i++)
        {
                if(s[i]=='+')
                {
                        if(o)o--,p++;
                        else ++p,mx=max(mx,p);
                }
                else
                {
                        if(p)p--,o++;
                        else ++o,mx=max(mx,o);
                }
                mx=max({mx,o,p});
        }
        cout<<mx<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
