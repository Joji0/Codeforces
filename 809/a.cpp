#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
int n;
using Mint=atcoder::modint1000000007;
void solve() 
{
        cin>>n;
        vector<int>a(n);
        for(int&x:a)cin>>x;
        sort(a.begin(),a.end());
        vector<Mint>A(n);
        for(int i=0;i<n;i++)A[i]=Mint(a[i]);
        Mint ans=0;
        for(int i=0;i<n;i++)
        {
                ans-=A[i]*Mint(2).pow(n-i-1);
                ans+=A[i]*Mint(2).pow(i);
        }
        cout<<ans.val()<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin >> tc;
        while(tc--)solve();
        return 0;
}
