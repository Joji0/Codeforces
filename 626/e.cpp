#include <bits/stdc++.h>
using namespace std;
#define double long double
const int N=200005;
int n;
int64_t x[N],pref[N],suff[N];
void solve()
{
        cin>>n;
        for(int i=1;i<=n;i++)cin>>x[i];
        sort(x,x+n+1);
        for(int i=1;i<=n;i++)pref[i]=pref[i-1]+x[i];
        for(int i=n;i>=1;i--)suff[i]=suff[i+1]+x[i];
        vector<int64_t>ans={x[1]};
        double mx=0;
        int at=-1,gtk=-1;
        for(int i=1;i<=n;i++)
        {
                int64_t med=x[i];
                int l=1,r=min(i-1,n-i),tk=-1;
                if(l>r)continue;
                while(r-l>=3)
                {
                        int mda=l+(r-l)/3,mdb=r-(r-l)/3;
                        double mean1=((double)x[i]+pref[i-1]-pref[i-mda-1]+suff[n-mda+1])/(2*mda+1);
                        double mean2=((double)x[i]+pref[i-1]-pref[i-mdb-1]+suff[n-mdb+1])/(2*mdb+1);
                        if(mean1>=mean2)r=mdb;
                        else l=mda;
                }
                for(int j=l;j<=r;j++)
                {
                        if(mx<((double)x[i]+pref[i-1]-pref[i-j-1]+suff[n-j+1])/(2*j+1)-med)
                        {
                                tk=j;
                                mx=((double)x[i]+pref[i-1]-pref[i-j-1]+suff[n-j+1])/(2*j+1)-med;
                        }
                }
                if(tk!=-1)
                {
                        gtk=tk;
                        at=i;
                }
        }
        if(at!=-1)
        {
                ans.clear();
                for(int j=at-gtk;j<=at-1;j++)ans.push_back(x[j]);
                ans.push_back(x[at]);
                for(int j=n;j>n-gtk;j--)ans.push_back(x[j]);
        }
        cout<<(int)ans.size()<<'\n';
        for(int i=0;i<(int)ans.size();i++)cout<<ans[i]<<" \n"[i==(int)ans.size()-1];
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
