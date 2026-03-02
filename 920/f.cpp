#include <bits/stdc++.h>
using namespace std;
int n,m,a[1<<20],D[1<<20],t,l,r;
struct Node 
{
        int64_t s; int mx;      
};
Node seg[4<<20];
void merge(int v)
{
        seg[v].s=seg[v<<1].s+seg[v<<1|1].s;
        seg[v].mx=max(seg[v<<1].mx,seg[v<<1|1].mx);
}
void build(int v,int tl,int tr) 
{
        if(tl==tr) seg[v]={a[tl],a[tl]};  
        else 
        {
                int tm=(tl+tr)>>1;
                build(v<<1,tl,tm), build(v<<1|1,tm+1,tr);
                merge(v);
        }
}
void upd(int v,int tl, int tr,int l,int r)
{ 
        if(seg[v].mx<=2)return;
        if(tl==tr)a[tl]=D[a[tl]],seg[v]={a[tl],a[tl]};
        else 
        {
                int tm=(tl+tr)>>1;
                if(l<=tm)upd(v<<1,tl,tm,l,r);
                if(r>tm)upd(v<<1|1,tm+1,tr,l,r);
                merge(v);
        }
}
int64_t qry(int v,int tl, int tr,int l,int r) 
{
        if(l>r)return 0;
        if(l==tl&&r==tr)return seg[v].s;
        int tm=(tl+tr)>>1;
        return qry(v<<1,tl,tm,l,min(r,tm))+qry(v<<1|1,tm+1,tr,max(l,tm+1),r);
}
void solve() 
{
        for(int i=1;i<1<<20;i++)
                for(int j=i;j<1<<20;j+=i)
                        D[j]++;
        cin>>n>>m;
        for(int i=0;i<n;i++)cin>>a[i];
        build(1,0,n-1);
        while(m--)
        {
                cin>>t>>l>>r;
                l--,r--;
                if(t==1) upd(1,0,n-1,l,r);
                else cout<<qry(1,0,n-1,l,r)<<'\n';
        }
}
int main() 
{
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        int t=1;
        // cin >> t;
        while(t--)solve();
        return 0;
}
