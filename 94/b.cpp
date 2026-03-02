#include <bits/stdc++.h>
using namespace std;
int m,mat[5][5],cnt=0;
void solve() 
{
        cin>>m;
        for(int i=0;i<m;i++)
        {
                int u,v;cin>>u>>v;u--,v--;mat[u][v]=1,mat[v][u]=1;
        }
        for(int i=0;i<5;i++)
        {
                for(int j=i+1;j<5;j++)
                {
                        for(int k=j+1;k<5;k++)
                        {
                                if(mat[i][j]&&mat[j][k]&&mat[k][i])
                                {
                                        cout<<"WIN\n";
                                        return;
                                }
                                if(!mat[i][j]&&!mat[j][k]&&!mat[k][i])
                                {
                                        cout<<"WIN\n";
                                        return;
                                }
                        }
                }
        }
        cout<<"FAIL\n";
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin >> tc;
        while(tc--)solve();
        return 0;
}
