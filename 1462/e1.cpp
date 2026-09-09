#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m=3,k=2;
int64_t a[N],C[N][3];
void solve()
{
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a,a+n);
        int64_t ans=0;
        for(int i=0;i<n;i++)
        {
                auto it=upper_bound(a,a+n,a[i]+k);
                int avail=(it-a)-i;
                ans+=C[avail-1][m-1];
        }
        cout<<ans<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        C[1][0]=1,C[1][1]=1,C[1][2]=0;
        for(int i=2;i<N;i++)
        {
                C[i][0]=1;
                for(int j=1;j<=2;j++)C[i][j]=C[i-1][j]+C[i-1][j-1];
        }
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}

