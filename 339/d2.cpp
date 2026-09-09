#include <bits/stdc++.h>
using namespace std;
const int FAVNUM=(1<<17)+67;
int a[FAVNUM],t[4*FAVNUM],n,m;
void build(int v, int tl, int tr, int lvl)
{
        if(tl==tr)t[v]=a[tl];
        else
        {
                int tm=(tl+tr)>>1;
                build(v<<1,tl,tm,lvl-1);
                build((v<<1|1),tm+1,tr,lvl-1);
                if(lvl&1)
                        t[v]=t[v<<1]|t[v<<1|1];
                else
                        t[v]=t[v<<1]^t[v<<1|1];
        }
}
void upd(int v, int tl, int tr, int pos, int nv, int lvl)
{
        if(tl==tr)t[v]=nv;
        else
        {
                int tm=(tl+tr)>>1;
                if(pos<=tm)upd(v<<1,tl,tm,pos,nv,lvl-1);
                else upd((v<<1|1),tm+1,tr,pos,nv,lvl-1);
                if(lvl&1)
                        t[v]=t[v<<1]|t[v<<1|1];
                else
                        t[v]=t[v<<1]^t[v<<1|1];
        }
}
void solve()
{
        cin>>n>>m;
        for(int i=0;i<(1<<n);i++)cin>>a[i];
        build(1,0,(1<<n)-1,n);
        while(m--)
        {
                int p,b;cin>>p>>b;p--;
                upd(1,0,(1<<n)-1,p,b,n);
                cout<<t[1]<<'\n';
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
