// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
const int N=1005;
int n,k;
array<int,2>a[N];
void solve()
{
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
                cin>>a[i][0];
                a[i][1]=i+1;
        }
        sort(a,a+n,greater<>());
        int mn=100;
        vector<int>ans;
        for(int i=0;i<k;i++)
        {
                mn=min(mn,a[i][0]);
                ans.push_back(a[i][1]);
        }
        cout<<mn<<'\n';
        for(int i=0;i<k;i++)cout<<ans[i]<<" \n"[i==k-1];
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
