#include <bits/stdc++.h>
using namespace std;
int n,m,a[1<<17],step[1<<17],nxt[1<<17],last[1<<17],bsiz;
void rebuild(int bln)
{
        int l=bln*bsiz,r=min(n-1,l+bsiz-1);
        for(int i=r;i>=l;i--)
        {
                int targ=i+a[i];
                if(targ>r)
                {
                        step[i]=1;
                        nxt[i]=targ;
                        last[i]=i;
                }
                else
                {
                        step[i]=step[targ]+1;
                        nxt[i]=nxt[targ];
                        last[i]=last[targ];
                }
        }
}
void solve()
{
        cin>>n>>m;
        for(int i=0;i<n;i++)cin>>a[i];
        bsiz=max(1,(int)sqrt(n));
        int bn=(n+bsiz-1)/bsiz;
        for(int i=0;i<bn;i++)
        {
                 rebuild(i);
        }
        while(m--)
        {
                int t;cin>>t;
                if(!t)
                {
                        int pos,nval;cin>>pos>>nval;pos--;
                        a[pos]=nval;
                        rebuild(pos/bsiz);
                }
                else
                {
                        int pos;cin>>pos;pos--;
                        int ans=0,lst=pos;
                        while(pos<n)
                        {
                                ans+=step[pos];
                                lst=last[pos];
                                pos=nxt[pos];
                        }
                        cout<<lst+1<<" "<<ans<<'\n';
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
