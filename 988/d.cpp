#include <bits/stdc++.h>
using namespace std;
int n;
void solve()
{
        cin>>n;
        vector<int64_t>x(n);
        set<int64_t>st;
        for(int i=0;i<n;i++)
        {
                cin>>x[i];
                st.insert(x[i]);
        }
        vector<int64_t>ans={x[0]};
        for(int i=0;i<n;i++)
        {
                for(int pw=0;pw<35;pw++)
                {
                        int64_t d=1LL<<pw;
                        bool ok1=st.contains(x[i]+d),ok2=st.contains(x[i]+2*d);
                        if(ok1&&ok2)
                        {
                                cout<<3<<'\n';
                                cout<<x[i]<<" "<<x[i]+d<<" "<<x[i]+2*d<<'\n';
                                return;
                        }
                        if(ok1&&(int)ans.size()<2)ans={x[i],x[i]+d};
                }
        }
        cout<<(int)ans.size()<<'\n';
        for(int i=0;i<(int)ans.size();i++)cout<<ans[i]<<" ";
        cout<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
