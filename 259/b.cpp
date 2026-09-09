// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
int a[3][3];
void solve()
{
        for(int i=0;i<3;i++)for(int j=0;j<3;j++)cin>>a[i][j];
        a[1][1]=(a[0][1]+a[2][1])>>1;
        int tot=0;
        for(int i=0;i<3;i++)tot+=a[i][1];
        a[0][0]=tot-(a[0][1]+a[0][2]);
        a[2][2]=tot-(a[2][1]+a[2][0]);
        for(int i=0;i<3;i++)for(int j=0;j<3;j++)cout<<a[i][j]<<" \n"[j==2];
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
