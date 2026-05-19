#include <bits/stdc++.h>
using namespace std;
int n;
int64_t x;
array<int64_t,2>bl[1<<8];
void solve() 
{
        cin>>n>>x;
        bool ok1=false,ok2=false;
        int64_t bst=0,mx=0;
        for(int i=0;i<n;i++)
        {
                for(int j=0;j<2;j++)
                {
                        cin>>bl[i][j];
                }
                ok1|=(bl[i][0]-bl[i][1]>0);
                ok2|=(bl[i][0]>=x);
                bst=max(bst,bl[i][0]-bl[i][1]);
                mx=max(mx,bl[i][0]);
        }
        if(!ok1&&!ok2)
        {
                cout<<"-1\n";
                return;
        }
        if(ok2)
        {
                cout<<"1\n";
                return;
        }
        int64_t nd=(x-mx+bst-1)/bst;
        cout<<nd+bool(nd*bst!=0)<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
