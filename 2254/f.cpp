// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int n,a[N],b[N];
void solve()
{
        cin>>n;
        int fa=0,fb=0;
        for(int i=0;i<n;i++)
        {
                cin>>a[i];
                fa^=a[i];
        }
        for(int i=0;i<n;i++)
        {
                cin>>b[i];
                fb^=b[i];
        }
        vector<int>ra={fa},rb={fb};
        for(int i=0;i<n;i++)ra.push_back(fa^a[i]),rb.push_back(fb^b[i]);
        sort(ra.begin(),ra.end()),sort(rb.begin(),rb.end());
        cout<<(ra==rb?"YES":"NO")<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
