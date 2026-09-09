// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
#define lc u<<1
#define rc u<<1|1
const int N=100005;
int seg[N<<2],q,n;
string s;
void pull(int u){seg[u]=seg[lc]|seg[rc];}
void build(int u, int l, int r)
{
        if(l==r)
        {
                seg[u]=1<<(s[l]-'a');
                return;
        }
        int mid=(l+r)>>1;
        build(lc,l,mid);
        build(rc,mid+1,r);
        pull(u);
}
void upd(int u, int l, int r, int x, char c)
{
        if(l==r)
        {
                seg[u]=1<<(c-'a');
                return;
        }
        int mid=(l+r)>>1;
        if(x<=mid)upd(lc,l,mid,x,c);
        else upd(rc,mid+1,r,x,c);
        pull(u);
}
int qry(int u, int l, int r, int ql, int qr)
{
        if(ql>qr)return 0;
        if(ql<=l&&r<=qr)return seg[u];
        int ret=0,mid=(l+r)>>1;
        if(ql<=mid)ret|=qry(lc,l,mid,ql,qr);
        if(mid<qr)ret|=qry(rc,mid+1,r,ql,qr);
        return ret;
}
void solve()
{
        cin>>s>>q;
        n=(int)s.size();
        s='#'+s;
        build(1,1,n);
        while(q--)
        {
                int t;cin>>t;
                if(t==1)
                {
                        int pos;char c;cin>>pos>>c;
                        upd(1,1,n,pos,c);
                }
                else
                {
                        int l,r;cin>>l>>r;
                        cout<<__builtin_popcount(qry(1,1,n,l,r))<<'\n';
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
