// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
const int N=105;
int64_t a[N][N];
int n,m;
void solve()
{
        cin>>n>>m;
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)
        {
                cin>>a[i][j];
                if((i&1)&&((j^a[i][j])&1))a[i][j]++;
                else if((!(i&1))&&(!((j^a[i][j])&1)))a[i][j]++;
        }
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)cout<<a[i][j]<<" \n"[j==m-1];
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
