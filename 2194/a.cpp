#include <bits/stdc++.h>
using namespace std;
int n,w;
void solve() 
{
        cin>>n>>w;
        cout<<n-n/w<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin >> tc;
        while(tc--)solve();
        return 0;
}
