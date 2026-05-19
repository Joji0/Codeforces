#include <bits/stdc++.h>
using namespace std;
int n,k;
vector<int>a[1<<6];
set<int>un;
void solve() 
{
        un.clear();
        cin>>n;
        for(int i=0;i<n;i++)a[i].clear();
        for(int i=0;i<n;i++)
        {
                cin>>k;
                for(int j=0;j<k;j++)
                {
                        int x;cin>>x;
                        a[i].push_back(x);
                        un.insert(x);
                }
        }
        int ans=0,mx=(int)un.size();
        for(int i=1;i<=50;i++)
        {
                set<int>st;
                bool ok;
                for(int j=0;j<n;j++)
                {
                        ok=true;
                        for(int x:a[j])
                        {
                                ok&=(x!=i);
                        }
                        if(ok)
                        {
                                for(int x:a[j])st.insert(x);
                        }
                }
                if((int)st.size()!=mx)ans=max(ans,(int)st.size());
        }
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
