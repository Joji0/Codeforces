#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
ll a[200005];
void solve()
{
        ll mx=-1ll<<60,mn=1ll<<60;
        cin>>n;
        for(int i=1;i<=n;i++)
                cin>>a[i],mx=max(mx,a[i]),mn=min(mn,a[i]);
        int lg=0;
        while((1ll<<lg)<mx-mn)
                lg++;
        if(1<<lg==mx-mn)
                lg++;
        cout<<lg<<'\n';
        // cerr<<"LG: "<<lg<<endl;
        if(lg<=n)
        {
                ll l=mn,r=mx;
                for(int i=0;i<lg;i++)
                {
                        if(l&1)
                        {
                                l=(l+1)>>1,
                                r=(r+1)>>1;
                                cout<<"1 ";
                        }
                        else
                        {
                                l>>=1,
                                r>>=1;
                                cout<<"0 ";
                        }
                        // if(!ok)
                        //         cout<<"1 ";
                        // else
                        //         cout<<"0 ";
                        // if(l>r)
                        //         swap(l,r);
                        // ll upv=r+1,upo=r+2;
                        // if(upv&1)
                        //         swap(upv,upo);
                        // if(l+1==r)
                        // {
                        //         ll tmpl=(upv+l)>>1;
                        //         ll tmpr=(upv+r)>>1;
                        //         if(tmpl!=tmpr)
                        //         {
                        //                 l=(upo+l)>>1;
                        //                 r=(upo+r)>>1;
                        //                 cout<<upo<<" ";
                        //         }
                        //         else
                        //                 cout<<upv<<" ";
                        //         continue;
                        // }
                        // if(l&1)
                        // {
                        //         l=(upv+l)>>1;
                        //         r=(upv+r)>>1;
                        //         cout<<upv<<" ";
                        // }
                        // else
                        // {
                        //         l=(upo+l)>>1;
                        //         r=(upo+r)>>1;
                        //         cout<<upo<<" ";
                        // }
                }
                if(lg>0)
                        cout<<'\n';
                assert(l==r);
        }
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
