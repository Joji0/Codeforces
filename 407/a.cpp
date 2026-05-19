#include <bits/stdc++.h>
using namespace std;
int a,b;
bool ok(int x, int y, int xx, int yy)
{
        if(x==xx||!x||!xx)return false;
        if(y==yy||!y||!yy)return false;
        return ((xx-x)*(xx-x)+(yy-y)*(yy-y)==a*a+b*b);
}
void solve() 
{
        cin>>a>>b;
        int nda=a*a,ndb=b*b;
        vector<array<int,2>>pta,ptb;
        for(int i=1;i<=1000;i++)
        {
                for(int j=1;j<=1000;j++)
                {
                        if(i*i+j*j==nda)
                        {
                                pta.push_back({i,j});
                                pta.push_back({-i,j});
                                pta.push_back({i,-j});
                                pta.push_back({-i,-j});
                                pta.push_back({j,i});
                                pta.push_back({-j,i});
                                pta.push_back({j,-i});
                                pta.push_back({-j,-i});
                        }
                }
        }
        for(int i=1;i<=1000;i++)
        {
                for(int j=1;j<=1000;j++)
                {
                        if(i*i+j*j==ndb)
                        {
                                ptb.push_back({i,j});
                                ptb.push_back({-i,j});
                                ptb.push_back({i,-j});
                                ptb.push_back({-i,-j});
                                ptb.push_back({j,i});
                                ptb.push_back({-j,i});
                                ptb.push_back({j,-i});
                                ptb.push_back({-j,-i});
                        }
                }
        }
        for(auto[x,y]:pta)
        {
                for(auto[xx,yy]:ptb)
                {
                        if(ok(x,y,xx,yy))
                        {
                                cout<<"YES\n";
                                cout<<"0 0\n";
                                cout<<x<<" "<<y<<'\n';
                                cout<<xx<<" "<<yy<<'\n';
                                return;
                        }
                }
        }
        cout<<"NO\n";
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
