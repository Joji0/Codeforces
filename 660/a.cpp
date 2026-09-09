// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
const int N=1005;
int n;
int64_t a[N];
void solve()
{
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        vector<int64_t>ans;
        for(int i=0;i<n-1;i++)
        {
                if(gcd(a[i],a[i+1])!=1)
                {
                        ans.push_back(a[i]);
                        ans.push_back(1);
                }
                else ans.push_back(a[i]);
        }
        ans.push_back(a[n-1]);
        cout<<(int)ans.size()-n<<'\n';
        for(int x:ans)cout<<x<<" ";
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
