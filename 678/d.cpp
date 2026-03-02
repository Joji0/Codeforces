#include <bits/stdc++.h>
#include <atcoder/modint>
#include "ds/matrix.hpp"
using namespace std;
using Mint=atcoder::modint1000000007;
int64_t a,b,n,x;
void solve() 
{
        cin>>a>>b>>n>>x;
        vector<vector<Mint>>t={{a,b},{0,1}},base={{x},{1}};
        Matrix<Mint>mat(t);
        Matrix<Mint>ans=mat.pow(n)*base;
        cout<<ans[0][0].val()<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin >> tc;
        while(tc--)solve();
        return 0;
}
