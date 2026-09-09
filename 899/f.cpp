// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m;
string s;
mt19937 rng(676767);
int treap[N],pr[N],lc[N],rc[N],sub[N],root=0,node=0;
int64_t mask[N];
int get(char c)
{
        if('a'<=c&&c<='z')return c-'a';
        else if('A'<=c&&c<='Z')return c-'A'+26;
        else return c-'0'+52;
}
char remap(int v)
{
        if(0<=v&&v<=25)return (char)(v+'a');
        else if(v<=51)return (char)((v-26)+'A');
        else return (char)((v-52)+'0');
}
int make(int val)
{
        int u=++node;
        treap[u]=val;
        pr[u]=rng();
        lc[u]=rc[u]=0;
        sub[u]=1;
        mask[u]=(1ULL<<val);
        return u;
}
void pull(int u)
{
        if(!u)return;
        sub[u]=sub[lc[u]]+sub[rc[u]]+1;
        mask[u]=(1ULL<<treap[u]);
        if(lc[u])mask[u]|=mask[lc[u]];
        if(rc[u])mask[u]|=mask[rc[u]];
}
void split(int u, int k, int &x, int &y)
{
        if(!u)
        {
                x=y=0;
                return;
        }
        int lft=sub[lc[u]]+1;
        if(lft<=k)
        {
                x=u;
                split(rc[u],k-lft,rc[u],y);
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
int rem(int u, int c)
{
        if(!u)return 0;
        if(!(mask[u]&(1ULL<<c)))return u;
        lc[u]=rem(lc[u],c);
        rc[u]=rem(rc[u],c);
        if(treap[u]==c)
        {
                int ret;
                merge(ret,lc[u],rc[u]);
                return ret;
        }
        pull(u);
        return u;
}
void print(int u)
{
        if(!u)return;
        print(lc[u]);
        cout<<remap(treap[u]);
        print(rc[u]);
}
void solve()
{
        cin>>n>>m>>s;
        for(int i=0;i<n;i++)
        {
                int nw=make(get(s[i]));
                merge(root,root,nw);
        }
        while(m--)
        {
                int l,r;
                char c;
                cin>>l>>r>>c;
                int gc=get(c);
                int x,y,z;
                split(root,r,x,y);
                split(x,l-1,x,z);
                z=rem(z,gc);
                merge(root,x,z);
                merge(root,root,y);
        }
        print(root);
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
