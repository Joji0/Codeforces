#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll tr[400005];
int n,m,a[200005],lg,l;
// iterative segtree
void build() {
        for(int i=0;i<1<<n;i++)
                tr[(1<<n)+i]=a[i];
        l=1;
        for(int i=1<<(n-1);i;i>>=1,l^=1)
                for(int j=0;j<i<<1;j++)
                        if(l)
                                tr[j]=tr[j<<1]|tr[j<<1|1];
                        else
                                tr[j]=tr[j<<1]^tr[j<<1|1];
}
void upd(int p, int v) {
        l=1;
        for(tr[p+=1<<n]=v;p>1;p>>=1,l^=1)
                if(l)
                        tr[p>>1]=tr[p]|tr[p^1];
                else
                        tr[p>>1]=tr[p]^tr[p^1];
}
void solve()
{
        cin>>n>>m;
        for(int i=0;i<1<<n;i++)
                cin>>a[i];
        build();
        while(m--)
        {
                int p,v;
                cin>>p>>v;
                upd(p-1,v);
                cout<<tr[1]<<'\n';
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
