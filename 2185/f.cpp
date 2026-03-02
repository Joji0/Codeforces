#include <bits/stdc++.h>
using namespace std;
int n,q,a[1<<19],b,c,t[1<<21];
void pull(int v)
{
        t[v]=t[v<<1]^t[v<<1|1];
}
void build(int v,int tl,int tr) 
{
        if(tl==tr) 
        {
                t[v]=a[tl];
        }
        else 
        {
                int tm=(tl+tr)>>1;
                build(v<<1,tl,tm);
                build(v<<1|1,tm+1,tr);
                pull(v);
        }
}
void upd(int v,int tl,int tr,int pos,int nn)
{
        if(tl==tr)
        {
                t[v]=nn;
        }
        else 
        {
                int tm=(tl+tr)>>1;
                if(pos<=tm) upd(v<<1,tl,tm,pos,nn);        
                else upd(v<<1|1,tm+1,tr,pos,nn);
                pull(v);
        }
}
int qry(int v,int tl,int tr, int pos) 
{
        if(tl==tr)return 0;
        int tm=(tl+tr)>>1;
        if(pos<=tm)
        {
                if(t[v<<1]<t[v<<1|1]) 
                {
                        return tr-tm+qry(v<<1,tl,tm,pos);
                }
                else 
                {
                        return qry(v<<1,tl,tm,pos);
                }
        }
        else 
        {
                if(t[v<<1]>=t[v<<1|1]) 
                {
                        return tm-tl+1+qry(v<<1|1,tm+1,tr,pos);
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
        fill(a,a+(1<<n),0),fill(t,t+(1<<n),0);
        for(int i=0;i<1<<n;i++)cin>>a[i];
        build(1,0,(1<<n)-1);
        while(q--)
        {
                cin>>b>>c;
                b--;
                upd(1,0,(1<<n)-1,b,c);
                cout<<qry(1,0,(1<<n)-1,b)<<'\n';
                upd(1,0,(1<<n)-1,b,a[b]);
        }
}
int main() 
{
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        int t=1;
        cin >> t;
        while(t--)solve();
        return 0;
}
