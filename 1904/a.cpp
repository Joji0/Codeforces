#include <bits/stdc++.h>
using namespace std;
int a,b,xk,yk,xq,yq,ans=0;
void solve() 
{
        ans=0;
        cin>>a>>b>>xk>>yk>>xq>>yq;
        int dx[8]={b,-b,a,a,b,-b,-a,-a},dy[8]={a,a,b,-b,-a,-a,b,-b};
        set<array<int,4>> st;
        for(int i=0;i<8;i++)
        {
                int nx=xk+dx[i],ny=yk+dy[i];
                for(int j=0;j<8;j++)
                {
                        int nxx=nx+dx[j],nyy=ny+dy[j];
                        if(st.contains({nx,ny,nxx,nyy})||st.contains({nxx,nyy,nx,ny}))continue;
                        st.insert({nx,ny,nxx,nyy});
                        if(nxx==xq&&nyy==yq)ans++;
                }
        }
        cout<<ans<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin >> tc;
        while(tc--)solve();
        return 0;
}
