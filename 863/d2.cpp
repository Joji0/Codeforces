// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
mt19937 rng(676767);
const int N=200005;
int n,q,m,a[N],treap[N],pr[N],lc[N],rc[N],sub[N],lz[N],root=0,node=0;
int make(int v)
{
        int u=++node;
        treap[u]=v;
        pr[u]=rng();
        lc[u]=rc[u]=0;
        sub[u]=1;
        lz[u]=0;
        return u;
}
void pull(int u)
{
        if(u)sub[u]=sub[lc[u]]+sub[rc[u]]+1;
}
void push(int u)
{
        if(!u||!lz[u])return;
        swap(lc[u],rc[u]);
        if(lc[u])lz[lc[u]]^=1;
        if(rc[u])lz[rc[u]]^=1;
        lz[u]=0;
}
void split(int u, int k, int &x, int &y)
{
        if(!u)
        {
                x=y=0;
                return;
        }
        push(u);
        int lft=sub[lc[u]];
        if(lft+1<=k)
        {
                x=u;
                split(rc[u],k-(lft+1),rc[u],y);
        }
        else
        {
                y=u;
                split(lc[u],k,x,lc[u]);
        }
        pull(u);
}
void merge(int &u, int x, int y)
{
        push(x),push(y);
        if(!x||!y)
        {
                u=(x?x:y);
                return;
        }
        if(pr[x]>pr[y])
        {
                u=x;
                merge(rc[u],rc[x],y);
        }
        else
        {
                u=y;
                merge(lc[u],x,lc[y]);
        }
        pull(u);
}
void cycle(int l, int r)
{
        int a,b,c,d,e,f;
        split(root,l-1,a,b);
        split(b,r-l+1,c,d);
        split(c,r-l,e,f);
        merge(a,a,f);
        merge(a,a,e);
        merge(root,a,d);
}
void rev(int l, int r)
{
        int a,b,c;
        split(root,l-1,a,b);
        split(b,r-l+1,b,c);
        lz[b]^=1;
        merge(a,a,b);
        merge(root,a,c);
}
void print(int idx)
{
        int a,b,c;
        split(root,idx-1,a,b);
        split(b,1,b,c);
        cout<<treap[b]<<" ";
        merge(a,a,b);
        merge(root,a,c);
}
void solve()
{
        cin>>n>>q>>m;
        for(int i=1;i<=n;i++)
        {
                cin>>a[i];
                merge(root,root,make(a[i]));
        }
        while(q--)
        {
                int t,l,r;cin>>t>>l>>r;
                if(t==1)cycle(l,r);
                else rev(l,r);
        }
        for(int i=0;i<m;i++)
        {
                int idx;cin>>idx;
                print(idx);
        }
        cout<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
