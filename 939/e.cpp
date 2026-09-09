#include <bits/stdc++.h>
using namespace std;
int q;
void solve()
{
        cin>>q;
        int64_t mx=-1;
        vector<int64_t>a,pref;
        while(q--)
        {
                int t;cin>>t;
                if(t==1)
                {
                        int64_t x;cin>>x;
                        mx=max(mx,x);
                        a.push_back(x);
                        if(pref.empty())pref.push_back(x);
                        else pref.push_back(pref.back()+x);
                }
                else
                {
                        if((int)a.size()<=1)
                        {
                                cout<<"0\n";
                        }
                        else if((int)a.size()==2)
                        {
                                double ans=(double)mx-((double)mx+a[0])/2.0;
                                cout<<fixed<<setprecision(10)<<ans<<'\n';
                        }
                        else
                        {
                                double mean=1LL<<60;
                                int l=0,r=(int)a.size()-2;
                                while(r-l>=3)
                                {
                                        int mda=l+(r-l)/3,mdb=r-(r-l)/3;
                                        double lft=((double)pref[mda]+mx)/(mda+2),rgt=((double)pref[mdb]+mx)/(mdb+2);
                                        if(lft<=rgt)r=mdb;
                                        else l=mda;
                                }
                                for(int i=l;i<=r;i++)
                                {
                                        mean=min(mean,((double)pref[i]+mx)/(i+2));
                                }
                                cout<<fixed<<setprecision(10)<<mx-mean<<'\n';
                        }
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
