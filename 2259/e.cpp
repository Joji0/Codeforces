#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define inf 0x3f3f3f3f
int n,b[200005],ok,prv[200005],nxt[200005],d[200005];
string ans;
void solve()
{
        cin>>n;
        ok=1;
        ans=string(n+1,'#');
        for(int i=0;i<=n+2;i++)
                prv[i]=-1,nxt[i]=-1,d[i]=0;
        for(int i=1;i<=n;i++)
        {
                cin>>b[i];
                if(b[i]!=-1)
                {
                        int l=max(1,i-b[i]+1),r=min(n,i+b[i]-1);
                        if(l<=r)
                                d[l]++,
                                d[r+1]--;
                }
        }
        int c=0;
        for(int i=1;i<=n;i++)
        {
                c+=d[i];
                if(c==0)
                        ans[i]='1';
                else
                        ans[i]='0';
        }
        for(int i=1;i<=n;i++)
        {
                if(!b[i])
                {
                        ok&=ans[i]=='1';
                }
                else if(b[i]>0)
                {
                        ok&=(ans[i]=='0');
                        int c=0;
                        if(i+b[i]<=n)
                                c|=(ans[i+b[i]]=='1');
                        if(i-b[i]>0)
                                c|=(ans[i-b[i]]=='1');
                        ok&=(c&&((i+b[i]<=n)||(i-b[i]>0)));
                }
        }
        for(int i=1;i<=n;i++)
                if(ans[i]=='1')
                        prv[i]=i;
                else
                        prv[i]=prv[i-1];
        for(int i=n;i>=1;i--)
                if(ans[i]=='1')
                        nxt[i]=i;
                else
                        nxt[i]=nxt[i+1];
        for(int i=1;i<=n;i++)
        {
                if(b[i]==-1)continue;
                int mn=inf;
                if(nxt[i]!=-1)
                        mn=min(mn,nxt[i]-i);
                if(prv[i]!=-1)
                        mn=min(mn,i-prv[i]);
                ok&=mn==b[i];
        }
        int cnt=0;
        for(int i=1;i<=n;i++)
                if(ans[i]=='1')
                        cnt++;
        if(!cnt)
                ans[1]='1';
        if(!ok)
                cout<<"-1\n";
        else
        {
                for(int i=1;i<=n;i++)
                        cout<<ans[i];
                cout<<'\n';
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
