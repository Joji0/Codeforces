#include <bits/stdc++.h>
using namespace std;
int n,a[1<<20];
void solve() 
{
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        int ans=0,prv=0;
        set<int>st;
        for(int i=0;i<n;i++)
        {
                if(st.count(a[i]))st.erase(a[i]);
                if(st.empty())
                {
                        ans++;
                        for(int j=prv;j<=i;j++)st.insert(a[j]);
                        prv=i;
                }
        }
        if(st.empty())ans++;
        cout<<ans<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
