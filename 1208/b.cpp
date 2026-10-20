#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n,a[2005],ans;
void solve()
{
        cin>>n;
        for(int i=1;i<=n;i++)
                cin>>a[i];
        ans=n;
        for(int l=1;l<=n;l++)
        {
                set<int>st;
                int ok=1;
                for(int i=1;i<l;i++)
                {
                        if(st.contains(a[i]))
                        {
                                ok=0;
                                break;
                        }
                        st.insert(a[i]);
                }
                if(!ok)break;
                int r=n;
                while(r>=l)
                {
                        if(st.contains(a[r]))break;
                        st.insert(a[r]);
                        r--;
                }
                ans=min(ans,r-l+1);
        }
        assert(ans<n);
        cout<<ans<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
