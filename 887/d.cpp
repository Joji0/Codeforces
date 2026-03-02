#include <bits/stdc++.h>
using namespace std;
int n,k;
void solve() 
{
        cin>>n;
        set<vector<int>> st;
        for(int i=0;i<n;i++)
        {
                vector<int> nw;
                cin>>k;for(int j=0;j<k;j++){int x; cin>>x; nw.push_back(x);}
                st.insert(nw);
        }
        cout<<(int)st.size()<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin >> tc;
        while(tc--)solve();
        return 0;
}
