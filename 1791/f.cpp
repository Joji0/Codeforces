#include <bits/stdc++.h>
using namespace std;
int n,q,t,l,r,x;
int64_t a[1<<20];
struct N {int64_t val,mx;};
N seg[1<<20];
int64_t f(int64_t x)
{
        int64_t ret=0;
        while(x>0)ret+=x%10,x/=10;
        return ret;
}
void pull(int v)
{
        seg[v]={0,max(seg[v<<1].mx,seg[v<<1|1].mx)};
}
void build(int v, int tl, int tr)
{
        if(tl==tr)seg[v]={a[tl],a[tl]};
        else
        {
                int tm=(tl+tr)>>1;
                build(v<<1,tl,tm);
                build(v<<1|1,tm+1,tr);
                pull(v);
        }
}
void upd(int v, int tl, int tr, int l, int r)
{
        if(l>r)return;    
        if(seg[v].mx<10)return;
        if(tl==tr)
        {
                seg[v].val=f(seg[v].val);
                seg[v].mx=seg[v].val;
        }
        else
        {
                int tm=(tl+tr)>>1;
                upd(v<<1,tl,tm,l,min(r,tm));
                upd(v<<1|1,tm+1,tr,max(l,tm+1),r);
                pull(v);
        }
}
int64_t qry(int v, int tl, int tr, int pos)
{
        if(tl==tr)return seg[v].val;
        else
        {
                int tm=(tl+tr)>>1;
                if(pos<=tm)
                {
                        return qry(v<<1,tl,tm,pos);
                }
                else
                {
                        return qry(v<<1|1,tm+1,tr,pos);
                }
        }
}
void solve() 
{
        cin>>n>>q;
        for(int i=0;i<n;i++)cin>>a[i];
        build(1,0,n-1);
        while(q--)
        {
                cin>>t;
                if(t==1)
                {
                        cin>>l>>r;
                        l--,r--;
                        upd(1,0,n-1,l,r);
                }
                else
                {
                        cin>>x;
                        x--;
                        cout<<qry(1,0,n-1,x)<<'\n';
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
