#include <bits/stdc++.h>
using namespace std;
int n;
int64_t a[1<<10];
void solve() 
{
        cin>>n;
        set<int64_t>st;
        for(int i=0;i<n;i++){cin>>a[i];st.insert(a[i]%2);}
        if((int)st.size()==2)
        {
                cout<<2<<'\n';
                return;
        }
        for(int i=0;i<=60;i++)
        {
                st.clear();
                for(int j=0;j<n;j++)st.insert(a[j]%(1LL<<i));
                if((int)st.size()==2)
                {
                        cout<<(1LL<<i)<<'\n';
                        return;
                }
        }
        assert(false);
}
int main() {
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
