#include <bits/stdc++.h>
using namespace std;
int q;
string s;
bitset<1<<17>B[26];
void solve()
{
        cin>>s>>q;
        for(int i=0;i<(int)s.size();i++)B[s[i]-'a'][i]=1;
        while(q--)
        {
                int t;cin>>t;
                if(t==1)
                {
                        int i;char c;cin>>i>>c;i--;
                        B[s[i]-'a'][i]=0,B[c-'a'][i]=1;
                        s[i]=c;
                }
                else
                {
                        int l,r;string y;cin>>l>>r>>y;l--,r--;
                        int lst=r-(int)y.size()+1;
                        if(lst<l)
                        {
                                cout<<"0\n";
                                continue;
                        }
                        bitset<1<<17>ans;
                        ans.set();
                        for(int i=0;i<(int)y.size();i++)
                        {
                                char nw=y[i];
                                ans&=(B[nw-'a']>>i);
                        }
                        ans>>=l;
                        ans<<=((1<<17)-(lst-l+1));
                        cout<<ans.count()<<'\n';
                }
        }
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
