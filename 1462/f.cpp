#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int64_t L[N],R[N];
array<int64_t,2>seg[N];
int n;
void solve()
{
        cin>>n;
        for(int i=0;i<n;i++)
        {
                cin>>L[i]>>R[i];
                seg[i]={L[i],R[i]};
        }
        sort(L,L+n),sort(R,R+n);
        int ans=n;
        for(int i=0;i<n;i++)
        {
                int l=lower_bound(R,R+n,seg[i][0])-R;
                int r=(L+n)-upper_bound(L,L+n,seg[i][1]);
                ans=min(ans,l+r);
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
