#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using uint=unsigned int;
uint n;
bool pal(string s)
{
        int sz=s.size(),ok=1;
        for(int i=0;i<sz/2;i++)
        {
                ok&=s[i]==s[sz-i-1];
        }
        if(sz&1)ok&=s[sz/2]=='0';
        return ok;
}
void solve()
{
        cin>>n;
        string o;
        for(int i=0;i<bit_width(n);i++)
        {
                if(n>>i&1)o+='1';
                else o+='0';
        }
        if(pal(o))
        {
                cout<<"YES\n";
                return;
        }
        for(int i=0;i<100;i++)
        {
                o+='0';
                if(pal(o))
                {
                        cout<<"YES\n";
                        return;
                }
        }
        cout<<"NO\n";
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
// 6->0110, x=0010=2, f(x) = 0100 ->x^f(x)=0110
// 10->1010, x=
