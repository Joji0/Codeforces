#include <bits/stdc++.h>
using namespace std;
/*
 * 0000 0011 1100 1111
 * 0010 0001 1110 1101
 * 1000 1011 0100 0111
 * 1010 1001 0110 0101
 *
 * 01 -> +2^0x +2^0y
 * 10 -> +2^1x
 * 11 -> +2^1y
 *
 * 14->1110
 */
int64_t n,q,x,y,d,ax,ay,pw,an;
string s;
string bt(int x)
{
        string ret;
        for(int i=0;i<n;i+=2)
        {
                // cerr<<i<<" " <<((1<<i)&x)<<'\n';
                // cerr<<i<<" " <<((1<<(i+1))&x)<<'\n';
                ret+=((1LL<<i)&x?"1":"0");
                ret+=((1LL<<(i+1))&x?"1":"0");
        }
        reverse(ret.begin(),ret.end());
        return ret;
}
void solve() 
{
       cin>>n>>q;        
       n*=2;
       while(q--)
       {
               cin>>s;
               if(s=="->")
               {
                       string g;
                       cin>>x>>y;
                       x--,y--;
                       pw=0,an=0;
                       for(int i=0;i<n/2;i++)
                       {
                               if(((1LL<<i)&x)&&((1LL<<i)&y))
                               {
                                        g+="10";
                               }
                               else if((1<<i)&x)
                               {
                                        g+="01";
                               }
                               else if((1<<i)&y)
                               {
                                        g+="11";
                               }
                               else
                               {
                                        g+="00";
                               }
                       }
                       for(int i=0;i<(int)g.size();i++)
                       {
                                if(g[i]-'0')
                                {
                                        an+=(1LL<<i);
                                }
                       }
                       cout<<an+1<<'\n';
               }
               else
               {
                        ax=0,ay=0,pw=0;
                        cin>>d;
                        d--;
                        string g=bt(d);
                        for(int i=n-2;i>=0;i-=2)
                        {
                                if(g[i]=='1'&&g[i+1]=='0')
                                {
                                        ax+=(1LL<<(pw));
                                }
                                else if(g[i]=='1'&&g[i+1]=='1')
                                {
                                        ay+=(1LL<<(pw));
                                }
                                else if(g[i]=='0'&&g[i+1]=='1')
                                {
                                        ax+=(1LL<<(pw));
                                        ay+=(1LL<<(pw));
                                }
                                pw++;
                        }
                        cout<<ax+1<<" "<<ay+1<<'\n';
               }
       }
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin >> tc;
        while(tc--)solve();
        return 0;
}
