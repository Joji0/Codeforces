#include <bits/stdc++.h>
using namespace std;
int n,a[100005],lz[4*100005],q,ty,l,r,g;
string s;
struct Node
{
        int f,s;
};
Node t[4*100005];
void pull(int v)
{
        t[v].f=t[v<<1].f^t[v<<1|1].f;
        t[v].s=t[v<<1].s^t[v<<1|1].s;
}
void build(int v, int tl, int tr)
{
        lz[v]=0;
        if(tl==tr)t[v].f=(s[tl]-'0'?a[tl]:0),t[v].s=(s[tl]-'0'?0:a[tl]);
        else
        {
                int tm=(tl+tr)>>1;
                build(v<<1,tl,tm),build(v<<1|1,tm+1,tr);
                pull(v);
        }
}
void push(int v)
{
        if(lz[v])
        {
                swap(t[v<<1].f,t[v<<1].s),swap(t[v<<1|1].f,t[v<<1|1].s);
                lz[v<<1]^=1,lz[v<<1|1]^=1;
                lz[v]=0;
        }
}
void upd(int v, int tl, int tr, int l, int r)
{
        if(l>r)return;
        if(l==tl&&r==tr)
        {
                swap(t[v].f,t[v].s),lz[v]^=1;
        }
        else
        {
                push(v);
                int tm=(tl+tr)>>1;
                upd(v<<1,tl,tm,l,min(r,tm)),upd(v<<1|1,tm+1,tr,max(l,tm+1),r);
                pull(v);
        }
}
void solve() 
{
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        cin>>s>>q;
        build(1,0,n-1);
        while(q--)
        {
                cin>>ty;
                if(ty==1)
                {
                        cin>>l>>r;
                        upd(1,0,n-1,l-1,r-1);
                }
                else
                {
                        cin>>g;
                        if(g)cout<<t[1].f<<" ";
                        else cout<<t[1].s<<" ";
                }
        }
        cout<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin >> tc;
        while(tc--)solve();
        return 0;
}
